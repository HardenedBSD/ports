# Created by: Max Khon <fjoe@FreeBSD.org>

PORTNAME=	upx
PORTVERSION=	3.96
DISTVERSIONPREFIX=	v
CATEGORIES=	archivers

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ultimate Packer for eXecutables

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libucl.so:archivers/ucl

USES=		cpe gmake perl5
<<<<<<< HEAD
USE_GITHUB=	yes
USE_PERL5=	build # provides pod2man/pod2html/pod2text required for docs

USE_HARDENING=	stackautoinit:off

CPE_VENDOR=	upx_project

GH_TUPLE=	upx:upx-lzma-sdk:${DISTVERSIONPREFIX}${DISTVERSION}:lzma/src/lzma-sdk
=======
USE_PERL5=	build
>>>>>>> origin/freebsd/main

MAKE_ENV=	UPX_UCLDIR=${LOCALBASE} \
		target=freebsd

PLIST_FILES=	bin/upx \
		man/man1/upx.1.gz

CPE_VENDOR=	upx_project

GH_TUPLE=	upx:upx-lzma-sdk:v${PORTVERSION}:lzma/src/lzma-sdk
USE_GITHUB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/upx.out ${STAGEDIR}${PREFIX}/bin/upx
	${INSTALL_MAN} ${WRKSRC}/doc/upx.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
