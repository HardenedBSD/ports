# Created by: Maho Nakata <maho@FreeBSD.org>

PORTNAME=	suitesparse
PORTVERSION=	5.10.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	fortran@FreeBSD.org
COMMENT=	Set of packages for sparse matrix calculation

<<<<<<< HEAD
LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	dual

LIB_DEPENDS=	libgmp.so:math/gmp	\
		libmpfr.so:math/mpfr	\
		libmetis.so:math/metis

USE_GITHUB=	yes
GH_ACCOUNT=	DrTimothyAldenDavis
GH_PROJECT=	SuiteSparse

USES=		cmake:insource fortran gmake localbase:ldflags
USE_LDCONFIG=	yes
INSTALL_TARGET=	install # skip USES=cmake
MAKE_ENV=	BLAS="${BLASLIB}" LAPACK="${LAPACKLIB}" \
		MY_METIS_LIB="-lmetis" \
		JOBS="${MAKE_JOBS_NUMBER}" \
		CMAKE_OPTIONS='${CMAKE_ARGS}' \
		INSTALL="${STAGEDIR}${PREFIX}" \
		INSTALL_DOC="${STAGEDIR}${DOCSDIR}" \
		INSTALL_INCLUDE="${STAGEDIR}${PREFIX}/include/${PORTNAME}"
CMAKE_ARGS=	-DCMAKE_INSTALL_INCLUDEDIR:PATH="include/${PORTNAME}"	\
		-DBUILD_GRB_STATIC_LIBRARY:BOOL=ON
LDFLAGS+=	-L${WRKSRC}/lib # prevent linking with shared libs from the preinstalled older versions

USE_HARDENING=	retpoline:off

CONFLICTS_INSTALL=	mongoose plinkseq # bin/mongoose

OPTIONS_DEFINE=		DEMOS DOCS OPENMP # TBB
OPTIONS_EXCLUDE_aarch64=	OPENMP
OPTIONS_RADIO=		BLAS
OPTIONS_RADIO_BLAS=	ATLAS GOTOBLAS NETLIB OPENBLAS
OPTIONS_DEFAULT=	OPENBLAS OPENMP # TBB

ATLAS_USES=		blaslapack:atlas
GOTOBLAS_DESC=		Goto blas implementation
GOTOBLAS_USES=		blaslapack:gotoblas
NETLIB_USES=		blaslapack:netlib
OPENBLAS_USES=		blaslapack:openblas

OPENMP_MAKE_ENV_OFF=	CFOPENMP=
.if !exists(/usr/include/omp.h)
# XXX ports/199603: LLVM openmp in base doesn't support armv6, armv7 yet
OPENMP_VARS=		OPENMP=gcc-
=======
LICENSE=	GPLv2+

RUN_DEPENDS=	suitesparse-AMD>0:math/suitesparse-amd			\
		suitesparse-BTF>0:math/suitesparse-btf			\
		suitesparse-CCOLAMD>0:math/suitesparse-ccolamd		\
		suitesparse-CHOLMOD>0:math/suitesparse-cholmod		\
		suitesparse-COLAMD>0:math/suitesparse-colamd		\
		suitesparse-config>0:math/suitesparse-config		\
		suitesparse-CXSparse>0:math/suitesparse-cxsparse	\
		suitesparse-GraphBLAS>0:math/suitesparse-graphblas	\
		suitesparse-KLU>0:math/suitesparse-klu			\
		suitesparse-LDL>0:math/suitesparse-ldl			\
		suitesparse-Mongoose>0:math/suitesparse-mongoose	\
		suitesparse-RBio>0:math/suitesparse-rbio		\
		suitesparse-SLIP_LU>0:math/suitesparse-slip_lu		\
		suitesparse-SPQR>0:math/suitesparse-spqr		\
		suitesparse-UMFPACK>0:math/suitesparse-umfpack
.if !defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	suitesparse-CSparse>0:math/suitesparse-csparse
>>>>>>> origin/freebsd/main
.endif

USES=		metaport

.include <bsd.port.mk>
