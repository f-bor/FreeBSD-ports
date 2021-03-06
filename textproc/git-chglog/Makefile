# $FreeBSD$

PORTNAME=	git-chglog
DISTVERSION=	0.9.1
CATEGORIES=	textproc

MAINTAINER=	vulcan@wired.sh
COMMENT=	CHANGELOG generator implemented in Go

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	git:devel/git

USES=		go
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${GH_PROJECT}
GO_TARGET=	./cmd/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CHANGELOG.md CONTRIBUTING.md README.md
PORTEXAMPLES=	${EXAMPLES:T}

OPTIONS_DEFINE=	DOCS EXAMPLES
EXAMPLES_DESC=	Install example template format and configuration

EXAMPLES=	.chglog/CHANGELOG.tpl.md .chglog/config.yml

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
