--- src/rust/cryptography-cffi/build.rs.orig	2023-09-12 20:23:57.059342000 +0000
+++ src/rust/cryptography-cffi/build.rs	2023-09-12 20:14:54.743501000 +0000
@@ -68,6 +68,6 @@
     // Enable abi3 mode if we're not using PyPy.
     if python_impl != "PyPy" {
         // cp37 (Python 3.7 to help our grep when we some day drop 3.7 support)
-        build.define("Py_LIMITED_API", "0x030700f0");
+        // build.define("Py_LIMITED_API", "0x030700f0");
     }
