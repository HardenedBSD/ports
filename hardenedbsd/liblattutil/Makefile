PORTNAME=	liblattutil
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	hardenedbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Library of code

LICENSE=	BSD2CLAUSE

USES+=		uidfix

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	shawn.webb
GL_PROJECT=	liblattutil
GL_COMMIT=	85d7f121572ba4bdbd5bd673b2c87d5c4ef5cc37

LIB_DEPENDS+=	libucl.so:textproc/libucl
LIB_DEPENDS+=	libsqlite3.so:databases/sqlite3

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
