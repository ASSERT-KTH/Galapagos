static int FUNC(byte_alignment) (CodedBitstreamContext *ctx, RWContext *rw)
{
    int err;

    fixed(1, byte_alignment_bit_equal_to_one, 1);
    while (byte_alignment(rw) != 0)
        fixed(1, byte_alignment_bit_equal_to_zero, 0);
    return 0;
}