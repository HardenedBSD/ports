PORTNAME=	pms
PORTVERSION=	0.42
PORTREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	riggs@FreeBSD.org
COMMENT=	ncurses-based client for the Music Player Daemon
WWW=		http://pms.sourceforge.net/

LICENSE=	GPLv3

USES=		gettext gnome ncurses pkgconfig tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_GNOME=	glib20

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/pms.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib

OPTIONS_DEFINE=	REGEX

REGEX_DESC=	Support boost regex pattern matching

REGEX_LIB_DEPENDS=	libboost_regex.so:devel/boost-libs
REGEX_CONFIGURE_ENABLE=	regex

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
