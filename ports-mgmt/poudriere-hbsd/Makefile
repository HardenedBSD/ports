PORTNAME=	poudriere
DISTVERSION=	3.3.7
PORTREVISION=	1
CATEGORIES=	ports-mgmt
PKGNAMESUFFIX=	-hbsd

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Port build and test system
WWW=		https://github.com/freebsd/poudriere/wiki

LICENSE=	BSD2CLAUSE

CONFLICTS_INSTALL=	poudriere poudriere-devel

#USE_GITHUB=	yes
#GH_ACCOUNT=	hardenedbsd
#GH_PROJECT=	poudriere-hbsd
#GH_COMMIT=	bbc35d4384509ff6bf512d5209171f0c30291e0a
#GH_TAGNAME=	${GH_COMMIT}

USE_GITLAB=	yes
GL_SITE=	https://git.hardenedbsd.org
GL_ACCOUNT=	hardenedbsd
GL_PROJECT=	poudriere
GL_COMMIT=	83ccf0e5a04ff0dbf18abdf69541d3c31098a6ee

GNU_CONFIGURE=	yes
ETCDIR=		${PREFIX}/etc/poudriere.d

OPTIONS_DEFINE=	BASH DIALOG4PORTS EXAMPLES QEMU ZSH
OPTIONS_DEFAULT=BASH DIALOG4PORTS ZSH
OPTIONS_SUB=	yes

DIALOG4PORTS_DESC=	Install dialog4ports for options command
DIALOG4PORTS_RUN_DEPENDS=	dialog4ports>0:ports-mgmt/dialog4ports

QEMU_DESC=	Add qemu-user-static for non-x86 architectures
QEMU_RUN_DEPENDS=	qemu-user-static>0:emulators/qemu-user-static

.include <bsd.port.options.mk>

# rm -x support came in 10.0.  A bundled rm is used if not supported in base.
# While <10 is technically not supported in the Ports Tree, Poudriere
# detects this and it being a package build tool it should still be
# supported as a user may be installing this to build packages for upgrading
# their system to a supported release.
.if ${OSVERSION} < 1000000
PLIST_SUB+=	RM=""
.else
PLIST_SUB+=	RM="@comment "
.endif

post-patch:
	${CP} -f ${WRKSRC}/src/bin/poudriere ${WRKSRC}/poudriere
	${REINPLACE_CMD} \
	    -e "s,^\(POUDRIERE_VERSION\)=.*,\1='${PKGVERSION}'," \
	    ${WRKSRC}/poudriere
	${REINPLACE_CMD} '/.PHONY: poudriere/d' ${WRKSRC}/Makefile.*
	${REINPLACE_CMD} '/linuxelf:linux/d' \
	    ${WRKSRC}/src/share/poudriere/common.sh

post-install-BASH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/bash-completion/completions/
	${INSTALL_DATA} ${WRKSRC}/completions/bash/poudriere \
	    ${STAGEDIR}${PREFIX}/share/bash-completion/completions/

post-install-ZSH-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions/
	${INSTALL_DATA} ${WRKSRC}/completions/zsh/_poudriere \
	    ${STAGEDIR}${PREFIX}/share/zsh/site-functions/

.include <bsd.port.mk>
