PORTNAME=	bareos
PORTREVISION=	0
PKGNAMESUFFIX=	22-traymonitor

COMMENT=	Backup archiving recovery open sourced (traymonitor)

LIB_DEPENDS+=	libqwt5-qt5.so:x11-toolkits/qwt5-qt5 \
		libbareos.so:sysutils/bareos22-client

CONFLICTS=	bareos-traymonitor-qt5 bareos-traymonitor-qt6 \
		bareos20-traymonitor bareos21-traymonitor

USES=		desktop-file-utils gettext-runtime pkgconfig qt:5
USE_QT=		buildtools:build qmake:build uitools:build gui core widgets
WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
CFLAGS+=	-DMDB_DSYNC=O_SYNC -DMDB_USE_POSIX_SEM=1

MASTERDIR=	${.CURDIR}/../../sysutils/bareos22-server

CMAKE_ARGS+=		-Dtraymonitor=yes \
			-Dbuild-dird=no \
			-Dbuild-stored=no \
			-Dclient-only=yes \
			-Dnls=ON

.include "${MASTERDIR}/Makefile"
