ge25519_p3_dbladd(ge25519_p3 *r, const int n, const ge25519_p3 *q)
{
    ge25519_p2   p2;
    ge25519_p1p1 p1p1;
    int          i;

    ge25519_p3_to_p2(&p2, r);
    for (i = 0; i < n; i++) {
        ge25519_p2_dbl(&p1p1, &p2);
        ge25519_p1p1_to_p2(&p2, &p1p1);
    }
    ge25519_p1p1_to_p3(r, &p1p1);
    ge25519_p3_add(r, r, q);
}