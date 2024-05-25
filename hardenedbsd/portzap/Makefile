PORTNAME=           portzap
PORTVERSION=        0.12.0
DISTVERSIONPREFIX=  v
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
GL_COMMIT=	48d182813cc3342c9ecc265ea756c4126a793427

BATCH=          yes
NO_ARCH=        yes
NO_BUILD=       yes

do-install:
	${MAKE} -C ${WRKSRC} PREFIX=${STAGEDIR}${PREFIX} install

.include <bsd.port.mk>
