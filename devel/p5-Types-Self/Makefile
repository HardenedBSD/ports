PORTNAME=	Types-Self
PORTVERSION=	0.002
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TOBYINK
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provide a "Self" type constraint, referring to the caller class or role
WWW=		https://metacpan.org/dist/Types-Self

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Role-Hooks>=0:devel/p5-Role-Hooks \
		p5-Type-Tiny>=1.012:devel/p5-Type-Tiny
TEST_DEPENDS=	p5-Role-Tiny>=0:devel/p5-Role-Tiny

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
