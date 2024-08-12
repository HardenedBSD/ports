--- utils.h.orig	2023-10-09 09:18:22 UTC
+++ utils.h
@@ -8,6 +8,8 @@
 #include <string.h>
 #include <unistd.h>
 
+#include "config.h"
+
 #ifdef HAVE_SYS_TREE_H
 #include <sys/tree.h>
 #else
