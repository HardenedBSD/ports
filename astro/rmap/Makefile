PORTNAME=	rmap
PORTVERSION=	1.2
PORTREVISION=	15
CATEGORIES=	astro geography
MASTER_SITES=	http://rmap.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generates images of the Earth centered at a particular location
WWW=		https://rmap.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgd.so:graphics/gd

USES=		gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/rmap share/man/man1/rmap.1.gz %%DATADIR%%/earth.rez \
		%%DATADIR%%/rmap.colors

.include <bsd.port.mk>
