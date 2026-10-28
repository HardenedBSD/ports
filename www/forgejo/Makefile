PORTNAME=	forgejo
PORTVERSION=	17
CATEGORIES=	www

MAINTAINER=	des@FreeBSD.org
COMMENT=	Compact self-hosted Git forge
WWW=		https://forgejo.org/

RUN_DEPENDS=	forgejo${PORTVERSION}>=0:www/forgejo${PORTVERSION}

USE_HARDENING=	pie:golang relro:off retpoline:off

USES=		metaport

.include <bsd.port.mk>
