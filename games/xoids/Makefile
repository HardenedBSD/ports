PORTNAME=	xoids
PORTVERSION=	1.5
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	XCONTRIB/games

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Window Asteroids style game with full color pixmaps

NOT_FOR_ARCHS=		mips64
NOT_FOR_ARCHS_REASON=	unknown architecture

USES=		imake xorg
USE_XORG=	x11 xpm
CFLAGS+=	-fcommon

PLIST_FILES=	bin/xoids \
		share/man/man6/xoids.6.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${WRKSRC}/xoids.1x ${WRKSRC}/xoids.man

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
