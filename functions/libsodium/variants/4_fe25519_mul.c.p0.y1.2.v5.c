void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t h0, h1, h2, h3, h4;
    uint128_t a, b, c, d, e;
    uint128_t temp0, temp1, temp2, temp3, temp4;
    uint64_t carry;

    a = f[0]; b = f[1]; c = f[2]; d = f[3]; e = f[4];

    temp0 = g[0];
    temp1 = g[1];
    temp2 = g[2];
    temp3 = g[3];
    temp4 = g[4];

    
    h0 = a*temp0 + 19*b*temp4 + 19*c*temp3 + 19*d*temp2 + 19*e*temp1;
    h1 = a*temp1 + b*temp0 + 19*c*temp4 + 19*d*temp3 + 19*e*temp2;
    h2 = a*temp2 + b*temp1 + c*temp0 + 19*d*temp4 + 19*e*temp3;
    h3 = a*temp3 + b*temp2 + c*temp1 + d*temp0 + 19*e*temp4;
    h4 = a*temp4 + b*temp3 + c*temp2 + d*temp1 + e*temp0;

    uint64_t h_00 = (uint64_t) h0 & mask;
    carry = h0 >> 51;
    h1 += carry;
    uint64_t h_01 = (uint64_t) h1 & mask;
    carry = h1 >> 51;
    h2 += carry;
    uint64_t h_02 = (uint64_t) h2 & mask;
    carry = h2 >> 51;
    h3 += carry;
    uint64_t h_03 = (uint64_t) h3 & mask;
    carry = h3 >> 51;
    h4 += carry;
    uint64_t h_04 = (uint64_t) h4 & mask;
    carry = h4 >> 51;
    h_00 = h_00 + 19 * carry;
    carry = h_00 >> 51;
    h_00 &= mask;
    h_01 = h_01 + carry;
    carry = h_01 >> 51;
    h_01 &= mask;
    h_02 = h_02 + carry;

    h[0] = h_00; 
    h[1] = h_01;
    h[2] = h_02;
    h[3] = h_03;
    h[4] = h_04;
}
