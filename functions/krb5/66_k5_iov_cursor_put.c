k5_iov_cursor_put(struct iov_cursor *cursor, unsigned char *block)
{
    size_t nbytes, bsz = cursor->block_size, remain = cursor->block_size;
    const krb5_crypto_iov *iov;

    remain = cursor->block_size;
    while (remain > 0 && cursor->out_iov < cursor->iov_count) {
        iov = &cursor->iov[cursor->out_iov];

        nbytes = iov->data.length - cursor->out_pos;
        if (nbytes > remain)
            nbytes = remain;

        memcpy(iov->data.data + cursor->out_pos, block + bsz - remain, nbytes);
        cursor->out_pos += nbytes;
        remain -= nbytes;

        if (cursor->out_pos == iov->data.length) {
            cursor->out_iov = next_iov_to_process(cursor, cursor->out_iov + 1);
            cursor->out_pos = 0;
        }
    }
}