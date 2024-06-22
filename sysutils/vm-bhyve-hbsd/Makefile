PORTNAME=	vm-bhyve-hbsd
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	sysutils

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Management system for bhyve virtual machines
WWW=		https://git.hardenedbsd.org/shawn.webb/vm-bhyve

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/certs/ca-root-nss.crt:security/ca_root_nss

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	shawn.webb
GL_PROJECT=	vm-bhyve
GL_TAGNAME=	34e2c4c671ae34fb670272f1f26bd670cd59f6ba

CONFLICTS_INSTALL=	vm-bhyve vm-bhyve-devel

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=		BHYVE_FIRMWARE EXAMPLES GRUB2_BHYVE TMUX
BHYVE_FIRMWARE_DESC=	Required to run UEFI guests
EXAMPLES_DESC=		Install example guest templates
GRUB2_BHYVE_DESC=	Required to run Linux or any other guests that need a Grub bootloader
TMUX_DESC=		Tmux console access instead of cu/nmdm

BHYVE_FIRMWARE_RUN_DEPENDS=	bhyve-firmware>0:sysutils/bhyve-firmware
GRUB2_BHYVE_RUN_DEPENDS=	grub2-bhyve>0:sysutils/grub2-bhyve
TMUX_RUN_DEPENDS=		tmux:sysutils/tmux

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vm ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/rc.d/vm ${STAGEDIR}${PREFIX}/etc/rc.d
	(cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/lib/vm-bhyve)
	(cd ${WRKSRC}/sample-templates/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_MAN} ${WRKSRC}/vm.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
