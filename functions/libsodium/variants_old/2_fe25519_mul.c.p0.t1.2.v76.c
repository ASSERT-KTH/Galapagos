fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fh[5], gh[5], f19[4];
    uint64_t rpart[5], carry;

    for (int i = 0; i < 5; i++) {
        fh[i] = (uint128_t) f[i];
        gh[i] = (uint128_t) g[i];
    }

    for (int i = 1; i < 5; i++) {
        f19[i-1] = 19ULL * fh[i];
    }

    r[0] = fh[0]*gh[0] + f19[0]*gh[4] + f19[1]*gh[3] + f19[2]*gh[2] + f19[3]*gh[1];
    r[1] = fh[0]*gh[1] + fh[1]*gh[0] + f19[1]*gh[4] + f19[2]*gh[3] + f19[3]*gh[2];
    r[2] = fh[0]*gh[2] + fh[1]*gh[1] + fh[2]*gh[0] + f19[2]*gh[4] + f19[3]*gh[3];
    r[3] = fh[0]*gh[3] + fh[1]*gh[2] + fh[2]*gh[1] + fh[3]*gh[0] + f19[4]*gh[4];
    r[4] = fh[0]*gh[4] + fh[1]*gh[3] + fh[2]*gh[2] + fh[3]*gh[1] + fh[4]*gh[0];

    for (int i = 0; i < 5; i++) {
        rpart[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        if(i<4) {
            r[i + 1] += carry;
        }
        else  rpart[0] += 19ULL * carry;
    }
     
    carry = rpart[0] >>51;
    rpart[0] &= mask;
    rpart[1]+= carry;
    
    carry = rpart[1] >> 51;
    rpart[1]&= mask;
    rpart[2] += carry;

    for (int i = 0; i < 5; i++) {
        h[i] = rpart[i];
    } 
}