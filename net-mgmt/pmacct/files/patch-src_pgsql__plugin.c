--- src/pgsql_plugin.c.orig	2021-11-05 15:03:23 UTC
+++ src/pgsql_plugin.c
@@ -611,7 +611,7 @@ void PG_cache_purge(struct db_cache *queue[], int inde
   if (sql_pqq_ptr) goto start;
 
   idata->elap_time = time(NULL)-start;
-  Log(LOG_INFO, "INFO ( %s/%s ): *** Purging cache - END (PID: %u, QN: %u/%u, ET: %lu) ***\n",
+  Log(LOG_INFO, "INFO ( %s/%s ): *** Purging cache - END (PID: %u, QN: %u/%u, ET: %zu) ***\n",
 		config.name, config.type, writer_pid, idata->qn, saved_index, idata->elap_time);
 
   if (config.sql_trigger_exec) {
