--- utility/util_cli.c.orig	2024-10-06 18:00:36 UTC
+++ utility/util_cli.c
@@ -85,7 +85,7 @@ enum OPTS {
 	LEFT3_BUTTON,
 	LEFT3_EXIT_CODE,
 	LOAD_THEME,
-	MAX_INPUT,
+	MAX_INPUT_ARG,
 	NO_CANCEL,
 	NO_DESCRIPTIONS,
 	NO_LINES,
@@ -202,7 +202,7 @@ static struct option longopts[] = {
 	{"left3-button",      required_argument, NULL, LEFT3_BUTTON},
 	{"left3-exit-code",   required_argument, NULL, LEFT3_EXIT_CODE},
 	{"load-theme",        required_argument, NULL, LOAD_THEME},
-	{"max-input",         required_argument, NULL, MAX_INPUT},
+	{"max-input",         required_argument, NULL, MAX_INPUT_ARG},
 	{"no-cancel",         no_argument,       NULL, NO_CANCEL},
 	{"nocancel",          no_argument,       NULL, NO_CANCEL},
 	{"no-descriptions",   no_argument,       NULL, NO_DESCRIPTIONS},
@@ -546,7 +546,7 @@ parseargs(int argc, char **argv, struct bsddialog_conf
 		case LOAD_THEME:
 			opt->loadthemefile = optarg;
 			break;
-		case MAX_INPUT:
+		case MAX_INPUT_ARG:
 			opt->max_input_form = (u_int)strtoul(optarg, NULL, 10);
 			break;
 		case NO_CANCEL:
