--- media/video/gpu_memory_buffer_video_frame_pool.cc.orig	2022-05-11 07:16:53 UTC
+++ media/video/gpu_memory_buffer_video_frame_pool.cc
@@ -720,7 +720,7 @@ void GpuMemoryBufferVideoFramePool::PoolImpl::CreateHa
   }
 
   bool is_software_backed_video_frame = !video_frame->HasTextures();
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   is_software_backed_video_frame &= !video_frame->HasDmaBufs();
 #endif
 
