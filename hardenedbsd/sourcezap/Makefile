PORTNAME=           sourcezap
PORTVERSION=        0.1.0
DISTVERSIONPREFIX=  v
CATEGORIES=         hardenedbsd

MAINTAINER=     0x1eef@protonmail.com
COMMENT=        Manages a local copy of the hardenedbsd source tree
WWW=            https://git.hardenedbsd.org/0x1eef/sourcezap

LICENSE=        BSD0CLAUSE

RUN_DEPENDS=	doas:security/doas git:devel/git

USE_GITLAB=     yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=     0x1eef
GL_PROJECT=	sourcezap
GL_COMMIT=	436e47f5e2030a2d8bad577dcc1703fd475c8fc0

BATCH=          yes
NO_ARCH=        yes
NO_BUILD=       yes

do-install:
	${MAKE} -C ${WRKSRC} PREFIX=${STAGEDIR}${PREFIX} install

.include <bsd.port.mk>
