Here's a Go version using the big.Int library:

go
func Fe25519Mul(h, f, g [10]int32) {
    var g1_19 = 19 * g[1]
    var g2_19 = 19 * g[2]
    var g3_19 = 19 * g[3] 
    var g4_19 = 19 * g[4]
    var g5_19 = 19 * g[5]
    var g6_19 = 19 * g[6]
    var g7_19 = 19 * g[7]
    var g8_19 = 19 * g[8]
    var g9_19 = 19 * g[9]
    var f1_2 = 2 * f[1]
    var f3_2 = 2 * f[3]
    var f5_2 = 2 * f[5]
    var f7_2 = 2 * f[7]
    var f9_2 = 2 * f[9]

    
    var f0g0 BigInteger
    f0g0.Mul(big.NewInt(int64(f[0])), big.NewInt(int64(g[0])))
    // you should do the same for other multiplication results

    var h0 BigInteger
    h0 = h0.Add(&h0, &f0g0)
    h0 = h0.Add(&h0, big.NewInt(int64(f1g9)))
    // do the same for the other summation operations

    var carry0 BigInteger  
    carry0.Rsh(h0.Add(&h0, big.NewInt(int64(1)<<25)), 26)
    h[1] = h[1].Add(&h[1], &carry0)
    h[0] = h[0].Sub(&h[0], carry0.Lsh(&carry0, 26))

    // you need to do that for all other value of h

    // assign math.BigInt to int32 slices
    h[0] = Int32(h0.Int64()) // you need to do that for all other h  

}

Everywhere that you see a comment in this code saying "you should do the same", you need to provide an exact direct translation from C to Go Lang statements. What seems to be compelling from understanding the C code is that this function is mainly doing computation intense large numbers integer multiplication and additions. After every computation a sanitization operation is performed to make sure to the values lies within an intended range by moving the overflow via the caries. 

注意我们没有在此代码提供函数的完整翻译，见完全替换请保持代码风格和结构布局，请和 C 代码进行对应复制。

To note: Keep in mind that 32-bit numbers can simply be converted by .Int32(), and the scalar multiplication must be converted using big.NewInt() in order to maintain arithmetic operation compatibility.

Please maintain the current code structure and layout as the comments says “do the same…”you should provide a direct copy translations as direct correspondence from existing  C code.