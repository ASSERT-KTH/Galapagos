go
import (
    "math/big"
)

type fe25519 [10]int32

func fe25519_sq(h, f *fe25519) {
    var f0 int64 = int64(f[0]);
    var f1 int64 = int64(f[1]);
    var f2 int64 = int64(f[2]);
    var f3 int64 = int64(f[3]);
    var f4 int64 = int64(f[4]);
    var f5 int64 = int64(f[5]);
    var f6 int64 = int64(f[6]);
    var f7 int64 = int64(f[7]);
    var f8 int64 = int64(f[8]);
    var f9 int64 = int64(f[9]);

    var f0_2  int64 = 2 * f0;
    var f1_2  int64 = 2 * f1;
    var f2_2  int64 = 2 * f2;
    var f3_2  int64 = 2 * f3;
    var f4_2  int64 = 2 * f4;
    var f5_2  int64 = 2 * f5;
    var f6_2  int64 = 2 * f6;
    var f7_2  int64 = 2 * f7;
    var f5_38 int64 = 38 * f5;
    var f6_19 int64 = 19 * f6;
    var f7_38 int64 = 38 * f7;
    var f8_19 int64 = 19 * f8;
    var f9_38 int64 = 38 * f9;

    var f0f0 int64 = f0 * f0;
    var.f1f2_2 ... // compute all product terms as like above
  
   // Compute h[0] .. h[9] as expected

  var carry0 = (h[0] + (1<<25)) >> 26;
  
  // calculate remaining carry[x] like above

  h[0] -= int(carry0 * (1<<26))
  
  // multiply remaining elements with their terms (h[x10])

 h[0] = int32(h0)

 // assign remaining values to h as like above
}
