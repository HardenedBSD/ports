--- ../nginx-upload-progress-module-68b3ab3/ngx_http_uploadprogress_module.c.orig	2021-12-24 10:53:38.000000000 -0500
+++ ../nginx-upload-progress-module-68b3ab3/ngx_http_uploadprogress_module.c	2022-07-10 22:24:32.435330000 -0400
@@ -559,12 +559,12 @@
     ngx_chain_t                      out;
     ngx_int_t                        rc, found=0, done=0, err_status=0;
     off_t                            rest=0, length=0;
-    ngx_uint_t                       len, i;
+    ngx_uint_t                       len;
     ngx_slab_pool_t                 *shpool;
     ngx_http_uploadprogress_conf_t  *upcf;
     ngx_http_uploadprogress_ctx_t   *ctx;
     ngx_http_uploadprogress_node_t  *up;
-    ngx_table_elt_t                 *expires, *cc, **ccp;
+    ngx_table_elt_t                 *expires, *cc;
     ngx_http_uploadprogress_state_t  state;
     ngx_http_uploadprogress_template_t  *t;
 
@@ -637,6 +637,7 @@
         }
 
         r->headers_out.expires = expires;
+        expires->next = NULL;
 
         expires->hash = 1;
         expires->key.len = sizeof("Expires") - 1;
@@ -646,37 +647,30 @@
     len = sizeof("Mon, 28 Sep 1970 06:00:00 GMT");
     expires->value.len = len - 1;
 
-    ccp = r->headers_out.cache_control.elts;
-    if (ccp == NULL) {
+    cc = r->headers_out.cache_control;
 
-        if (ngx_array_init(&r->headers_out.cache_control, r->pool,
-                           1, sizeof(ngx_table_elt_t *))
-            != NGX_OK) {
-            return NGX_HTTP_INTERNAL_SERVER_ERROR;
-        }
+    if (cc == NULL) {
 
-        ccp = ngx_array_push(&r->headers_out.cache_control);
-        if (ccp == NULL) {
-            return NGX_HTTP_INTERNAL_SERVER_ERROR;
-        }
-
         cc = ngx_list_push(&r->headers_out.headers);
         if (cc == NULL) {
+            expires->hash = 0;
             return NGX_HTTP_INTERNAL_SERVER_ERROR;
         }
 
+        r->headers_out.cache_control = cc;
+        cc->next = NULL;
+
         cc->hash = 1;
         cc->key.len = sizeof("Cache-Control") - 1;
         cc->key.data = (u_char *) "Cache-Control";
 
-        *ccp = cc;
-
     } else {
-        for (i = 1; i < r->headers_out.cache_control.nelts; i++) {
-            ccp[i]->hash = 0;
+        for (cc = cc->next; cc; cc = cc->next) {
+            cc->hash = 0;
         }
 
-        cc = ccp[0];
+        cc = r->headers_out.cache_control;
+        cc->next = NULL;
     }
 
     expires->value.data = (u_char *) "Thu, 01 Jan 1970 00:00:01 GMT";
