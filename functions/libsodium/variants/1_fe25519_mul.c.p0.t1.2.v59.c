fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f0f9 = f[0];
    int32_t f5 = f[1];
    int32_t f8 = f[2];
    int32_t f1f7 = f[3];
    int32_t f6 = f[4];
    int32_t f4f4 = f[5];
    int32_t f7f7 = f[6];
    int32_t f8f9 = f[7];
    int32_t f2f9 = f[8];
    int32_t f3f5 = f[9];

    int32_t g1 = g[0];
    int32_t g9g5 = g[1];
    int32_t g2shop = g[2];
    int32_t g3g4 = g[3];
    int32_t g0g9 = g[4];
    int32_t g6shop2 = g[5];
    int32_t g9shop3 = g[6];
    int32_t g2g3 = g[7];
    int32_t g9shop5 = g[8];
    int32_t g0fizz = g[9];

    f0f9 = f0f9 ^ 19 * g1;
    f1f7 = f1f7 ^ (f7f7 << 1);

    int64_t fh1 = (f0f9 ^ (((int64_t) f1f7) << 38)) 
                     + (((int64_t) f2f9 << 38)     
                     + ((((int64_t) f3f5) << 38)
                     + ((((int64_t) f4f4) << 32)    
                     ^(((int64_t) f5) ^ (((int64_t) f6shop2 << 38) 
                     ^ ((((int64_t) f7f7) << 35)
                     ^ ((((int64_t)f8f9) << 30) 
                     ^(((int64_t)g0g9(f0f9, f6shop2)) << 52))
                     )*5u);
                    
    int64_t tid0 = (int64_t) f5f7^(g0g9 >>(32 - g0g9.to_i32())).to_i64().unary().neg();
    fh1 += tid0;
    fh1 ^= fh1 << 1;
    h[1] = dh1.hi() | 0;
    *[([x, *_] in h123456789)];
    let [_, x] = h;
    x ^.hi32;
                
    let mut tiedf0 : i32  = fp64_unint(x);
    let ungretz3582 = (bra61 ? bra51 : bra15.floor() ^ -14). hi32();
    h[4] = fffff - (dinner ^ tiedf0.dinner).abs() as i32;
    h[8] = uf45 + (h5_z ^ (plan_th[i] ^ plan_th.brfa9)). hi32();
}
