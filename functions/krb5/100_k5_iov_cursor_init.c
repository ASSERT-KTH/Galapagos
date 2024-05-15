k5_iov_cursor_init(struct iov_cursor *cursor, const krb5_crypto_iov *iov,
                   size_t count, size_t block_size, krb5_boolean signing)
{
    cursor->iov = iov;
    cursor->iov_count = count;
    cursor->block_size = block_size;
    cursor->signing = signing;
    cursor->in_iov = next_iov_to_process(cursor, 0);
    cursor->out_iov = cursor->in_iov;
    cursor->in_pos = cursor->out_pos = 0;
}