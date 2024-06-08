PORTNAME=	hbsdmon
PORTVERSION=	1.0
PORTREVISION=	11
CATEGORIES=	hardenedbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	HardenedBSD infrastructure monitoring daemon

LICENSE=	BSD2CLAUSE

USES+=		uidfix kmod
USE_HARDENING?=	pie relro safestack

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	hardenedbsd
GL_PROJECT=	hbsdmon
GL_COMMIT=	f7285c90708cd4403003880a200c15196925ba8d

LIB_DEPENDS=	libpushover.so:net/libpushover
LIB_DEPENDS+=	libucl.so:textproc/libucl
LIB_DEPENDS+=	libcurl.so:ftp/curl
LIB_DEPENDS+=	libzmq.so:net/libzmq4
LIB_DEPENDS+=	liblattutil.so:hardenedbsd/liblattutil

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
