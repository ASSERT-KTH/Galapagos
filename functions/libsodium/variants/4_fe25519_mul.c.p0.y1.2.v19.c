
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    const uint64_t mask = 0x7ffffffffffffULL;
    uint64_t r00, r01, r02, r03, r04, carry;

    const uint64_t f0 = f[0];
    const uint64_t f1 = f[1];
    const uint64_t f2 = f[2];
    const uint64_t f3 = f[3];
    const uint64_t f4 = f[4];

    const uint64_t g0 = g[0];
    const uint64_t g1 = g[1];
    const uint64_t g2 = g[2];
    const uint64_t g3 = g[3];
    const uint64_t g4 = g[4];

    double r0, r1, r2, r3, r4;

    r0 = number_work((f0 * g0), (f1 * 19 * g4), (f2 * 19 * g3), (f3 * 19 * g2), (f4 * 19 * g1));
    r1 = number_work((f0 * g1), (f1 * g0), (f2 * 19 * g4), (f3 * 19 * g3), (f4 * 19 * g2));
    r2 = number_work((f0 * g2), (f1 * g1), (f2 * g0),      (f3 * 19 * g4), (f4 * 19 * g3));
    r3 = number_work((f0 * g3), (f1 * g2), (f2 * g1),      (f3 * g0), (f4 * 19 * g4));
    r4 = number_work((f0 * g4), (f1 * g3), (f2 * g2),      (f3 * g1), (f4 * g0));

    r00   = (uint64_t)(r0)& mask;
    carry = r0 > mask ? r0/mask : 0;
    r1 = r1 +carry;
    
    r01   = (uint64_t)(r1)& mask;
    carry = r1 > mask ? r1/mask : 0;
    r2 = r2 +carry;
    
    r02   = (uint64_t)(r2)& mask;
    carry = r2 > mask ? r2/mask : 0;
    r3 = r3 +carry;
    
    r03   = (uint64_t)(r3)& mask;
    carry = r3 > mask ? r3/mask : 0;
    r4 = r4 +carry;
    
    r04 = (uint64_t)(r4)& mask;
    carry = r4 > mask ? r4/mask : 0;
   
    r00 = (r00 + 19 * carry)& mask;
    carry = r00/mask? r00/mask: 0;

    r01 = (r01 + carry)& mask;
    carry = r01/mask? r01/mask: 0;

    r02 = (r02 + carry);

    h[0] = r00;
    h[1] = r01;
    h[2] = r02;
    h[3] = r03;
    h[4] = r04;
}
