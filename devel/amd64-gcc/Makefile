# $FreeBSD$

PKGNAMEPREFIX=	amd64-
PLIST=	${.CURDIR}/pkg-plist

MASTERDIR=	${.CURDIR}/../powerpc64-gcc

BROKEN_armv6=		invalid output constraint '=a' in assembler
BROKEN_armv7=		invalid output constraint '=a' in assembler
BROKEN_mips=		configure: cannot compute suffix of object files: cannot compile
BROKEN_mips64=		configure: cannot compute suffix of object files: cannot compile

.include "${MASTERDIR}/Makefile"
