static void idct_put(uint8_t *dst, int stride, int *block)
{
    for (int i = 0; i < 8; i++) {
        if ((block[0x08 + i] |
             block[0x10 + i] |
             block[0x18 + i] |
             block[0x20 + i] |
             block[0x28 + i] |
             block[0x30 + i] |
             block[0x38 + i]) == 0) {
            block[0x08 + i] = block[i];
            block[0x10 + i] = block[i];
            block[0x18 + i] = block[i];
            block[0x20 + i] = block[i];
            block[0x28 + i] = block[i];
            block[0x30 + i] = block[i];
            block[0x38 + i] = block[i];
        } else {
            idct_1d(block + i, 8);
        }
    }

    for (int i = 0; i < 8; i++) {
        idct_1d(block, 1);
        for (int j = 0; j < 8; j++)
            dst[j] = av_clip_uint8((block[j] >> 5) + 128);
        block += 8;
        dst += stride;
    }
}