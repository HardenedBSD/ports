PORTNAME=		pooler
DISTVERSIONPREFIX=	v
DISTVERSION=		1.78
PORTREVISION=		1
CATEGORIES=		biology

MAINTAINER=	ssb22@cam.ac.uk
COMMENT=	Optimise DNA sequencing primer-set combinations

LICENSE=	APACHE20
LICENSE_FILE=	${WRKDIR}/${GH_PROJECT}-${PORTVERSION}/LICENSE

<<<<<<< HEAD
USES=		compiler:openmp
=======
>>>>>>> origin/freebsd/main
USE_GITHUB=	yes

USE_HARDENING=	stackautoinit:off

GH_ACCOUNT=	ssb22
GH_PROJECT=	PrimerPooler

WRKSRC_SUBDIR=	pooler
CFLAGS+=	-fopenmp

INSTALL_TARGET=	install-strip
PLIST_FILES=	bin/pooler man/man1/pooler.1.gz share/applications/pooler.desktop

.include <bsd.port.mk>

