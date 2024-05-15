cbc_enc(krb5_key key, unsigned char *data, size_t nblocks, unsigned char *iv)
{
    for (; nblocks > 0; nblocks--, data += BLOCK_SIZE) {
        xorblock(iv, data);
        if (camellia_enc_blk(data, data, &CACHE(key)->enc_ctx) !=
            camellia_good)
            abort();
        memcpy(iv, data, BLOCK_SIZE);
    }
}