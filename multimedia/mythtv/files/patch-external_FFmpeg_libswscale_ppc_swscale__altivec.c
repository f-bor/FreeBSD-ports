--- external/FFmpeg/libswscale/ppc/swscale_altivec.c.orig	2019-08-11 20:06:32 UTC
+++ external/FFmpeg/libswscale/ppc/swscale_altivec.c
@@ -153,13 +153,13 @@ static void yuv2plane1_float_altivec(const int32_t *sr
     const int add = (1 << (shift - 1));
     const int clip = (1 << 16) - 1;
     const float fmult = 1.0f / 65535.0f;
-    const vector uint32_t vadd = (vector uint32_t) {add, add, add, add};
-    const vector uint32_t vshift = (vector uint32_t) vec_splat_u32(shift);
-    const vector uint32_t vlargest = (vector uint32_t) {clip, clip, clip, clip};
-    const vector float vmul = (vector float) {fmult, fmult, fmult, fmult};
-    const vector float vzero = (vector float) {0, 0, 0, 0};
-    vector uint32_t v;
-    vector float vd;
+    const vec_u32 vadd = (vec_u32) {add, add, add, add};
+    const vec_u32 vshift = (vec_u32) vec_splat_u32(shift);
+    const vec_u32 vlargest = (vec_u32) {clip, clip, clip, clip};
+    const vec_f vmul = (vec_f) {fmult, fmult, fmult, fmult};
+    const vec_f vzero = (vec_f) {0, 0, 0, 0};
+    vec_u32 v;
+    vec_f vd;
     int i;
 
     yuv2plane1_float_u(src, dest, dst_u, 0);
@@ -186,14 +186,14 @@ static void yuv2plane1_float_bswap_altivec(const int32
     const int add = (1 << (shift - 1));
     const int clip = (1 << 16) - 1;
     const float fmult = 1.0f / 65535.0f;
-    const vector uint32_t vadd = (vector uint32_t) {add, add, add, add};
-    const vector uint32_t vshift = (vector uint32_t) vec_splat_u32(shift);
-    const vector uint32_t vlargest = (vector uint32_t) {clip, clip, clip, clip};
+    const vec_u32 vadd = (vec_u32) {add, add, add, add};
+    const vec_u32 vshift = (vec_u32) vec_splat_u32(shift);
+    const vec_u32 vlargest = (vec_u32) {clip, clip, clip, clip};
     const vector float vmul = (vector float) {fmult, fmult, fmult, fmult};
     const vector float vzero = (vector float) {0, 0, 0, 0};
-    const vector uint32_t vswapbig = (vector uint32_t) {16, 16, 16, 16};
-    const vector uint16_t vswapsmall = vec_splat_u16(8);
-    vector uint32_t v;
+    const vec_u32 vswapbig = (vec_u32) {16, 16, 16, 16};
+    const vec_u16 vswapsmall = vec_splat_u16(8);
+    vec_u32 v;
     vector float vd;
     int i;
 
@@ -208,8 +208,8 @@ static void yuv2plane1_float_bswap_altivec(const int32
         vd = vec_ctf(v, 0);
         vd = vec_madd(vd, vmul, vzero);
 
-        vd = (vector float) vec_rl((vector uint32_t) vd, vswapbig);
-        vd = (vector float) vec_rl((vector uint16_t) vd, vswapsmall);
+        vd = (vector float) vec_rl((vec_u32) vd, vswapbig);
+        vd = (vector float) vec_rl((vec_u16) vd, vswapsmall);
 
         vec_st(vd, 0, (float *) &dest[i]);
     }
