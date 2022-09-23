--- main.c
+++ main.c
@@ -111,7 +111,7 @@ main(int argc, char *argv[])
 		if (rc > 2)
 			fputc('\n', stderr);
 		if (outtype == OUTT_MDOC) {
-			if (fd == -1 && (bname = basename(fname)) != NULL)
+			if (fd == -1)
 				printf(".\\\" automatically generated "
 				    "with %s %s\n", progname, bname);
 			ptree_print_mdoc(tree);
