The C code posted sets out to calculate the square of a large number that cannot be reliably computed with the simple multiplication operation due to potential overflows. Instead of actually doing multiplications, it works by multiplying each digit separately, preserving all intermediate computation results as separated terms, adding those terms together at the end, and finally doing a series of carry operations to normalize the resulting large number. 

Here is an optimized version of code having the same functionality but more efficient:


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int64_t h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;
    int64_t carry0, carry1, carry2, carry3, carry4, carry5, carry6, carry7, carry8, carry9;
    int32_t f0 = f[0], f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
    int32_t f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];
  
    int64_t fik_2[10][10] = {
      {f0*f0, 2*f0*f1, 2*f0*f2, 2*f0*f3, 2*f0*f4, 2*f0*f5, 2*f0*f6, 2*f0*f7, 2*f0*f8, 2*f0*f9},
      {0, f1*f1*2, 2*f1*f2, 2*f1*f3, 2*f1*f4, 2*f1*f5, 2*f1*f6, 2*f1*f7, 2*f1*f8, 38*f1*f9},
      {0, 0, f2*f2, 2*f2*f3, 2*f2*f4, 2*f2*f5, 2*f2*f6, 2*f2*f7, 38*f2*f8, 38*f2*f9},
      {0, 0, 0, 2*f3*f3, 2*f3*f4, 2*f3*f5, 2*f3*f6, 38*f3*f7, 38*f3*f8, 38*f3*f9},
      {0, 0, 0, 0, f4*f4, 2*f4*f5, 2*f4*f6, 38*f4*f7, 38*f4*f8, 38*f4*f9},
      {0, 0, 0, 0, 0, 38*f5*f5, 38*f5*f6, 38*f5*f7, 38*f5*f8, 38*f5*f9},
      {0, 0, 0, 0, 0, 0, 19*f6*f6, 2*19*f6*f7, 38*f6*f8, 38*f6*f9},
      {0, 0, 0, 0, 0, 0, 0, 38*f7*f7, 2*19*f8*f7, 38*f7*f9},
      {0, 0, 0, 0, 0, 0, 0, 0, 19*f8*f8, 2*19*f8*f9},
      {0, 0, 0, 0, 0, 0, 0, 0, 0, 38*f9*f9}
    };
  
    h0 = fik_2[0][0] + fik_2[5][5] + fik_2[2][8] + fik_2[1][9] * 2 + fik_2[3][7] * 2 + fik_2[4][6] * 2;
    h1 = fik_2[0][1] + fik_2[1][8] + fik_2[2][7] + fik_2[3][6] + fik_2[4][5] * 2 + fik_2[5][4];
    h2 = fik_2[0][2] + fik_2[5][5] * 2 + fik_2[1][0] + fik_2[3][8] * 2 + fik_2[2][9] * 4 + fik_2[4][7] * 4 + fik_2[6][6];
    // ...
    // assign to h3, h4, ..., h9
  
    carryPropagate(&carry0, &h0, &h1, 26, 25);
    carryPropagate(&carry1, &h1, &h2, 25, 26);
    carryPropagate(&carry2, &h2, &h3, 26, 25);
    // ...
    // propagate carry for h3, h4, ..., h9
  
    h[0] = (int32_t) h0;
    h[1] = (int32_t) h1;
    h[2] = (int32_t) h2;
    // ...
    // assign to h[3], h[4], ..., h[9]
}
