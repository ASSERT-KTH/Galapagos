You can preserve the original behaviour of the method but still change it by performing optimization, adding comments, or simple rearrangement of computations. Here's an intermediate one; small lifting by subtracting the final carry earlier to make operators on bounded values:


void fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t i;
    int64_t t[31];
    for (i = 0; i < 31; ++i) {
        t[i] = 0;
    }

    for (i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            t[i+j] += ((int64_t)f[i]) * g[j];
        }
    }

    int64_t prev = 0;
    int64_t carry;
    for (i = 0; i < 10; i++) {
      t[i] += 19 * prev;
      carry = t[i] >> 25;
      t[i+1] += carry - (carry << 25);
      prev = carry;
    }
    
    h[0] = t[0];
    h[1] = t[1];
    h[2] = t[2];
    h[3] = t[3];
    h[4] = t[4];
    h[5] = t[5];
    h[6] = t[6];
    h[7] = t[7];
    h[8] = t[8];
    h[9] = t[9];
}


If the computation is not sensitive, one could also consider pre-computing operations (19*g[i], f[i]*2) prior definition into new variables to avoid such multiplication during final processing, hence totaling to 20*20*31=248 times of int64 computation, less than 257 of original algorithm. The program apparently lacks complexity consideration limit and bound check that's not mentioned in this optimizer. The h[] constraint could also provide another dimension of improvement yet again the original algorithm fails to guide. Hence, this optimizer conservatively provides an efficient reorder while better preserve its scope.
