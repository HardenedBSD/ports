PORTNAME=	kernel-nodebug
PORTVERSION!=	date "+%y.%m.%d"
CATEGORIES=	hardenedbsd
PKGNAMEPREFIX=	${HARDENEDBSD_PKGNAMEPREFIX}
DISTFILES=
EXTRACT_ONLY=

MAINTAINER=	loic.f@hardenedbsd.org
COMMENT=	HardenedBSD kernel without many debug options

USES=
USE_HARDENING=	pie:off relro:off

PREFIX=/
WRKSRC?=	/usr/src
NEED_ROOT=	yes

KERNCONF=	HARDENEDBSD-NODEBUG

.if defined(_MAKE_JOBS_NUMBER)
JOBFLAG=	-j ${_MAKE_JOBS_NUMBER}
.else
JOBFLAG=	-j ${_SMP_CPUS}
.endif

.include <bsd.port.pre.mk>

do-build:
	cd ${WRKSRC} && ${SETENV} -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} KERNCONF=${KERNCONF} \
		buildkernel

do-install:
	cd ${WRKSRC} && ${SETENV} -i MAKEOBJDIRPREFIX=${WRKDIR} make ${JOBFLAG} KERNCONF=${KERNCONF} \
		DESTDIR=${STAGEDIR} \
		installkernel
	${MV} ${STAGEDIR}/boot/kernel ${STAGEDIR}/boot/kernel-nodebug
	${ECHO_MSG} "==> Generating plist..."
	(cd ${STAGEDIR}; ${FIND} ./boot/kernel-nodebug \( -type f -o -type l \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' >> ${TMPPLIST})
	(cd ${STAGEDIR}; ${FIND} ./boot/kernel-nodebug \( -type d \) \
		| ${SED} -e 's,^\./,,g' \
		| ${AWK} '{print length, $$0}' | ${SORT} -rn \
		| ${AWK} '{print $$2 }' \
		| ${XARGS} -I '{}' echo "@dir {}" >> ${TMPPLIST})

.include <bsd.port.post.mk>
