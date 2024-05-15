read_private_key_from_memory(void **key_ctx,
                             pem_read_bio_func read_private_key,
                             const char *filedata,
                             size_t filedata_len,
                             unsigned const char *passphrase)
{
    BIO * bp;

    *key_ctx = NULL;

#if OPENSSL_VERSION_NUMBER >= 0x1000200fL
    bp = BIO_new_mem_buf(filedata, (int)filedata_len);
#else
    bp = BIO_new_mem_buf((char *)filedata, (int)filedata_len);
#endif
    if(!bp) {
        return -1;
    }

    *key_ctx = read_private_key(bp, NULL, (pem_password_cb *) passphrase_cb,
                                (void *) passphrase);

    BIO_free(bp);
    return (*key_ctx) ? 0 : -1;
}