PORTNAME=	libpoly
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.11
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C library for manipulating polynomials

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE

LIB_DEPENDS=	libgmp.so:math/gmp

<<<<<<< HEAD
USE_HARDENING=	stackautoinit:off

USES=		cmake
=======
USES=		cmake:testing
>>>>>>> origin/freebsd/main
USE_GITHUB=	yes
GH_ACCOUNT=	SRI-CSL
USE_LDCONFIG=	yes

CMAKE_OFF=	LIBPOLY_BUILD_PYTHON_API LIBPOLY_BUILD_STATIC LIBPOLY_BUILD_STATIC_PIC

.include <bsd.port.mk>
