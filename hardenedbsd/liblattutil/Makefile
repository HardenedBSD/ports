PORTNAME=	liblattutil
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	hardenedbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Library of code

LICENSE=	BSD2CLAUSE

USES+=		uidfix

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	shawn.webb
GL_PROJECT=	liblattutil
GL_COMMIT=	c116f92d09bfa6e8291ba88c594b49754ae56ceb

LIB_DEPENDS+=	libucl.so:textproc/libucl
LIB_DEPENDS+=	libsqlite3.so:databases/sqlite3

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.mk>
