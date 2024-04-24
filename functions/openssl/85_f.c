static word32 f(gost_ctx * c, word32 x)
{
    x = c->k87[x >> 24 & 255] | c->k65[x >> 16 & 255] |
        c->k43[x >> 8 & 255] | c->k21[x & 255];
    /* Rotate left 11 bits */
    return x << 11 | x >> (32 - 11);
}