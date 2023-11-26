PORTNAME=	void-zones-tools
<<<<<<< HEAD
PORTVERSION=	2.0
=======
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.2-18
DISTVERSIONSUFFIX=	-g204634a
PORTREVISION=	1
>>>>>>> internal/freebsd/main
CATEGORIES=	dns

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Prepare a list of void zones that can be readily fed into Unbound
WWW=		https://github.com/cyclaero/void-zones-tools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	ca_root_nss>0:security/ca_root_nss

USES=		compiler:c11 uidfix

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	shawn.webb
GL_PROJECT=	void-zones-tools
GL_COMMIT=	0681f44db15ed1707b9be9385a14bf4166d1ee42

SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
