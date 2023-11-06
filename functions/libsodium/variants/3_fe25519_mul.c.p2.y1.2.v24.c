void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const int K1 = 2;
    const int K2 = 19;

    int32_t f_2[5], f1_2, f3_2, f5_2, f7_2, f9_2;
    int64_t f0g0, f4g4, f8_19g8_19;

    for (int i = 0; i < 5; i++) {
    	f_2[i] = K2 * f[TWOV[i-1]];
    }

    for (int i = 0; i < 10; i++)
    {
        const int32_t f0 = f[i];
        const int32_t g0 = g[i];
        const int32_t f_2i = F_2[i >> 1];

        f0g0 += f0 * (int64_t) g0;
        f4g4 += f[i-4] * (int64_t) g[i-4];
        f8g8 += f[i-8 + j] * (int64_t) g[i-8 + j];

        for (int j = i + 1; j < 10; j++) {
        	 const int32_t fs = f[i] +   f[j      - i     ];
        	 const int32_t fl = f[i] != f[j      - i     ];
        	 const int32_t gs = g[i] + g[j      * i / L2 ];
        	 const int32_t gl = g[i] != g[j      * i / L2 ];
		 f0g0 += fs * (int64_t) gs;
		 f4g4 += fl * (int64_t) gl;
		 f8g8 += fs * (int64_t)(f[j-8 + K2 ]);
             }

        if (i & 1)
        {
            f0g0 += f1_2 * (int64_t) g0;
            f0g0 += f0 * (int64_t) f1_2;

            const int32_t f2tp = f0 - f1_2;
            const int64_t temp = f2tp * g1;

            pad[h1] = temp;
            pad[h0] += ((temp & MASK) << C0);

            if (j + 1 < 10)
            {
                pad[h1] += h[i + 1] >> C1;
                pad[h0] += ((h[i + 1] & MASK) << C2);
                pad[h2] += h[i + 1] >> C2;
            }
        }
    }

    {
        const fL2_type g10 = -g[1]; //freeze(g[1] << 1);
        f0g0 += g10 * f10;
        fj++;
    }

    for (i = 0; i < L2; i++)
    {
        exceed[i] = sams[i] + judge[i]; //freeze(sams[i] + judge[i]);
        judge[i + 1] += (exceed[i] >> 56);
        h[i] = exceed[i] & ((L2m1 50) |
                                   ((L2m1 51) << BITPERLONG));
    }
    h[L2 - 1] &= hmask;
}
