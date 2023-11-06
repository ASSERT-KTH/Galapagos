go
package main

import (
        "fmt"
)


type fe25519[10] int64;

func fe25519sq(h, f fe25519) {
    var f0 int64 = int64(f[0])
    var f1 int64 = int64(f[1])
    var f2 int64 = int64(f[2])
    var f3 int64 = int64(f[3])
    var f4 int64 = int64(f[4])
    var f5 int64 = int64(f[5])
    var f6 int64 = int64(f[6])
    var f7 int64 = int64(f[7])
    var f8 int64 = int64(f[8])
    var f9 int64 = int64(f[9])


    var f0_2  int64 = 2 * f0
    var f1_2  int64 = 2 * f1
    var f2_2  int64 = 2 * f2
    var f3_2  int64 = 2 * f3
    var f4_2  int64 = 2 * f4
    var f5_2  int64 = 2 * f5
    var f6_2  int64 = 2 * f6
    var f7_2  int64 = 2 * f7
    var f5_38 int64 = 38 * f5     /* 1.959375*2^30 */
    var f6_19 int64 = 19 * f6     /* 1.959375*2^30 */
    var f7_38 int64 = 38 * f7     /* 1.959375*2^30 */
    var f8_19 int64 = 19 * f8     /* 1.959375*2^30 */
    var f9_38 int64 = 38 * f9      /* 1.959375*2^30 */

    var f0f0    int64 = f0 * f0
    ....

    var carry1 int64
    ....

    carry0 = (h0 + (1 << 25)) >> 26
    h1 += carry0
    h0 -= carry0 * (1 << 26)
    ....

    h[0] = int32(h0)
    h[1] = int32(h1)
    h[2] = int32(h2)
    ....
}

I've only given some of the variables conversions here. Complete the whole function with full conversions `int64`.