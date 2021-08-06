PORTNAME=	liblattutil
PORTVERSION=	1.0
CATEGORIES=	hardenedbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Library of code

LICENSE=	BSD2CLAUSE

USES+=		uidfix

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	shawn.webb
GL_PROJECT=	liblattutil
GL_COMMIT=	9d0baa1a92f4c45db7290302b4df7152176d5a18

LIB_DEPENDS+=	libucl.so:textproc/libucl
LIB_DEPENDS+=	libsqlite3.so:databases/sqlite3

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
