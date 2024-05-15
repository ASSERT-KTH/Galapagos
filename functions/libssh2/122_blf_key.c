blf_key(blf_ctx *c, const uint8_t *k, uint16_t len)
{
    /* Initialize S-boxes and subkeys with Pi */
    Blowfish_initstate(c);

    /* Transform S-boxes and subkeys with key */
    Blowfish_expand0state(c, k, len);
}