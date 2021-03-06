--- Makefile.in.orig	2020-08-28 16:04:43 UTC
+++ Makefile.in
@@ -75,7 +75,7 @@ endif
 endif
 
 .SUFFIXES:
-.SUFFIXES: $(X) .$(O) .$(A) .xml .1 .c .i .s .txt
+.SUFFIXES: $(X) .$(O) .$(A) .xml .1 .c .i .s .txt .time
 
 .PHONY: all doc rdf install clean distclean cleaner spotless install_rdf test
 .PHONY: install_doc everything install_everything strip perlreq dist tags TAGS
@@ -100,7 +100,10 @@ NDISASM = disasm/ndisasm.$(O)
 NASM    = asm/nasm.$(O)
 NDISASM = disasm/ndisasm.$(O)
 
-LIBOBJ = stdlib/snprintf.$(O) stdlib/vsnprintf.$(O) stdlib/strlcpy.$(O) \
+PROGOBJ = $(NASM) $(NDISASM)
+PROGS   = nasm$(X) ndisasm$(X)
+
+LIBOBJ_NW = stdlib/snprintf.$(O) stdlib/vsnprintf.$(O) stdlib/strlcpy.$(O) \
 	stdlib/strnlen.$(O) stdlib/strrchrnul.$(O) \
 	\
 	nasmlib/ver.$(O) \
@@ -122,7 +125,7 @@ LIBOBJ = stdlib/snprintf.$(O) stdlib/vsnprintf.$(O) st
 	x86/regs.$(O) x86/regvals.$(O) x86/regflags.$(O) x86/regdis.$(O) \
 	x86/disp8.$(O) x86/iflag.$(O) \
 	\
-	asm/error.$(O) asm/warnings.$(O) \
+	asm/error.$(O) \
 	asm/floats.$(O) \
 	asm/directiv.$(O) asm/directbl.$(O) \
 	asm/pragma.$(O) \
@@ -147,15 +150,20 @@ LIBOBJ = stdlib/snprintf.$(O) stdlib/vsnprintf.$(O) st
 	\
 	disasm/disasm.$(O) disasm/sync.$(O)
 
-ALLOBJ = $(NASM) $(NDISASM) $(LIBOBJ)
+# Warnings depend on all source files, so handle them separately
+WARNOBJ   = asm/warnings.$(O)
 
+LIBOBJ    = $(LIBOBJ_NW) $(WARNOBJ)
+ALLOBJ_NW = $(PROGOBJ) $(LIBOBJ_NW)
+ALLOBJ    = $(PROGOBJ) $(LIBOBJ)
+
 SUBDIRS  = stdlib nasmlib output asm disasm x86 common macros
 XSUBDIRS = test doc nsis rdoff
 DEPDIRS  = . include config x86 rdoff $(SUBDIRS)
 #-- End File Lists --#
 
 all: dirs
-	$(MAKE) nasm$(X) ndisasm$(X) rdf
+	$(MAKE) $(PROGS) rdf
 
 NASMLIB = libnasm.$(A)
 
@@ -271,19 +279,31 @@ warnings:
 	$(RM_F) $(WARNFILES)
 	$(MAKE) asm/warnings.time
 
-asm/warnings.time: $(ALLOBJ:.@OBJEXT@=.c)
+asm/warnings.time: $(ALLOBJ_NW:.$(O)=.c)
 	: > asm/warnings.time
-	$(MAKE) $(WARNFILES)
+	$(MAKE) $(WARNFILES:=.time)
 
-asm/warnings.c: asm/warnings.pl asm/warnings.time
+asm/warnings.c.time: asm/warnings.pl asm/warnings.time
 	$(RUNPERL) $(srcdir)/asm/warnings.pl c asm/warnings.c $(srcdir)
+	: > asm/warnings.c.time
 
-include/warnings.h: asm/warnings.pl asm/warnings.time
+asm/warnings.c: asm/warnings.c.time
+	@: Side effect
+
+include/warnings.h.time: asm/warnings.pl asm/warnings.time
 	$(RUNPERL) $(srcdir)/asm/warnings.pl h include/warnings.h $(srcdir)
