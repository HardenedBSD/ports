PORTNAME=	libsock
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	swebb@blackhawknest.com
COMMENT=	Encrypted sockets abstraction library

LICENSE=	BSD2CLAUSE

USES=		uidfix

LIB_DEPENDS+=	libtls.so:security/libressl@libtls

USE_GITHUB=yes
GH_ACCOUNT=	BlackHawkNest
GH_PROJECT=	libsock
GH_TAGNAME=	7e627921ceee197bbf175ceafc8f7a37e7cbb938

MAKE_JOBS_UNSAFE=	yes

do-build:
	make -C ${WRKSRC}

.include <bsd.port.mk>
