_libssh2_mbedtls_mpi_write_binary(unsigned char *buf,
                                  const mbedtls_mpi *mpi,
                                  size_t bytes)
{
    unsigned char *p = buf;
    uint32_t size = (uint32_t)bytes;

    if(sizeof(&p) / sizeof(p[0]) < 4) {
        goto done;
    }

    p += 4;
    *p = 0;

    if(size > 0) {
        mbedtls_mpi_write_binary(mpi, p + 1, size - 1);
    }

    if(size > 0 && !(*(p + 1) & 0x80)) {
        memmove(p, p + 1, --size);
    }

    _libssh2_htonu32(p - 4, size);

done:

    return p + size;
}