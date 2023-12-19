PORTNAME=	obpager
PORTVERSION=	1.8
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Lightweight pager for NetWM-compliant window managers
WWW=		https://obpager.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake xorg
USE_XORG=	x11 xext

<<<<<<< HEAD
USE_HARDENING=	pie:off

MAKE_ARGS=	CDEFS="${CXXFLAGS}"

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

=======
>>>>>>> internal/freebsd/main
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
