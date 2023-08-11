fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fi[5], g_i[5];
    uint128_t fi_19[4];
    uint64_t r_i[5];
    uint64_t carry;

    for(int i = 0; i < 5; i++) {
        fi[i] = (uint128_t) f[i];
        if(i < 4) fi_19[i] = 19ULL * fi[i+1];
        g_i[i] = (uint128_t) g[i];
    }

    r[0] = fi[0] * g_i[0] + fi_19[0] * g_i[4] + fi_19[1] * g_i[3] + fi_19[2] * g_i[2] + fi_19[3] * g_i[1];
    r[1] = fi[0] * g_i[1] +    fi[1] * g_i[0] + fi_19[1] * g_i[4] + fi_19[2] * g_i[3] + fi_19[3] * g_i[2];
    r[2] = fi[0] * g_i[2] +    fi[1] * g_i[1] +    fi[2] * g_i[0] + fi_19[2] * g_i[4] + fi_19[3] * g_i[3];
    r[3] = fi[0] * g_i[3] +    fi[1] * g_i[2] +    fi[2] * g_i[1] +    fi[3] * g_i[0] + fi_19[3] * g_i[4];
    r[4] = fi[0] * g_i[4] +    fi[1] * g_i[3] +    fi[2] * g_i[2] +    fi[3] * g_i[1] +    fi[4] * g_i[0];

    for(int i=0;i<5;i++) {
      r_i[i]    = ((uint64_t) r[i]) & mask;
      carry  = (uint64_t) (r[i] >> 51);
      r[i+1] += carry;
    }

    carry  = r_i[4] >> 51;
    r_i[0]   += 19ULL * carry;
    for(int i=0;i<5;i++) {
      carry  = r_i[i] >> 51;
      r_i[i] &= mask;
      r_i[i+1] += carry;
      h[i] = r_i[i];
    }
}