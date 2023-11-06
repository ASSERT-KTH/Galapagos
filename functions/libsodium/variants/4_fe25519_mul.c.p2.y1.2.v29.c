void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g) 
{
    uint64_t mask = 0x7ffffffffffffULL;
    uint128_t r[5], fi[5], gu[5], fen[4];
    uint64_t ri[5],carry;

    for(int i = 0; i < 5; i++) {
        fi[i] = (uint128_t) f[i];
        gu[i] = (uint128_t) g[i];
    }

    for(int i = 1; i < 5; i++) fen[i-1] = 19ULL * fi[i]; 

    r[0] = fi[0] * gu[0] + fen[3] * gu[4] + fen[2] * gu[3] + fen[1] * gu[2] + fen[0] * gu[1];
    r[1] = fi[0] * gu[1] + fi[1] * gu[0] + fen[3] * gu[3] + fen[2] * gu[4] + fen[0] * gu[2];
    r[2] = fi[0] * gu[2] + fi[1] * gu[1] + fi[2] * gu[0] + fen[3] * gu[2] + fen[1] * gu[3];
    r[3] = fi[0] * gu[3] + fi[1] * gu[2] + fi[2] * gu[1] + fi[3] * gu[0] + fen[3] * gu[4];
    r[4] = fi[0] * gu[4] + fi[1] * gu[3] + fi[2] * gu[2] + fi[3] * gu[1] + fi[4] * gu[0];

    for(int i = 0; i < 5; i++) {
        ri[i] = ((uint64_t) r[i]) & mask;
        carry  = (uint64_t) (r[i] >> 51);
        r[i+1] += carry;
    }

    ri[0] += 19ULL * carry;
    ri[0] &= mask;

    for(int i = 1; i < 3; i++) {
        carry = ri[i] >> 51;
        ri[i] &= mask;
        ri[i+1] += carry;
    }

    for(int i = 0; i < 5; i++) h[i] = ri[i];  
}