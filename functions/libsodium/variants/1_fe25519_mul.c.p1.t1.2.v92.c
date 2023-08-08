The following is a formally identical version of your previous program, major difference here is that this version reduces repetitive initialization through use of the "for" loop carried out 10 times. It also consolidates variable declarations intended to clean up your code further and furnishes a more concise final result.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t f_vals[10], g_vals[10], g_multiplied_19[10], f_multiplied_2[5];
    int64_t fg_products[100], h_vals[10], carries[10];
    int idx_f, idx_g, idx_h, idx_c;

    for (idx_f = 0; idx_f < 10; idx_f++) {
        f_vals[idx_f] = f[idx_f];
        g_vals[idx_f] = g[idx_f];
        fg_products[idx_f * 10 + idx_f] = f_vals[idx_f] * (int64_t)g_vals[idx_f];

        if (idx_f % 2 != 0) {
            g_multiplied_19[idx_f] = 19 * g_vals[idx_f];
            f_multiplied_2[idx_f / 2] = 2 * f_vals[idx_f];
            carries[idx_f] = (h_vals[idx_f] + (int64_t)(1L << 24)) >> 25;
        }
        else {
            g_multiplied_19[idx_f] = 19 * g_vals[idx_f];
            carries[idx_f] = (h_vals[idx_f] + (int64_t)(1L << 25)) >> 26;
        }

        for (idx_g = idx_f + 1; idx_g < 10; idx_g++) {
            fg_products[idx_f * 10 + idx_g] = f_vals[idx_f] * (int64_t)g_vals[idx_g];
            fg_products[idx_g * 10 + idx_f] = f_vals[idx_g] * (int64_t)g_vals[idx_f];
        }

        fg_products[idx_f * 10 + ((idx_f + 1) % 10)] *= 2;
        fg_products[idx_f * 10 + ((idx_f + 3) % 10)] *= 2;
        fg_products[idx_f * 10 + ((idx_f + 5) % 10)] *= 2;

        fg_products[idx_f * 10 + ((idx_f + 7) % 10)] *=
            ((idx_f + 7) % 10 < 8 ? g_multiplied_19[(idx_f + 7) % 10] : 19);
    }

    for (idx_h = 0; idx_h < 10; idx_h++) {
        for (idx_c = 0; idx_c < 10; idx_c++) { h_vals[idx_h] += fg_products[(idx_h + idx_c) % 10];}
        h_vals[idx_h + 1] += carries[idx_h];
        h[idx_h] = h_vals[idx_h] - carries[idx_h] * ((uint64_t) 1L << ((idx_h + 2) % 2 == 0 ? 26 : 25));
    }
}
