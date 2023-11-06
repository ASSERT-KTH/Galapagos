
void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int64_t fElement[10], gElement[10], elementProduct[100] = { 0 }, carry[10] = { 0 };

    for (int i = 0; i < 10; i++)
    {
        fElement[i] = f[i];
        gElement[i] = g[i];
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            elementProduct[i + j] += fElement[i] * ((!(i & 1) && j & 1 || i & 1 && !(j & 1)) ? gElement[j] * 19 : gElement[j]);
        }
    }

    for (int round = 0; round < 4; round++)
    {
        for (int i = 0; i < 10; i++)
        {
            elementProduct[i + 1] += (elementProduct[i] >> (i? 25:26));
            elementProduct[i] &= (1L << ((i == 0 || i%2) ? 26 : 25)) - 1;
        }
 
    }

    elementProduct[0] += elementProduct[10]*19;
    carry[0] = (elementProduct[0] + (1L << 25)) >> 26;
    elementProduct[0] -= carry[0] * (1L << 26);
    elementProduct[1] += carry[0];

    for (int i = 0; i < 10; i++)
    {
        h[i] = elementProduct[i];
    }
}
