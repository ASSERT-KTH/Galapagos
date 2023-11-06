fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t var0 = f[0];
    int32_t var1 = f[1];
    int32_t var2 = f[2];
    int32_t var3 = f[3];
    int32_t var4 = f[4];
    int32_t var5 = f[5];
    int32_t var6 = f[6];
    int32_t var7 = f[7];
    int32_t var8 = f[8];
    int32_t var9 = f[9];

    int32_t var0_2 = 2 * var0;
    int32_t var1_2 = 2 * var1;
    int32_t var2_2 = 2 * var2;
    int32_t var3_2 = 2 * var3;
    int32_t var4_2 = 2 * var4;
    int32_t var5_2 = 2 * var5;
    int32_t var6_2 = 2 * var6;
    int32_t var7_2 = 2 * var7;
    int32_t var5_38 = 38 * var5;
    int32_t var6_19 = 19 * var6;
    int32_t var7_38 = 38 * var7;
    int32_t var8_19 = 19 * var8;
    int32_t var9_38 = 38 * var9;

    int64_t mult00 = var0 * (int64_t) var0;
    int64_t mult01 = var0_2 * (int64_t) var1;
    int64_t mult02 = var0_2 * (int64_t) var2;
    int64_t mult03 = var0_2 * (int64_t) var3;
    int64_t mult04 = var0_2 * (int64_t) var4;
    int64_t mult05 = var0_2 * (int64_t) var5;
    int64_t mult06 = var0_2 * (int64_t) var6;
    int64_t mult07 = var0_2 * (int64_t) var7;
    int64_t mult08 = var0_2 * (int64_t) var8;
    int64_t mult09 = var0_2 * (int64_t) var9;
    int64_t mult11 = var1_2 * (int64_t) var1;
    int64_t mult111 = var1_2 * (int64_t) var2;
    int64_t mult122 = var1_2 * (int64_t) var3_2;
    int64_t mult112 = var1_2 * (int64_t) var4;
    int64_t mult120 = var1_2 * (int64_t) var5_2;
    int64_t mult113 = var1_2 * (int64_t) var6;
    int64_t mult133 = var1_2 * (int64_t) var7_2;
    int64_t mult91 = var1_2 * (int64_t) var9_38; 

    //the same transformation should be applied until the end.

    //...

    h00 = (mult00 + (int64_t)(1L << 25)) >> 26;
    h11 += h00;
    h00 -= h00 * ((uint64_t) 1L << 26);
    carry4 = (h[4] + (int64_t)(1L << 25)) >> 26;
    h[5] += carry4;
   //... the same transformation till the end ...//

    h[0] = (int32_t) h00;
    h[1] = (int32_t) h11;
    h[2] = (int32_t) h2; 
    //...the same transformation till the end...//
}