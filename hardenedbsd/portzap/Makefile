PORTNAME=           portzap
PORTVERSION=        0.8.1
DISTVERSIONPREFIX=  v
PORTREVISION=	2
CATEGORIES=         hardenedbsd

MAINTAINER=     0x1eef@protonmail.com
COMMENT=        Manages a local copy of the hardenedbsd ports tree
WWW=            https://git.hardenedbsd.org/0x1eef/portzap

LICENSE=        BSD0CLAUSE

RUN_DEPENDS=	doas:security/doas git:devel/git

USE_GITLAB=     yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=     0x1eef
GL_PROJECT=	portzap
GL_COMMIT=	d868030a1ccb9145b6b5a2d1036a11c5abb4f0f7

BATCH=          yes
NO_ARCH=        yes
NO_BUILD=       yes

do-install:
	${MAKE} -C ${WRKSRC} PREFIX=${STAGEDIR}${PREFIX} install

.include <bsd.port.mk>
