--- chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc.orig	2022-05-11 07:16:47 UTC
+++ chrome/browser/extensions/api/enterprise_reporting_private/chrome_desktop_report_request_helper.cc
@@ -23,7 +23,7 @@
 #include "base/win/registry.h"
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 #include "base/environment.h"
 #include "base/nix/xdg_util.h"
 #endif
@@ -207,7 +207,7 @@ base::FilePath GetEndpointVerificationDir() {
   bool got_path = false;
 #if defined(OS_WIN)
   got_path = base::PathService::Get(base::DIR_LOCAL_APP_DATA, &path);
-#elif defined(OS_LINUX) || defined(OS_CHROMEOS)
+#elif defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   std::unique_ptr<base::Environment> env(base::Environment::Create());
   path = base::nix::GetXDGDirectory(env.get(), base::nix::kXdgConfigHomeEnvVar,
                                     base::nix::kDotConfigDir);
@@ -218,7 +218,7 @@ base::FilePath GetEndpointVerificationDir() {
   if (!got_path)
     return path;
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   path = path.AppendASCII("google");
 #else
   path = path.AppendASCII("Google");
