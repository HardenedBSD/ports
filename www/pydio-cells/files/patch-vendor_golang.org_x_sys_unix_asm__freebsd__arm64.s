--- vendor/golang.org/x/sys/unix/asm_freebsd_arm64.s.orig	2021-11-14 16:37:38 UTC
+++ vendor/golang.org/x/sys/unix/asm_freebsd_arm64.s
@@ -0,0 +1,29 @@
+// Copyright 2018 The Go Authors. All rights reserved.
+// Use of this source code is governed by a BSD-style
+// license that can be found in the LICENSE file.
+
+// +build !gccgo
+
+#include "textflag.h"
+
+//
+// System call support for ARM64, FreeBSD
+//
+
+// Just jump to package syscall's implementation for all these functions.
+// The runtime may know about them.
+
+TEXT	·Syscall(SB),NOSPLIT,$0-56
+	JMP	syscall·Syscall(SB)
+
+TEXT	·Syscall6(SB),NOSPLIT,$0-80
+	JMP	syscall·Syscall6(SB)
+
+TEXT	·Syscall9(SB),NOSPLIT,$0-104
+	JMP	syscall·Syscall9(SB)
+
+TEXT ·RawSyscall(SB),NOSPLIT,$0-56
+	JMP	syscall·RawSyscall(SB)
+
+TEXT	·RawSyscall6(SB),NOSPLIT,$0-80
+	JMP	syscall·RawSyscall6(SB)
