# Compile a port with -D_FORTIFY_SOURCE=${value}
#
# Feature:	fortifysource
# Usage:	USES=fortifysource
# Valid ARGS:	none
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if !defined(_INCLUDE_USES_FORTIFYSOURCE_MK)
_INCLUDE_USES_FORTIFYSOURCE_MK=    yes

FORTIFY_SOURCE?=	2
CFLAGS+=		-D_FORTIFY_SOURCE=${FORTIFY_SOURCE}
CXXFLAGS+=		-D_FORTIFY_SOURCE=${FORTIFY_SOURCE}

.endif
