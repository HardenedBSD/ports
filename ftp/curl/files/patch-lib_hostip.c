diff --git lib/hostip.c lib/hostip.c
index 2b854d79d..d7d4d22ed 100644
--- lib/hostip.c
+++ lib/hostip.c
@@ -683,14 +683,6 @@ enum resolve_t Curl_resolv(struct Curl_easy *data,
   CURLcode result;
   enum resolve_t rc = CURLRESOLV_ERROR; /* default to failure */
   struct connectdata *conn = data->conn;
-  /* We should intentionally error and not resolve .onion TLDs */
-  size_t hostname_len = strlen(hostname);
-  if(hostname_len >= 7 &&
-     (curl_strequal(&hostname[hostname_len - 6], ".onion") ||
-      curl_strequal(&hostname[hostname_len - 7], ".onion."))) {
-    failf(data, "Not resolving .onion address (RFC 7686)");
-    return CURLRESOLV_ERROR;
-  }
   *entry = NULL;
 #ifndef CURL_DISABLE_DOH
   conn->bits.doh = FALSE; /* default is not */
