#!/bin/sh
#
# Simple script to fetch the latest commits via the github API.  Requires
# curl and jq.  Uses unauthenticated access which is ratelimited to 60
# queries per hour.

REPOS_URL=https://api.github.com/repos/CTSRD-CHERI
MAX_DATE=1970101

tmpfile=`mktemp -t gen-Makefile.snapshot`

query_repo()
{
	branch=${2:-master}
	curl ${REPOS_URL}/$1/branches/${branch} > $tmpfile

	# Accumulate the dates of the last commits to find the snapshot date
	committime=`jq -r '.commit.commit.committer.date' $tmpfile`
	committime=${committime%%T*}
	year=${committime%%-*}
	month=${committime%-*}
	month=${month#*-}
	day=${committime##*-}
	dateint=${year}${month}${day}
	if [ $dateint -gt $MAX_DATE ]; then
		export MAX_DATE=$dateint
	fi

	SHA=`jq -r '.commit.sha' $tmpfile`
}

query_repo qemu qemu-cheri
QEMU_COMMIT=$SHA

cat <<EOF > Makefile.snapshot
# Generated file!  Do not edit!  
#
# Generated by: files/gen-Makefile.snapshot.sh.
#
SNAPDATE=	${MAX_DATE}

QEMU_COMMIT=		${QEMU_COMMIT}
EOF

rm -f $tmpfile
