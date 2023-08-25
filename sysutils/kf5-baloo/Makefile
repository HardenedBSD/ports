PORTNAME=	baloo
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	sysutils kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 Framework for searching and managing user metadata

LIB_DEPENDS=	liblmdb.so:databases/lmdb \
		libinotify.so:devel/libinotify

USES=		cmake compiler:c++11-lib gettext kde:5 pathfix qt:5 tar:xz
USE_KDE=	config coreaddons crash dbusaddons \
		filemetadata i18n idletime kio service \
		solid \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network \
		buildtools:build qmake:build testlib:build


MPROTECT_DISABLE=	lib/libexec/baloo_file
MPROTECT_DISABLE=	lib/libexec/baloo_file_extractor
SEGVGUARD_DISABLE=	lib/libexec/baloo_file_extractor

.include <bsd.port.mk>
