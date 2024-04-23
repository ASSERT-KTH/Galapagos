static int FUNC(nal_unit_header) (CodedBitstreamContext *ctx, RWContext *rw,
                                  H266RawNALUnitHeader *current,
                                  int expected_nal_unit_type)
{
    int err;

    fixed(1, forbidden_zero_bit, 0);
    flag(nuh_reserved_zero_bit);

    u(6, nuh_layer_id, 0, 55);

    if (expected_nal_unit_type >= 0)
        u(5, nal_unit_type, expected_nal_unit_type, expected_nal_unit_type);
    else
        ub(5, nal_unit_type);

    u(3, nuh_temporal_id_plus1, 1, 7);
    return 0;
}