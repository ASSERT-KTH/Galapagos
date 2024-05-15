blf_enc(blf_ctx *c, uint32_t *data, uint16_t blocks)
{
    uint32_t *d;
    uint16_t i;

    d = data;
    for(i = 0; i < blocks; i++) {
        Blowfish_encipher(c, d, d + 1);
        d += 2;
    }
}