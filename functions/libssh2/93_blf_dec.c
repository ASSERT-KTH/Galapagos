blf_dec(blf_ctx *c, uint32_t *data, uint16_t blocks)
{
    uint32_t *d;
    uint16_t i;

    d = data;
    for(i = 0; i < blocks; i++) {
        Blowfish_decipher(c, d, d + 1);
        d += 2;
    }
}