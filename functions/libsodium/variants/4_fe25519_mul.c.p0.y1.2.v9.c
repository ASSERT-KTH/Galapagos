
fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    unsigned __int128 r[5];
    unsigned __int128 fr[5];
    const uint64_t mask = 0x7ffffffffffffULL;
    int i;
    uint64_t carry;

    // switch from uint64 to __int128, handle scalars immediately
    for (i = 0; i < 5; i++) {
        fr[i] = (unsigned __int128)f[i];
        if (i == 1 || i == 2 || i == 3 || i == 4)	
            fr[i] *= 19;
    }

    r[0] = fr[0]*g[0] + fr[1]*g[4] + fr[2]*g[3] + fr[3]*g[2] + fr[4]*g[1];
    r[1] = fr[0]*g[1] + f[1]*g[0] + fr[2]*g[4] + fr[3]*g[3] + fr[4]*g[2];
    r[2] = fr[0]*g[2] + f[1]*g[1] + f[2]*g[0] + fr[3]*g[4] + fr[4]*g[3];
    r[3] = fr[0]*g[3] + f[1]*g[2] + f[2]*g[1] + f[3]*g[0] + fr[4]*g[4];
    r[4] = fr[0]*g[4] + f[1]*g[3] + f[2]*g[2] + f[3]*g[1] + f[4]*g[0];

    r[1] += r[0] >> 51; r[0] &= mask;
    r[2] += r[1] >> 51; r[1] &= mask;
    r[3] += r[2] >> 51; r[2] &= mask;
    r[4] += r[3] >> 51; r[3] &= mask;
    r[0] += (r[4] >> 51) * 19; r[4] &= mask;

    for (i = 0; i < 5; i++)
        h[i] = r[i];
}
