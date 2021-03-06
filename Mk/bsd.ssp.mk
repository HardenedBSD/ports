# SSP Support

SSP_Include_MAINTAINER=	portmgr@FreeBSD.org

.if !defined(SSP_UNSAFE) && \
    (! ${ARCH:Mmips*})
# Overridable as a user may want to use -fstack-protector-all
SSP_CFLAGS?=	-fstack-protector-all
CFLAGS+=	${SSP_CFLAGS}
LDFLAGS+=	${SSP_CFLAGS}
.endif
