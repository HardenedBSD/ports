https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=239266 reports how
clang unfortunately poisons user namespace by default (without any
special options).

Until that changes (or GCC changes) we need to avoid using vec_step
as a variable.

--- UTC
Index: gcc-9.3.0/gcc/tree-vect-loop.c
===================================================================
--- gcc-9.3.0/gcc/tree-vect-loop.c	(revision 273856)
+++ gcc-9.3.0/gcc/tree-vect-loop.c	(working copy)
@@ -55,6 +55,8 @@ along with GCC; see the file COPYING3.  If not see
 #include "vec-perm-indices.h"
 #include "tree-eh.h"
 
+#define vec_step vec_step_
+
 /* Loop Vectorization Pass.
 
    This pass tries to vectorize loops.
