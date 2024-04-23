static int FUNC(rbsp_trailing_bits) (CodedBitstreamContext *ctx,
                                     RWContext *rw)
{
    int err;

    fixed(1, rbsp_stop_one_bit, 1);
    while (byte_alignment(rw) != 0)
        fixed(1, rbsp_alignment_zero_bit, 0);
    return 0;
}