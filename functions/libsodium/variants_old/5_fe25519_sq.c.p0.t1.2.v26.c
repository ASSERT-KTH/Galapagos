// Variant of the original function
void fe25519_sq(fe25519 h, const fe25519 f)
{
    const uint64_t mask_spec = 0x7ffffffffffffULL;
    uint128_t r_1, r_2, r_3, r_4, r_5;
    uint128_t f_a, f_b, f_c, f_d, f_e;
    uint128_t f_a_two, f_b_two, f_d_19, f_e_19;
    uint64_t  r1_val, r2_val, r3_val, r4_val, r5_val;
    uint64_t  allocator;

    f_a = (uint128_t) f[0];
    f_b = (uint128_t) f[1];
    f_c = (uint128_t) f[2];
    f_d = (uint128_t) f[3];
    f_e = (uint128_t) f[4];

    f_a_two = f_a << 1;
    f_b_two = f_b << 1;

    uint128_t f_b_38 = 38ULL * f_b;
    uint128_t f_c_38 = 38ULL * f_c;
    uint128_t f_d_38 = 38ULL * f_d;

    f_d_19 = 19ULL * f_d;
    f_e_19 = 19ULL * f_e;

    r_1 =   f_a * f_a + f_b_38 * f_e + f_c_38 * f_d;
    r_2 = f_a_two * f_b + f_c_38 * f_e + f_d_19 * f_d;
    r_3 = f_a_two * f_c +    f_b * f_b + f_d_38 * f_e;
    r_4 = f_a_two * f_d +  f_b_two * f_c + f_e_19 * f_e;
    r_5 = f_a_two * f_e +  f_b_two * f_d +    f_c * f_c;

    r1_val    = ((uint64_t) r_1) & mask_spec;
    allocator  = (uint64_t) (r_1 >> 51);
    r_2    += allocator;
    r2_val    = ((uint64_t) r_2) & mask_spec;
    allocator  = (uint64_t) (r_2 >> 51);
    r_3    += allocator;
    r3_val    = ((uint64_t) r_3) & mask_spec;
    allocator  = (uint64_t) (r_3 >> 51);
    r_4    += allocator;
    r4_val    = ((uint64_t) r_4) & mask_spec;
    allocator  = (uint64_t) (r_4 >> 51);
    r_5    += allocator;
    r5_val    = ((uint64_t) r_5) & mask_spec;
    allocator  = (uint64_t) (r_5 >> 51);
    r1_val   += 19ULL * allocator;
    allocator  = r1_val >> 51;
    r1_val   &= mask_spec;
    r2_val   += allocator;
    allocator  = r2_val >> 51;
    r2_val   &= mask_spec;
    r3_val   += allocator;

    h[0] = r1_val;
    h[1] = r2_val;
    h[2] = r3_val;
    h[3] = r4_val;
    h[4] = r5_val;
}