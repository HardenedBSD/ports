PORTNAME=	scratch-game
PORTVERSION=	1.4.0.7
CATEGORIES=	games
MASTER_SITES=	https://download.scratch.mit.edu/
DISTNAME=       ${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	loic.f@hardenedbsd.org
COMMENT=	Educational programming language
WWW=		https://scratch.mit.edu/

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

USE_GNOME=	cairo glib20 pango

BUILD_DEPENDS=	pkg-config:devel/pkgconf \
		${LOCALBASE}/include/pango-1.0/pango/pangocairo.h:x11-toolkits/pango
RUN_DEPENDS=	squeak:lang/squeak

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

post-extract:
	@${REINPLACE_CMD} -i '' '/camera/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -i '' '/wedo/d' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|usr/lib|usr/local/lib|g" \
		${WRKSRC}/src/scratch
	@${REINPLACE_CMD} -e "s|cut -f5 -d|cut -f6 -d|g" \
		${WRKSRC}/src/scratch

do-install:
	${INSTALL} -m 755 ${WRKSRC}/src/scratch ${STAGEDIR}${PREFIX}/bin/scratch
	${MKDIR} -m 644 ${STAGEDIR}${PREFIX}/lib/scratch
	${INSTALL} -m 644 ${WRKSRC}/Scratch.image ${STAGEDIR}${PREFIX}/lib/scratch/Scratch.image
	${INSTALL} -m 644 ${WRKSRC}/Scratch.ini ${STAGEDIR}${PREFIX}/lib/scratch/Scratch.ini
	${INSTALL} -m 644 ${WRKSRC}/src/scratch.desktop ${STAGEDIR}${PREFIX}/share/applications/scratch.desktop
	${INSTALL} -m 644 ${WRKSRC}/src/man/scratch.1.gz ${STAGEDIR}${PREFIX}/share/man/man1/scratch.1.gz
	${MKDIR} -m 644 -p ${STAGEDIR}${PREFIX}/share/mime/packages
	${INSTALL} -m 644 ${WRKSRC}/src/scratch.xml ${STAGEDIR}${PREFIX}/share/mime/packages/scratch.xml
	${MKDIR} -m 644 -p ${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps
	${INSTALL} -m 644 ${WRKSRC}/src/icons/128x128/scratch.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/128x128/apps/scratch.png
	${CP} -rp ${WRKSRC}/Help ${WRKSRC}/locale ${WRKSRC}/Media ${WRKSRC}/Projects \
		${WRKSRC}/README ${WRKSRC}/Plugins ${STAGEDIR}${PREFIX}/lib/scratch/

.include <bsd.port.mk>
