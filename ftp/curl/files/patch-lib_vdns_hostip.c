--- lib/vdns/hostip.c.orig	2026-09-12 19:51:55 UTC
+++ lib/vdns/hostip.c
@@ -724,15 +724,8 @@ static CURLcode hostip_resolv(struct Curl_easy *data,
   (void)allowDOH;
 #endif
 
-  /* We should intentionally error and not resolve .onion TLDs */
   hostname_len = strlen(peer->hostname);
   DEBUGASSERT(hostname_len);
-  if(hostname_len >= 7 &&
-     (curl_strequal(&peer->hostname[hostname_len - 6], ".onion") ||
-      curl_strequal(&peer->hostname[hostname_len - 7], ".onion."))) {
-    failf(data, "Not resolving .onion address (RFC 7686)");
-    goto out;
-  }
 
 #ifdef DEBUGBUILD
   CURL_TRC_DNS(data, "[%s] hostip_resolv(%s:%u)",
