# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	mimalloc
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	General-purpose allocator with excellent performance characteristics

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

<<<<<<< HEAD
BUILD_DEPENDS_i386=	libatomic_ops>0:devel/libatomic_ops

USE_HARDENING=	stackautoinit:off

USES=		cmake compiler:gcc-c++11-lib
=======
USES=		cmake compiler:c++17-lang
>>>>>>> origin/freebsd/main
USE_GITHUB=	yes
GH_ACCOUNT=	microsoft
USE_LDCONFIG=	yes

CMAKE_ON=	MI_INSTALL_TOPLEVEL
TEST_TARGET=	test

LDFLAGS_powerpc=	-latomic

# ci pipeline creates transient tags
PORTSCOUT=	ignore:1

post-install: # workaround for https://github.com/microsoft/mimalloc/issues/398
	@${RM} ${STAGEDIR}${PREFIX}/lib/mimalloc.o

.include <bsd.port.mk>
