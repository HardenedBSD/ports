--- core/vm.cpp.orig	2021-12-21 17:55:49 UTC
+++ core/vm.cpp
@@ -23,7 +23,7 @@ limitations under the License.
 
 #include "desugarer.h"
 #include "json.h"
-#include "json.hpp"
+#include "nlohmann/json.hpp"
 #include "md5.h"
 #include "parser.h"
 #include "ryml_std.hpp" // include this before any other ryml header
