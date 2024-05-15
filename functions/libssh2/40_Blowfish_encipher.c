Blowfish_encipher(blf_ctx *c, uint32_t *xl, uint32_t *xr)
{
    uint32_t Xl;
    uint32_t Xr;
    uint32_t *s = c->S[0];
    uint32_t *p = c->P;

    Xl = *xl;
    Xr = *xr;

    Xl ^= p[0];
    BLFRND(s, p, Xr, Xl, 1); BLFRND(s, p, Xl, Xr, 2);
    BLFRND(s, p, Xr, Xl, 3); BLFRND(s, p, Xl, Xr, 4);
    BLFRND(s, p, Xr, Xl, 5); BLFRND(s, p, Xl, Xr, 6);
    BLFRND(s, p, Xr, Xl, 7); BLFRND(s, p, Xl, Xr, 8);
    BLFRND(s, p, Xr, Xl, 9); BLFRND(s, p, Xl, Xr, 10);
    BLFRND(s, p, Xr, Xl, 11); BLFRND(s, p, Xl, Xr, 12);
    BLFRND(s, p, Xr, Xl, 13); BLFRND(s, p, Xl, Xr, 14);
    BLFRND(s, p, Xr, Xl, 15); BLFRND(s, p, Xl, Xr, 16);

    *xl = Xr ^ p[17];
    *xr = Xl;
}