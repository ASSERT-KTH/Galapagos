fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t t0, t1, t2, t3, t4;
    uint128_t fi0, fi1, fi2, fi3, fi4;
    uint128_t f0_2, f1_2, f1_38, f2_38, f3_38, f3_19, f4_19;
    uint64_t  s00, s01, s02, s03, s04;
    uint64_t  carry;

    fi0 = (uint128_t) f[0];
    fi1 = (uint128_t) f[1];
    fi2 = (uint128_t) f[2];
    fi3 = (uint128_t) f[3];
    fi4 = (uint128_t) f[4];

    f0_2 = fi0 << 1;
    f1_2 = fi1 << 1;

    f1_38 = 38ULL * fi1;
    f2_38 = 38ULL * fi2;
    f3_38 = 38ULL * fi3;

    f3_19 = 19ULL * fi3;
    f4_19 = 19ULL * fi4;

    t0 =   (fi0 * fi0) + (f1_38 * fi4) + (f2_38 * fi3);
    t1 = (f0_2 * fi1) + (f2_38 * fi4) + f3_19 * fi3;
    t2 =  f0_2 * fi2 +  fi1 * fi1  +  f3_38 * fi4;
    t3 = f0_2 * fi3 +  f1_2 * fi2 +  f4_19 * fi4;
    t4 = f0_2 * fi4 +  f1_2 * fi3 +  fi2 * fi2;

    s00 = ((uint64_t) t0) & mask;
    carry  = (uint64_t) (t0 >> 51);
    t1 += carry;
    s01 = ((uint64_t) t1) & mask;
    carry  = (uint64_t) (t1 >> 51);
    t2 += carry;
    s02 = ((uint64_t) t2) & mask;
    carry  = (uint64_t) (t2 >> 51);
    t3 += carry;
    s03 = ((uint64_t) t3) & mask;
    carry  = (uint64_t) (t3 >> 51);
    t4 += carry;
    s04 = ((uint64_t) t4) & mask;
    carry  = (uint64_t) (t4 >> 51);


    s00 += 19ULL * carry;
    carry  = s00 >> 51;
    s00 &= mask;
    s01 += carry;
    carry  = s01 >> 51;
    s01 &= mask;
    s02 += carry;

    h[0] = s00;
    h[1] = s01;
    h[2] = s02;
    h[3] = s03;
    h[4] = s04;
}