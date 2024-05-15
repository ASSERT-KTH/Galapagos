int bdrv_pwrite(BlockDriverState *bs, int64_t offset,
                const void *buf, int count1)
{
    QEMUIOVector qiov;
    struct iovec iov = {
        .iov_base   = (void *) buf,
        .iov_len    = count1,
    };

    qemu_iovec_init_external(&qiov, &iov, 1);
    return bdrv_pwritev(bs, offset, &qiov);
}