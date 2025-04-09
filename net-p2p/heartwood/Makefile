PORTNAME=	heartwood
DISTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	net-p2p devel

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Metaport for Radicle, a sovereign code forge built on Git
WWW=		https://radicle.xyz/

RUN_DEPENDS=	heartwood-cli>=${DISTVERSION}_${PORTREVISION}:net-p2p/heartwood-cli
RUN_DEPENDS+=	heartwood-node>=${DISTVERSION}_${PORTREVISION}:net-p2p/heartwood-node
RUN_DEPENDS+=	heartwood-remote-helper>=${DISTVERSION}_${PORTREVISION}:net-p2p/heartwood-remote-helper
RUN_DEPENDS+=	heartwood-tools>=${DISTVERSION}_${PORTREVISION}:net-p2p/heartwood-tools

USES=		metaport

FLAVORS=	default lite
FLAVOR?=	${FLAVORS:[1]}

lite_PKGNAMESUFFIX=	-lite
default_RUN_DEPENDS+=	heartwood-httpd>=0:net-p2p/heartwood-httpd

.include <bsd.port.mk>
