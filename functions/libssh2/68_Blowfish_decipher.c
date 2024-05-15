Blowfish_decipher(blf_ctx *c, uint32_t *xl, uint32_t *xr)
{
    uint32_t Xl;
    uint32_t Xr;
    uint32_t *s = c->S[0];
    uint32_t *p = c->P;

    Xl = *xl;
    Xr = *xr;

    Xl ^= p[17];
    BLFRND(s, p, Xr, Xl, 16); BLFRND(s, p, Xl, Xr, 15);
    BLFRND(s, p, Xr, Xl, 14); BLFRND(s, p, Xl, Xr, 13);
    BLFRND(s, p, Xr, Xl, 12); BLFRND(s, p, Xl, Xr, 11);
    BLFRND(s, p, Xr, Xl, 10); BLFRND(s, p, Xl, Xr, 9);
    BLFRND(s, p, Xr, Xl, 8); BLFRND(s, p, Xl, Xr, 7);
    BLFRND(s, p, Xr, Xl, 6); BLFRND(s, p, Xl, Xr, 5);
    BLFRND(s, p, Xr, Xl, 4); BLFRND(s, p, Xl, Xr, 3);
    BLFRND(s, p, Xr, Xl, 2); BLFRND(s, p, Xl, Xr, 1);

    *xl = Xr ^ p[0];
    *xr = Xl;
}