+	: > include/warnings.h.time
 
-doc/warnings.src: asm/warnings.pl asm/warnings.time
+include/warnings.h: include/warnings.h.time
+	@: Side effect
+
+doc/warnings.src.time: asm/warnings.pl asm/warnings.time
 	$(RUNPERL) $(srcdir)/asm/warnings.pl doc doc/warnings.src $(srcdir)
+	: > doc/warnings.src.time
 
+doc/warnings.src : doc/warnings.src.time
+	@: Side effect
+
 # Assembler token hash
 asm/tokhash.c: x86/insns.dat x86/regs.dat asm/tokens.dat asm/tokhash.pl \
 	perllib/phash.ph
@@ -385,10 +405,9 @@ manpages: nasm.1 ndisasm.1
 # Generated manpages, also pregenerated for distribution
 manpages: nasm.1 ndisasm.1
 
-install: nasm$(X) ndisasm$(X)
+install: $(PROGS)
 	$(MKDIR_P) $(DESTDIR)$(bindir)
-	$(INSTALL_PROGRAM) nasm$(X) $(DESTDIR)$(bindir)/nasm$(X)
-	$(INSTALL_PROGRAM) ndisasm$(X) $(DESTDIR)$(bindir)/ndisasm$(X)
+	$(INSTALL_PROGRAM) $(PROGS) $(DESTDIR)$(bindir)/
 	$(MKDIR_P) $(DESTDIR)$(mandir)/man1
 	$(INSTALL_DATA) $(srcdir)/nasm.1 $(DESTDIR)$(mandir)/man1/nasm.1
 	$(INSTALL_DATA) $(srcdir)/ndisasm.1 $(DESTDIR)$(mandir)/man1/ndisasm.1
@@ -397,7 +416,7 @@ clean:
 	for d in . $(SUBDIRS) $(XSUBDIRS); do \
 		$(RM_F) "$$d"/*.$(O) "$$d"/*.s "$$d"/*.i "$$d"/*.$(A) ; \
 	done
-	$(RM_F) nasm$(X) ndisasm$(X)
+	$(RM_F) $(PROGS)
 	$(RM_F) nasm-*-installer-*.exe
 	$(RM_F) tags TAGS
 	$(RM_F) nsis/arch.nsh
@@ -412,18 +431,18 @@ distclean: clean
 	done
 	$(RM_F) test/*.$(O)
 	$(RM_RF) autom4te*.cache
-	$(RM_F) Makefile *.dep asm/warnings.time
+	$(RM_F) Makefile *.dep
 
 cleaner: clean
 	$(RM_F) $(PERLREQ) *.1 nasm.spec
 	$(MAKE) -C doc clean
-	$(RM_F) *.dep asm/warnings.time
+	$(RM_F) *.dep */*.time
 
 spotless: distclean cleaner
 	$(RM_F) doc/Makefile
 
 strip:
-	$(STRIP) --strip-unneeded nasm$(X) ndisasm$(X)
+	$(STRIP) --strip-unneeded $(PROGS)
 
 TAGS:
 	$(RM_F) TAGS
@@ -496,13 +515,13 @@ splint:
 splint:
 	splint -weak *.c
 
-test: nasm$(X)
+test: $(PROGS)
 	cd test && $(RUNPERL) performtest.pl --nasm=../nasm *.asm
 
-golden: nasm$(X)
+golden: $(PROGS)
 	cd test && $(RUNPERL) performtest.pl --golden --nasm=../nasm *.asm
 
-travis: nasm$(X)
+travis: $(PROGS)
 	$(PYTHON3) travis/nasm-t.py run
 
 #
--- Mkfiles/msvc.mak.orig	2020-08-28 16:04:43 UTC
+++ Mkfiles/msvc.mak
@@ -64,7 +64,10 @@ NDISASM = disasm\ndisasm.$(O)
 NASM    = asm\nasm.$(O)
 NDISASM = disasm\ndisasm.$(O)
 
