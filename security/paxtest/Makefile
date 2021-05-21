# Created by:   loic.f@hardenedbsd.org

PORTNAME=       paxtest
PORTVERSION=	0.9.15
PORTREVISION=	0
CATEGORIES=     hardenedbsd
MAINTAINER=     loic.f@hardenedbsd.org
MASTER_SITES=	https://www.grsecurity.net/~spender/
DISTNAME=       ${PORTNAME}-${PORTVERSION}

LICENSE=        GPLv2
COMMENT=        PaX regression test suite

EXTRA_PATCHES+= ${FILESDIR}/freebsd.patch \
                ${FILESDIR}/fix-RUNDIR.patch \
                ${FILESDIR}/fix-PATH.patch

MAKE_ENV+=      make -f Makefile.FreeBSD

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/paxtest
	${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/paxtest/results
	${CP} ${WRKSRC}/paxtest ${STAGEDIR}${PREFIX}/bin/paxtest
	${FIND} ${WRKSRC} -perm 0755 -type f -exec mv {} ${STAGEDIR}${PREFIX}/lib/paxtest/ \;
	${CP} ${WRKSRC}/ChangeLog ${STAGEDIR}${PREFIX}/share/doc/paxtest/
	${CP} ${WRKSRC}/README ${STAGEDIR}${PREFIX}/share/doc/paxtest/
	${CP} ${WRKSRC}/results/HardenedBSD-11_x86_64.kiddie ${STAGEDIR}${PREFIX}/share/doc/paxtest/results

clean:
	$(MAKE) -C ${WRKSRC} -f ${WRKSRC}/Makefile.FreeBSD clean

.include <bsd.port.mk>
