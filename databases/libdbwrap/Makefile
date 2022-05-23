PORTNAME=	libdbwrap
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	swebb@blackhawknest.com
COMMENT=	Database wrapper library

LICENSE=	BSD2CLAUSE

USES=		mysql:80,client uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	BlackhawkNest
GH_PROJECT=	libdbwrap
GH_TAGNAME=	002984423a0004a2f68093e4b7cf40610898bee5

LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

MAKE_JOBS_UNSAFE=	yes

do-build:
	make -C ${WRKSRC}

.include <bsd.port.mk>