-LIBOBJ = stdlib\snprintf.$(O) stdlib\vsnprintf.$(O) stdlib\strlcpy.$(O) \
+PROGOBJ = $(NASM) $(NDISASM)
+PROGS   = nasm$(X) ndisasm$(X)
+
+LIBOBJ_NW = stdlib\snprintf.$(O) stdlib\vsnprintf.$(O) stdlib\strlcpy.$(O) \
 	stdlib\strnlen.$(O) stdlib\strrchrnul.$(O) \
 	\
 	nasmlib\ver.$(O) \
@@ -86,7 +89,7 @@ LIBOBJ = stdlib\snprintf.$(O) stdlib\vsnprintf.$(O) st
 	x86\regs.$(O) x86\regvals.$(O) x86\regflags.$(O) x86\regdis.$(O) \
 	x86\disp8.$(O) x86\iflag.$(O) \
 	\
-	asm\error.$(O) asm\warnings.$(O) \
+	asm\error.$(O) \
 	asm\floats.$(O) \
 	asm\directiv.$(O) asm\directbl.$(O) \
 	asm\pragma.$(O) \
@@ -111,8 +114,13 @@ LIBOBJ = stdlib\snprintf.$(O) stdlib\vsnprintf.$(O) st
 	\
 	disasm\disasm.$(O) disasm\sync.$(O)
 
-ALLOBJ = $(NASM) $(NDISASM) $(LIBOBJ)
+# Warnings depend on all source files, so handle them separately
+WARNOBJ   = asm\warnings.$(O)
 
+LIBOBJ    = $(LIBOBJ_NW) $(WARNOBJ)
+ALLOBJ_NW = $(PROGOBJ) $(LIBOBJ_NW)
+ALLOBJ    = $(PROGOBJ) $(LIBOBJ)
+
 SUBDIRS  = stdlib nasmlib output asm disasm x86 common macros
 XSUBDIRS = test doc nsis rdoff
 DEPDIRS  = . include config x86 rdoff $(SUBDIRS)
@@ -230,18 +238,30 @@ warnings:
 	$(RM_F) $(WARNFILES)
 	$(MAKE) asm\warnings.time
 
-asm\warnings.time: $(ALLOBJ:.@OBJEXT@=.c)
+asm\warnings.time: $(ALLOBJ_NW:.$(O)=.c)
 	: > asm\warnings.time
-	$(MAKE) $(WARNFILES)
+	$(MAKE) $(WARNFILES:=.time)
 
-asm\warnings.c: asm\warnings.pl asm\warnings.time
+asm\warnings.c.time: asm\warnings.pl asm\warnings.time
 	$(RUNPERL) $(srcdir)\asm\warnings.pl c asm\warnings.c $(srcdir)
+	: > asm\warnings.c.time
 
-include\warnings.h: asm\warnings.pl asm\warnings.time
+asm\warnings.c: asm\warnings.c.time
+	@: Side effect
+
+include\warnings.h.time: asm\warnings.pl asm\warnings.time
 	$(RUNPERL) $(srcdir)\asm\warnings.pl h include\warnings.h $(srcdir)
+	: > include\warnings.h.time
 
-doc\warnings.src: asm\warnings.pl asm\warnings.time
+include\warnings.h: include\warnings.h.time
+	@: Side effect
+
+doc\warnings.src.time: asm\warnings.pl asm\warnings.time
 	$(RUNPERL) $(srcdir)\asm\warnings.pl doc doc\warnings.src $(srcdir)
+	: > doc\warnings.src.time
+
+doc\warnings.src : doc\warnings.src.time
+	@: Side effect
 
 # Assembler token hash
 asm\tokhash.c: x86\insns.dat x86\regs.dat asm\tokens.dat asm\tokhash.pl \
