PORTNAME=	hbsdmon
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	hardenedbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	HardenedBSD infrastructure monitoring daemon

LICENSE=	BSD2CLAUSE

USES+=		uidfix
USE_HARDENING?=	safestack

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	hardenedbsd
GL_PROJECT=	hbsdmon
GL_COMMIT=	39499feab5a2a154975b4b1ce5e73a483dfb847e

LIB_DEPENDS=	libpushover.so:net/libpushover
LIB_DEPENDS+=	libucl.so:textproc/libucl
LIB_DEPENDS+=	libcurl.so:ftp/curl
LIB_DEPENDS+=	libzmq.so:net/libzmq4

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
