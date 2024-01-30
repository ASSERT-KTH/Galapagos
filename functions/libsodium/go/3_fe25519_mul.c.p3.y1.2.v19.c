go
package main

import "fmt"

func fe25519_mul(h, f, g [10]int32) {
    var f0 = f[0]
    var f1 = f[1]
    var f2 = f[2]
    var f3 = f[3]
    var f4 = f[4]
    var f5 = f[5]
    var f6 = f[6]
    var f7 = f[7]
    var f8 = f[8]
    var f9 = f[9]

    var g0 = g[0]
    var g1 = g[1]
    var g2 = g[2]
    var g3 = g[3]
    var g4 = g[4]
    var g5 = g[5]
    var g6 = g[6]
    var g7 = g[7]
    var g8 = g[8]
    var g9 = g[9]

    var g1_19 = 19 * g1 
    var g2_19 = 19 * g2 
    var g3_19 = 19 * g3
    var g4_19 = 19 * g4
    var g5_19 = 19 * g5
    var g6_19 = 19 * g6
    var g7_19 = 19 * g7
    var g8_19 = 19 * g8
    var g9_19 = 19 * g9
    var f1_2  = 2 * f1
    var f3_2  = 2 * f3
    var f5_2  = 2 * f5
    var f7_2  = 2 * f7
    var f9_2  = 2 * f9

    var f0g0 = int64(f0) * int64(g0)
    var f0g1 = int64(f0) * int64(g1)
    var f0g2 = int64(f0) * int64(g2)
    var f0g3 = int64(f0) * int64(g3)
    var f0g4 = int64(f0) * int64(g4)
    var f0g5 = int64(f0) * int64(g5)
    var f0g6 = int64(f0) * int64(g6)
    var f0g7 = int64(f0) * int64(g7)
    var f0g8 = int64(f0) * int64(g8)
    var f0g9 = int64(f0) * int64(g9)
    var f1g0 = int64(f1) * int64(g0)
    var f1g1_2  = int64(f1_2) * int64(g1)
    var f1g2 = int64(f1) * int64(g2)
    var f1g3_2  = int64(f1_2) * int64(g3)
    var f1g4 = int64(f1) * int64(g4)
    var f1g5_2  = int64(f1_2) * int64(g5)
    var f1g6 = int64(f1) * int64(g6)
    var f1g7_2  = int64(f1_2) * int64(g7)
    var f1g8 = int64(f1) * int64(g8)
    var f1g9_38 = int64(f1_2) * int64(g9_19)
    
    // Continue implementing other similar lines...

    // In the end...

    h[0] = int32(h0)
    h[1] = int32(h1)
    h[2] = int32(h2)
    h[3] = int32(h3)
    h[4] = int32(h4)
    h[5] = int32(h5)
    h[6] = int32(h6)
    h[7] = int32(h7)
    h[8] = int32(h8)
    h[9] = int32(h9)
}
