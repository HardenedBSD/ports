--- components/storage_monitor/removable_device_constants.h.orig	2021-09-14 01:51:55 UTC
+++ components/storage_monitor/removable_device_constants.h
@@ -14,7 +14,7 @@ namespace storage_monitor {
 extern const char kFSUniqueIdPrefix[];
 extern const char kVendorModelSerialPrefix[];
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 extern const char kVendorModelVolumeStoragePrefix[];
 #endif
 
