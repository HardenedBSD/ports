# Compile a port with stack zero-initialization
#
# Feature:	stack_autoinit
# Usage:	USES=stack_autoinit
# Valid ARGS:	uninitialized
#
# MAINTAINER:	shawn.webb@hardenedbsd.org

.if !defined(_INCLUDE_USES_STACK_AUTOINIT_MK)
_INCLUDE_USES_STACK_AUTOINIT_MK=    yes

.if ${stack_autoinit_ARGS:Muninitialized}
CFLAGS+=        -ftrivial-auto-var-init=uninitialized
CXXFLAGS+=      -ftrivial-auto-var-init=uninitialized
.else
CFLAGS+=        -ftrivial-auto-var-init=zero
CXXFLAGS+=      -ftrivial-auto-var-init=zero
.endif

.endif
