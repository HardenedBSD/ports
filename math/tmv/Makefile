PORTNAME=	tmv
DISTVERSIONPREFIX=	v
DISTVERSION=	0.75
PORTREVISION=	8
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Fast, intuitive linear algebra library for C++

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/TMV_LICENSE

<<<<<<< HEAD
USE_HARDENING=	stackautoinit:off

USES=		compiler:openmp gmake blaslapack:netlib localbase
=======
USES=		gmake blaslapack:netlib localbase
>>>>>>> origin/freebsd/main
USE_GITHUB=	yes
GH_ACCOUNT=	rmjarvis
USE_LDCONFIG=	yes

BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${BUILD_WRKSRC}
MAKEFILE=	${FILESDIR}/Makefile

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/TMV_Documentation.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
