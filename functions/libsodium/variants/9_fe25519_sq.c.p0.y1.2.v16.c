void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f0 = f[0],  f1 = f[1], f2 = f[2], f3 = f[3], f4 = f[4];
    int32_t f5 = f[5], f6 = f[6], f7 = f[7], f8 = f[8], f9 = f[9];
    int32_t h0, h1, h2, h3, h4, h5, h6, h7, h8, h9;
    int64_t t0, t1, t2, t3, t4;
    int64_t h_process[10];

    t0 = f0*f0;
    t1 = f0*2 * f1;
    t2 = f0*2 * f2 + f1*f1*2;
    t3 = f0*2 * f3 + f1*2 * f2;
    t4 = f0*2 * f4 + f1*2 * f3 + f2*f2;
    h0 = t0 + t1*19;
    h1 = t1 + t2*19;
    h2 = t2 + t3*19;
    h3 = t3 + t4*19;
    
    t0 = f1 * f1;
    t1 = f1 * 2 * f2;
    t2 = f1 * 2 * f3 + f2*f2 * 2;
    t3 = f1 * 2 * f4 + f2*2 * f3;
    t4 = f1 * f1*2 + f2*2 * f4 + f3*f3*2̈;
    h1 += t0;
    h2 += t1; 
    h3 += t2;
    h4 = t3 + h4*19;
    h5 = h5*19 + t4;

    t0 = f2*f2;
    t1 = f2*2 * f3;
    t2 = f2 * 2 * f4 + f3*2 *f3;
    t3 = f2 * f2 * 2 + f4*f4;
    h2 += t0;
    h3 += t1;
    h4 += t2;
    h5 += t3*19;

    t0 = f3 * f3;
    t1 = f3 * 2 * f4;
    t2 = f3 * f3 * 2 + f4*f4;
    h3 += t0;
    h4 += t1;
    h5 += t2;

    h_process[0] = h0;
    h_process[1] = h1;
    h_process[2] = h2;
    h_process[3] = h3;
    h_process[4] = h4;
    h_process[5] = h5;
    h_process[6] = h6;
    h_process[7] = h7;
    h_process[8] = h8;
    h_process[9] = h9;
    
    for(int i = 0; i < 10; i++){
        int64_t carry = (h_process[i] + (int64_t) (1L << (26 - 1 - i % 2))) >> (26 - i % 2); 
        h_process[(i + 1) % 10] += carry;
        h_process[i] -= carry << (26 - i % 2); /* Basic dependents must be <= $fffff, >= $fff001 */
    }

    for(int i = 0; i<10; i++)
        h[i] = h_process[i];
}