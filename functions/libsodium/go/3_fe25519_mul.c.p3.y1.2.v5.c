go
func fe25519_mul(h [10]int32, f [10]int32, g [10]int32) [10]int32 {
    var f0 int32 = f[0]
    var f1 int32 = f[1]
    var f2 int32 = f[2]
    var f3 int32 = f[3]
    var f4 int32 = f[4]
    var f5 int32 = f[5]
    var f6 int32 = f[6]
    var f7 int32 = f[7]
    var f8 int32 = f[8]
    var f9 int32 = f[9]

    var g0 int32 = g[0]
    var g1 int32 = g[1]
    var g2 int32 = g[2]
    var g3 int32 = g[3]
    var g4 int32 = g[4]
    var g5 int32 = g[5]
    var g6 int32 = g[6]
    var g7 int32 = g[7]
    var g8 int32 = g[8]
    var g9 int32 = g[9]

    var g1_19 int32 = 19 * g1 
    var g2_19 int32 = 19 * g2 
    var g3_19 int32 = 19 * g3 
    var g4_19 int32 = 19 * g4 
    var g5_19 int32 = 19 * g5 
    var g6_19 int32 = 19 * g6
    var g7_19 int32 = 19 * g7 
    var g8_19 int32 = 19 * g8
    var g9_19 int32 = 19 * g9 
    var f1_2  int32 = 2 * f1 
    var f3_2  int32 = 2 * f3 
    var f5_2  int32 = 2 * f5 
    var f7_2  int32 = 2 * f7
    var f9_2  int32 = 2 * f9 

    var f0g0    int64 = int64(f0 * int32(g0))
    var f0g1    int64 = int64(f0 * (g1))
    /*... continue this for all the `int64`, similar to `C` code ...*/

    var carry0 = int64(0)
    /*... continue initializing all the `carry` variables to `0` as in `C` code ...*/

    /* carry operations like in your `C` code */
    /*[]...*/

    /* rest of the code */

    h[0] = int32(h0);
    /* update other h[i] like h[0] */

    return &h
}

I hope providing explicit int casting properly. Assignment operations way or another similar~! Good Luck!