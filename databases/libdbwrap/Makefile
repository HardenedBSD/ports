PORTNAME=	libdbwrap
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	swebb@blackhawknest.com
COMMENT=	Database wrapper library

LICENSE=	BSD2CLAUSE

USES=		mysql:80,client uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	BlackhawkNest
GH_PROJECT=	libdbwrap
GH_TAGNAME=	e277e252a07463b5568662bcff8fe5780630952c

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

MAKE_JOBS_UNSAFE=	yes

do-build:
	make -C ${WRKSRC}

.include <bsd.port.mk>
