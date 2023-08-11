fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t ra, rb, rc, rd, re;
    uint128_t f_0, f_1, f_2, f_3, f_4;
    uint128_t df0, df1, f138, f238, f338, dal, gal;
    uint64_t  ra0, ra1, ra2, ra3, ra4;
    uint64_t  shift;

    f_0 = (uint128_t) f[0];
    f_1 = (uint128_t) f[1];
    f_2 = (uint128_t) f[2];
    f_3 = (uint128_t) f[3];
    f_4 = (uint128_t) f[4];

    df0 = f_0 << 1;
    df1 = f_1 << 1;

    f138 = 38 * f_1;
    f238 = 38 * f_2;
    f338 = 38 * f_3;

    dal = 19 * f_3;
    gal = 19 * f_4;

    ra = f_0 * f_0  +  f138 * f_4  +  f238 * f_3;
    rb = df0 * f_1  +  f238 * f_4  +  dal * f_3;
    rc = df0 * f_2  +  f_1 * f_1  +  f338 * f_4;
    rd = df0 * f_3  +  df1 * f_2  +  gal * f_4;
    re = df0 * f_4  +  df1 * f_3  +  f_2 * f_2;

    ra0    = ((uint64_t) ra) & mask;
    shift  = (uint64_t) (ra >> 51);
    rb    += shift;
    ra1    = ((uint64_t) rb) & mask;
    shift  = (uint64_t) (rb >> 51);
    rc    += shift;
    ra2    = ((uint64_t) rc) & mask;
    shift  = (uint64_t) (rc >> 51);
    rd    += shift;
    ra3    = ((uint64_t) rd) & mask;
    shift  = (uint64_t) (rd >> 51);
    re    += shift;
    ra4    = ((uint64_t) re) & mask;
    shift  = (uint64_t) (re >> 51);
    ra0   += 19 * shift;
    shift  = ra0 >> 51;
    ra0   &= mask;
    ra1   += shift;
    shift  = ra1 >> 51;
    ra1   &= mask;
    ra2   += shift;

    h[0] = ra0;
    h[1] = ra1;
    h[2] = ra2;
    h[3] = ra3;
    h[4] = ra4;
}