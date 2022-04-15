diff -ru ../harfbuzz-4.2.0.orig/src/hb-ot-layout.cc ./src/hb-ot-layout.cc
--- ../harfbuzz-4.2.0.orig/src/hb-ot-layout.cc	2022-04-15 14:23:31.703363000 -0400
+++ ./src/hb-ot-layout.cc	2022-04-15 14:23:58.997755000 -0400
@@ -2088,6 +2088,9 @@
 					 hb_tag_t                     language_tag,
 					 hb_position_t               *coord /* OUT */)
 {
+	if (font == NULL) {
+		return;
+	}
   if (hb_ot_layout_get_baseline (font,
 				 baseline_tag,
 				 direction,
