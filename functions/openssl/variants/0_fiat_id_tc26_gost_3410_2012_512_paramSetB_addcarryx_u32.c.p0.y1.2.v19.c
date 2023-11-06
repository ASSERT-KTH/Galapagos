static void fiat_id_tc26_gost_3410_2012_512_paramSetB_addcarryx_u32(
    uint32_t *out1, fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 *out2,
    fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1 arg1, uint32_t arg2,
    uint32_t arg3) {

    uint64_t temp_sum;
    uint32_t truncated_sum, carry;

    // calculates the sum of inputs
    temp_sum = ((uint64_t)arg1 + arg2 + arg3);

    // truncate sum to 32 bit
    truncated_sum = (uint32_t)(temp_sum & UINT32_C(0xffffffff));

    // calculates bit-wise shift to the right and assign result to carry
    carry = (fiat_id_tc26_gost_3410_2012_512_paramSetB_uint1)(temp_sum >> 32);

    // assign truncated sum and carry to out1 and out2 respectively
    *out1 = truncated_sum;
    *out2 = carry;
}