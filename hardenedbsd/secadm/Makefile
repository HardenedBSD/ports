PORTNAME=	secadm
PORTVERSION=	0.5.1
DISTVERSIONPREFIX=	v
PORTREVISION?=	10
CATEGORIES=	hardenedbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	HardenedBSD Security Administration

LICENSE=	BSD2CLAUSE

USES+=		uidfix
USE_HARDENING?=	safestack

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	hardenedbsd
GL_PROJECT=	secadm
GL_COMMIT=	01112cf07c37ce306eae7134ada5d3ce29f9f2ca

.if !defined(KMOD)
LIBDIR?=	${PREFIX}/lib
MAKE_ENV+=	LIBDIR=${LIBDIR}
.endif

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

.if defined(KMOD)
MAKE_ENV+=	WITHOUT_CLI=YES
.else
MAKE_ENV+=	WITHOUT_KMOD=YES

LIB_DEPENDS=	libucl.so:textproc/libucl
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1100000
LIB_DEPENDS+=	libxo.so:devel/libxo
.endif

.endif

.include <bsd.port.post.mk>
