# NB: Do not delete or wrap post-install section, since we have to provide
#     READMEj and README

PORTNAME=	mxico
PORTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	https://people.freebsd.org/~maho/mxico/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rotating Object on the screen (Zalgaller polyhedra)
WWW=		https://people.freebsd.org/~maho/mxico/

LICENSE=	MIT

USES=		imake xorg
USE_XORG=	x11 xext
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} polyhedron/READMEj ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} polyhedron/README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