--- Mkfiles/openwcom.mak.orig	2020-08-28 16:04:44 UTC
+++ Mkfiles/openwcom.mak
@@ -53,7 +53,10 @@ NDISASM = disasm\ndisasm.$(O)
 NASM    = asm\nasm.$(O)
 NDISASM = disasm\ndisasm.$(O)
 
-LIBOBJ = stdlib\snprintf.$(O) stdlib\vsnprintf.$(O) stdlib\strlcpy.$(O) &
+PROGOBJ = $(NASM) $(NDISASM)
+PROGS   = nasm$(X) ndisasm$(X)
+
+LIBOBJ_NW = stdlib\snprintf.$(O) stdlib\vsnprintf.$(O) stdlib\strlcpy.$(O) &
 	stdlib\strnlen.$(O) stdlib\strrchrnul.$(O) &
 	&
 	nasmlib\ver.$(O) &
@@ -75,7 +78,7 @@ LIBOBJ = stdlib\snprintf.$(O) stdlib\vsnprintf.$(O) st
 	x86\regs.$(O) x86\regvals.$(O) x86\regflags.$(O) x86\regdis.$(O) &
 	x86\disp8.$(O) x86\iflag.$(O) &
 	&
-	asm\error.$(O) asm\warnings.$(O) &
+	asm\error.$(O) &
 	asm\floats.$(O) &
 	asm\directiv.$(O) asm\directbl.$(O) &
 	asm\pragma.$(O) &
@@ -100,8 +103,13 @@ LIBOBJ = stdlib\snprintf.$(O) stdlib\vsnprintf.$(O) st
 	&
 	disasm\disasm.$(O) disasm\sync.$(O)
 
-ALLOBJ = $(NASM) $(NDISASM) $(LIBOBJ)
+# Warnings depend on all source files, so handle them separately
+WARNOBJ   = asm\warnings.$(O)
 
+LIBOBJ    = $(LIBOBJ_NW) $(WARNOBJ)
+ALLOBJ_NW = $(PROGOBJ) $(LIBOBJ_NW)
+ALLOBJ    = $(PROGOBJ) $(LIBOBJ)
+
 SUBDIRS  = stdlib nasmlib output asm disasm x86 common macros
 XSUBDIRS = test doc nsis rdoff
 DEPDIRS  = . include config x86 rdoff $(SUBDIRS)
@@ -243,18 +251,30 @@ warnings:
 	$(RM_F) $(WARNFILES)
 	$(MAKE) asm\warnings.time
 
-asm\warnings.time: $(ALLOBJ:.@OBJEXT@=.c)
+asm\warnings.time: $(ALLOBJ_NW:.$(O)=.c)
 	: > asm\warnings.time
-	$(MAKE) $(WARNFILES)
+	$(MAKE) $(WARNFILES:=.time)
 
-asm\warnings.c: asm\warnings.pl asm\warnings.time
+asm\warnings.c.time: asm\warnings.pl asm\warnings.time
 	$(RUNPERL) $(srcdir)\asm\warnings.pl c asm\warnings.c $(srcdir)
+	: > asm\warnings.c.time
 
-include\warnings.h: asm\warnings.pl asm\warnings.time
+asm\warnings.c: asm\warnings.c.time
+	@: Side effect
+
+include\warnings.h.time: asm\warnings.pl asm\warnings.time
 	$(RUNPERL) $(srcdir)\asm\warnings.pl h include\warnings.h $(srcdir)
+	: > include\warnings.h.time
 
-doc\warnings.src: asm\warnings.pl asm\warnings.time
+include\warnings.h: include\warnings.h.time
+	@: Side effect
+
+doc\warnings.src.time: asm\warnings.pl asm\warnings.time
 	$(RUNPERL) $(srcdir)\asm\warnings.pl doc doc\warnings.src $(srcdir)
+	: > doc\warnings.src.time
+
+doc\warnings.src : doc\warnings.src.time
+	@: Side effect
 
 # Assembler token hash
 asm\tokhash.c: x86\insns.dat x86\regs.dat asm\tokens.dat asm\tokhash.pl &
