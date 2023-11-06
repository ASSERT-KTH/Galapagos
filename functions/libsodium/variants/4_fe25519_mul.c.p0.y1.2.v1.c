void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t t[5];
    uint128_t r0, r1, r2, r3, r4;
    uint128_t fi[5], gi[5];
    uint128_t fi_19[4];
    uint64_t carry;

    for (int i = 0; i < 5; ++i) {
      fi[i] = (uint128_t) f[i];
      gi[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 5; ++i)
      fi_19[i-1] = 19ULL * fi[i];

    t[0] = fi[0] * gi[0] + fi_19[3] * gi[4] + fi_19[2] * gi[3] + fi_19[1] * gi[2] + fi_19[0] * gi[1];
    t[1] = fi[0] * gi[1] +    fi[1] * gi[0] + fi_19[3] * gi[3] + fi_19[2] * gi[2] + fi_19[0] * gi[2];
    t[2] = fi[0] * gi[2] +    fi[1] * gi[1] +    fi[2] * gi[0] + fi_19[3] * gi[4] + fi_19[0] * gi[3];
    t[3] = fi[0] * gi[3] +    fi[1] * gi[2] +    fi[2] * gi[1] +    fi[3] * gi[0] + fi[19[0] * gi[4];
    t[4] = fi[0] * gi[4] +    fi[1] * gi[3] +    fi[2] * gi[2] +    fi[3] * gi[1] +    fi[4] * gi[0];

    for (int i = 0; i < 4; ++i) {
      h[i] = t[i] & mask;
      carry = t[i] >> 51;
      t[i+1] += carry;
    }
  
    h[4] = t[4] & mask;
    carry = t[4] >> 51;
    h[0] += 19ULL * carry;

    carry = h[0] >> 51;
    h[0] &= mask;
    h[1] += carry;
    
    carry= h[1]>>51;
    h[1]&=mask;
    h[2]+=carry;
}