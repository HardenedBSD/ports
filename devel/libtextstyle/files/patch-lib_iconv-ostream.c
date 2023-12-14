--- lib/iconv-ostream.c.orig	2023-09-18 20:50:39 UTC
+++ lib/iconv-ostream.c
@@ -252,6 +252,13 @@ is_instance_of_iconv_ostream (ostream_t stream)
 
 #else
 
+iconv_ostream_t
+iconv_ostream_create (const char *from_encoding, const char *to_encoding,
+                      ostream_t destination)
+{
+  abort ();
+}
+
 static void
 iconv_ostream__write_mem (iconv_ostream_t stream, const void *data, size_t len)
 {
@@ -259,7 +266,7 @@ static void
 }
 
 static void
-iconv_ostream__flush (iconv_ostream_t stream)
+iconv_ostream__flush (iconv_ostream_t stream, ostream_flush_scope_t scope)
 {
   abort ();
 }
