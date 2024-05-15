cbc_enc(krb5_key key, unsigned char *data, size_t nblocks, unsigned char *iv)
{
    if (aesni_supported(key)) {
        aesni_enc(key, data, nblocks, iv);
        return;
    }
    for (; nblocks > 0; nblocks--, data += AES_BLOCK_SIZE) {
        xorblock(iv, data);
        if (aes_encrypt(data, data, &CACHE(key)->enc_ctx) != EXIT_SUCCESS)
            abort();
        memcpy(iv, data, AES_BLOCK_SIZE);
    }
}