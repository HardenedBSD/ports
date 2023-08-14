PORTNAME=	mono
PORTVERSION=	${MONO_DEFAULT}
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meta-port for the default version of the Mono framework
WWW=		https://www.mono-project.com/

RUN_DEPENDS=	mono${MONO_DEFAULT}>0:lang/mono${MONO_DEFAULT}

MPROTECT_DISABLE+=	bin/mono
MPROTECT_DISABLE+=	bin/mono-sgen
MPROTECT_DISABLE+=	bin/mono-boehm
PAGEEXEC_DISABLE+=	bin/mono
PAGEEXEC_DISABLE+=	bin/mono-sgen
PAGEEXEC_DISABLE+=	bin/mono-boehm
DISALLOW_MAP32BIT+=	bin/mono
DISALLOW_MAP32BIT+=	bin/mono-sgen
DISALLOW_MAP32BIT+= bin/mono-boehm

USES=		metaport

.include <bsd.port.mk>
