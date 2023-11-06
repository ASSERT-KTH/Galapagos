Here's one way that changes the behavior by reordering some of the computations. This version aggregates all the similar operations together which could potentially also increase performance on some systems due to loop unrolling and better cache utilization.


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t facts[10];
    int64_t products[45];
    int64_t carry[10];

    for(int i = 0; i < 10; ++i) facts[i] = i & 0x1 ? 2 * f[i] : f[i];

    int j = 0;
    for(int i = 0; i < 10; ++i)
        for(int k = 0; k <= i; ++k)             
            if(k == i) products[j++] = ((i & 0x1) ? 38 * facts[i] : facts[i]) * g[k];
            else products[j++] = ((i+k) & 0x1 ? 38 : 2) * facts[i] * g[k];

    for(int a = 0; a < 10; ++a) h[a] = 0;
    for(int i = 0; i < 100; i ++) h[i%10] += products[i/10 + i%10];

    for(int a = 0; a < 10; ++a) {
        if(a == 0) {
            carry[0] = (h[0] + (int64_t)(1L << 25)) >> 26; h[0] -= carry[0] << 26; h[1] += carry[0];
        } else if(!(a%2)) { // if even
            carry[a] = (h[a] + (int64_t)(1L << 25)) >> 26; h[a] -= carry[a] << 26;
            h[(a + 1) % 10] += carry[a];
        } else { // odd number index
            carry[a] = (h[a] + (int64_t)(1L << 24)) >> 25; h[a] -= carry[a] << 25;
            h[(a + 1) % 10] += carry[a] * (a == 9 ? 19 : 1);
        }
    }

    for(int a = 0; a < 10; ++a) h[a] = (int32_t) h[a];
}
