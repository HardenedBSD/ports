PORTNAME=	hbsdmon
PORTVERSION=	1.0
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
GL_COMMIT=	de020ca598e3bb3545fb95c6520bf1657ef05b51

LIB_DEPENDS=	libpushover.so:net/libpushover
LIB_DEPENDS+=	libucl.so:textproc/libucl
LIB_DEPENDS+=	libcurl.so:ftp/curl
LIB_DEPENDS+=	libzmq.so:net/libzmq4

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
