k5_iov_cursor_get(struct iov_cursor *cursor, unsigned char *block)
{
    size_t nbytes, bsz = cursor->block_size, remain = cursor->block_size;
    const krb5_crypto_iov *iov;

    remain = cursor->block_size;
    while (remain > 0 && cursor->in_iov < cursor->iov_count) {
        iov = &cursor->iov[cursor->in_iov];

        nbytes = iov->data.length - cursor->in_pos;
        if (nbytes > remain)
            nbytes = remain;

        memcpy(block + bsz - remain, iov->data.data + cursor->in_pos, nbytes);
        cursor->in_pos += nbytes;
        remain -= nbytes;

        if (cursor->in_pos == iov->data.length) {
            cursor->in_iov = next_iov_to_process(cursor, cursor->in_iov + 1);
            cursor->in_pos = 0;
        }
    }

    if (remain == bsz)
        return FALSE;
    if (remain > 0)
        memset(block + bsz - remain, 0, remain);
    return TRUE;
}