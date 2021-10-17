PORTNAME=	hbsdmon
PORTVERSION=	1.0
PORTREVISION=	10
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
GL_COMMIT=	5df7f04a0afd8d25ad79e3701dcd839b80d9c1bd

LIB_DEPENDS=	libpushover.so:net/libpushover
LIB_DEPENDS+=	libucl.so:textproc/libucl
LIB_DEPENDS+=	libcurl.so:ftp/curl
LIB_DEPENDS+=	libzmq.so:net/libzmq4
LIB_DEPENDS+=	liblattutil.so:hardenedbsd/liblattutil

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
