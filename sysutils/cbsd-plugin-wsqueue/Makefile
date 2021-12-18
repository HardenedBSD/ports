# $FreeBSD:$

PORTNAME=	cbsd-plugin-wsqueue
PORTVERSION=	0.1
CATEGORIES=	sysutils

MAINTAINER=	loic.f@hardenedbsd.org
COMMENT=	CBSD WEB UI

LICENSE=	BSD
RUN_DEPENDS=	cbsd:sysutils/cbsd
USES=		go

SUB_FILES=	pkg-message

PLIST_FILES=	cbsd/modules/cbsd_queue.d/cbsd-plugin-wsqueue

USE_GITHUB=	yes
GH_TAGNAME=	c93543f
GH_ACCOUNT=	cbsd
GH_PROJECT=	cbsd-plugin-wsqueue

GH_TUPLE=	go-logfmt:logfmt:v0.3.0:go_logfmt/src/github.com/go-logfmt/logfmt \
		gorilla:websocket:v1.4.0:websocket/src/github.com/gorilla/websocket

post-extract:
	${LN} -sf ${WRKSRC}/src ${WRKDIR}
	${LN} -sf ${WRKSRC} ${WRKDIR}/src/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/cbsd
	${MKDIR} ${STAGEDIR}${PREFIX}/cbsd/modules
	${MKDIR} ${STAGEDIR}${PREFIX}/cbsd/modules/cbsd_queue.d
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/cbsd/modules/cbsd_queue.d/cbsd-plugin-wsqueue

.include <bsd.port.mk>
