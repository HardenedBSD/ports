--- common/libBuffer/include/CommonFWriteBufferFlusher.h.orig	2022-01-09 18:33:16 UTC
+++ common/libBuffer/include/CommonFWriteBufferFlusher.h
@@ -13,15 +13,19 @@
 
 #include "CommonIBufferFlusher.h"
 
+/*
 #if (defined(WIN64) || defined(_WIN64) || defined(__WIN64__)) || (defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(__APPLE__))
 #if defined(__GNUC__) && !defined(_LIBCPP_VERSION)
 #	include <tr1/unordered_map>
 #else
+*/
 #	include <unordered_map>
+/*
 #endif
 #else
 #	include <tr1/unordered_map>
 #endif
+*/
 
 #ifdef _LIBCPP_VERSION
 // If we're compiling with libc++, create a namespace alias for tr1 that points to std.
