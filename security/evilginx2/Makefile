PORTNAME=	evilginx2
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	security net

MAINTAINER=	shawn.webb@hardenedbsd.org
COMMENT=	Man-in-the-middle attack framework used for phishing login credentials along with session cookies
WWW=		https://github.com/kgretzky/evilginx2

LICENSE=	BSD3CLAUSE

USES+=		go:modules

USE_HARDENING+=	pie:golang

USE_GITHUB=	yes
GH_ACCOUNT=	kgretzky

PLIST_FILES=	bin/evilginx2

GH_TUPLE=	\
		caddyserver:certmagic:v0.16.1:caddyserver_certmagic/vendor/github.com/caddyserver/certmagic \
		cenkalti:backoff:v3.0.0:cenkalti_backoff_v3/vendor/github.com/cenkalti/backoff/v3 \
		chzyer:readline:2972be24d48e:chzyer_readline/vendor/github.com/chzyer/readline \
		fatih:color:v1.13.0:fatih_color/vendor/github.com/fatih/color \
		fsnotify:fsnotify:v1.5.1:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go-acme:lego:v3.1.0:go_acme_lego_v3/vendor/github.com/go-acme/lego/v3 \
		go-ini:ini:v1.66.4:go_ini_ini/vendor/gopkg.in/ini.v1 \
		go-yaml:yaml:v2.4.0:go_yaml_yaml/vendor/gopkg.in/yaml.v2 \
		golang:crypto:630584e8d5aa:golang_crypto/vendor/golang.org/x/crypto \
		golang:mod:86c51ed26bb4:golang_mod/vendor/golang.org/x/mod \
		golang:net:c7608f3a8462:golang_net/vendor/golang.org/x/net \
		golang:sys:a90be440212d:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		golang:tools:v0.1.12:golang_tools/vendor/golang.org/x/tools \
		gorilla:mux:v1.7.3:gorilla_mux/vendor/github.com/gorilla/mux \
		hashicorp:hcl:v1.0.0:hashicorp_hcl/vendor/github.com/hashicorp/hcl \
		inconshreveable:go-vhost:06d84117953b:inconshreveable_go_vhost/vendor/github.com/inconshreveable/go-vhost \
		kgretzky:goproxy:7d0e0c658440:kgretzky_goproxy/vendor/github.com/elazarl/goproxy \
		klauspost:cpuid:v2.1.0:klauspost_cpuid_v2/vendor/github.com/klauspost/cpuid/v2 \
		libdns:libdns:v0.2.1:libdns_libdns/vendor/github.com/libdns/libdns \
		magiconair:properties:v1.8.6:magiconair_properties/vendor/github.com/magiconair/properties \
		mattn:go-colorable:v0.1.12:mattn_go_colorable/vendor/github.com/mattn/go-colorable \
		mattn:go-isatty:v0.0.14:mattn_go_isatty/vendor/github.com/mattn/go-isatty \
		mholt:acmez:v1.0.3:mholt_acmez/vendor/github.com/mholt/acmez \
		miekg:dns:v1.1.50:miekg_dns/vendor/github.com/miekg/dns \
		mitchellh:mapstructure:v1.4.3:mitchellh_mapstructure/vendor/github.com/mitchellh/mapstructure \
		mwitkow:go-http-dialer:378f744fb2b8:mwitkow_go_http_dialer/vendor/github.com/mwitkow/go-http-dialer \
		pelletier:go-toml:v1.9.4:pelletier_go_toml/vendor/github.com/pelletier/go-toml \
		spf13:afero:v1.8.1:spf13_afero/vendor/github.com/spf13/afero \
		spf13:cast:v1.4.1:spf13_cast/vendor/github.com/spf13/cast \
		spf13:jwalterweatherman:v1.1.0:spf13_jwalterweatherman/vendor/github.com/spf13/jwalterweatherman \
		spf13:pflag:v1.0.5:spf13_pflag/vendor/github.com/spf13/pflag \
		spf13:viper:v1.10.1:spf13_viper/vendor/github.com/spf13/viper \
		square:go-jose:v2.3.1:square_go_jose/vendor/gopkg.in/square/go-jose.v2 \
		subosito:gotenv:v1.2.0:subosito_gotenv/vendor/github.com/subosito/gotenv \
		tidwall:btree:9876f1454cf0:tidwall_btree/vendor/github.com/tidwall/btree \
		tidwall:buntdb:v1.1.0:tidwall_buntdb/vendor/github.com/tidwall/buntdb \
		tidwall:gjson:v1.14.0:tidwall_gjson/vendor/github.com/tidwall/gjson \
		tidwall:grect:ba9a043346eb:tidwall_grect/vendor/github.com/tidwall/grect \
		tidwall:match:v1.1.1:tidwall_match/vendor/github.com/tidwall/match \
		tidwall:pretty:v1.2.0:tidwall_pretty/vendor/github.com/tidwall/pretty \
		tidwall:rtree:6cd427091e0e:tidwall_rtree/vendor/github.com/tidwall/rtree \
		tidwall:tinyqueue:1e39f5511563:tidwall_tinyqueue/vendor/github.com/tidwall/tinyqueue \
		uber-go:atomic:v1.9.0:uber_go_atomic/vendor/go.uber.org/atomic \
		uber-go:multierr:v1.8.0:uber_go_multierr/vendor/go.uber.org/multierr \
		uber-go:zap:v1.21.0:uber_go_zap/vendor/go.uber.org/zap

.include <bsd.port.mk>
