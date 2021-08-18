# Created by: Jeremy Norris <ishmael27@home.com>

PORTNAME=	scrot
<<<<<<< HEAD
DISTVERSION=	1.5
PORTREVISION=	1
=======
DISTVERSION=	1.6
>>>>>>> origin/freebsd/main
CATEGORIES=	graphics

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SCReenshOT - command line screen capture utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	autoconf-archive>=0:devel/autoconf-archive
LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USE_GITHUB=	yes
GH_ACCOUNT=	resurrecting-open-source-projects

<<<<<<< HEAD
USE_HARDENING=	cfi safestack

CFLAGS+=	-fuse-ld=lld

USES=		autoreconf xorg
USE_CSTD=	c99
=======
USES=		autoreconf pkgconfig xorg
>>>>>>> origin/freebsd/main
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xfixes xcomposite

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
