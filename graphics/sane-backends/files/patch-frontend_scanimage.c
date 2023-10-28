From 373dceaa36039977db43e5864759f3b080e92d2c Mon Sep 17 00:00:00 2001
From: Ralph Little <skelband@gmail.com>
Date: Mon, 13 Feb 2023 12:32:35 -0800
Subject: [PATCH] scanimage: more generic fix for selecting a common basename
 function.

We have been specially including libgen.h to get a version in other
platforms such as macOS and FreeBSD. However, it is dangerous to
make assumptions about which version of basename that we will get.
So this change reverts to asking for the version that modifies the
argument and creates a copy of the arg that we *can* modify.
---
 frontend/scanimage.c | 24 +++++++++++++++---------
 1 file changed, 15 insertions(+), 9 deletions(-)

diff --git a/frontend/scanimage.c b/frontend/scanimage.c
index d79d48754..2bf31fc3b 100644
--- frontend/scanimage.c
+++ frontend/scanimage.c
@@ -39,15 +39,7 @@
 #include <string.h>
 #include <unistd.h>
 #include <stdarg.h>
-
-#ifdef __FreeBSD__
-#include <libgen.h>
-#endif
-
-#if defined (__APPLE__) && defined (__MACH__)
 #include <libgen.h>     // for basename()
-#endif
-
 #include <sys/types.h>
 #include <sys/stat.h>
 
@@ -1260,7 +1252,21 @@ write_png_header (SANE_Frame format, int width, int height, int depth, int dpi,
 	  if ((is_gray_profile && color_type == PNG_COLOR_TYPE_GRAY) ||
 	      (is_rgb_profile && color_type == PNG_COLOR_TYPE_RGB))
 	    {
-	      png_set_iCCP(*png_ptr, *info_ptr, basename(icc_profile), PNG_COMPRESSION_TYPE_BASE, icc_buffer, icc_size);
+	      char *icc_profile_cp = strdup(icc_profile);
+	      if (icc_profile_cp == NULL)
+	        {
+                  fprintf(stderr, "Memory allocation failure prevented the setting of PNG ICC profile.\n");
+	        }
+	      else
+	        {
+                  png_set_iCCP (*png_ptr,
+                                *info_ptr,
+                                basename (icc_profile_cp),
+                                PNG_COMPRESSION_TYPE_BASE,
+                                icc_buffer,
+                                icc_size);
+                  free(icc_profile_cp);
+	        }
 	    }
 	  else
 	    {
-- 
GitLab

