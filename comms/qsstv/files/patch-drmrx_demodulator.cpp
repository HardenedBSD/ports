--- drmrx/demodulator.cpp.orig	2019-02-26 18:17:40 UTC
+++ drmrx/demodulator.cpp
@@ -947,7 +947,7 @@ bool demodulator::channelEstimation()
           temp2 += actual_pilots[2 * j] * next_pilots[2 * j + 1] -actual_pilots[2 * j + 1] * next_pilots[2 * j];
 
         }
-      if (i != 0)  delta_freq_offset = (float) atan2(temp2, temp1 + MIN_ABS_H);
+      if (i != 0)  delta_freq_offset = atan2f(temp2, temp1 + MIN_ABS_H);
 
       for (j = 0; j < K_max - K_min + 1; j++)
         {
