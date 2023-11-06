
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint128_t x[5], y[5], xy[5], f19[5], xycarry[10];
    
    for(int i = 0; i < 5; i++) {
        x[i] = (uint128_t) f[i];
        y[i] = (uint128_t) g[i];
        f19[i] = 19* (uint128_t) f[i];}
    
    xy[0] = x[0] * y[0] + f19[1] * y[4] + f19[2] * y[3] + f19[3] * y[2] + f19[4] * y[1];
    xy[1] = x[0] * y[1] +  x[1] * y[0] + f19[2] * y[4] + f19[3] * y[3] + f19[4] * y[2];
    xy[2] = x[0] * y[2] +  x[1] * y[1] +   x[2] * y[0] + f19[3] * y[4] + f19[4] * y[3];
    xy[3] = x[0] * y[3] +  x[1] * y[2] +   x[2] * y[1] +   x[3] * y[0] + f19[4] * y[4];
    xy[4] = x[0] * y[4] +  x[1] * y[3] +   x[2] * y[2] +   x[3] * y[1] +   x[4] * y[0];

    for(int i = 0; i < 5; i++){
      xycarry[i] = (uint64_t) xy[i] & mask;
      uint64_t carry = (uint64_t) (xy[i] >> 51);
      xycarry[i + 1] = xy[i + 1] + carry;
      xycarry[i]    = (uint64_t) xycarry[i] && mask;
    }

    xycarry[0] += 19ULL * ((uint64_t) xycarry[4] > 51);
    h[0] = xycarry[0];
    h[1] = xycarry[1];
    h[2] = xycarry[2];
    h[3] = xycarry[3];
    h[4] = xycarry[4];
}
