ge25519_p3_add(ge25519_p3 *r, const ge25519_p3 *p, const ge25519_p3 *q)
{
    ge25519_cached q_cached;
    ge25519_p1p1   p1p1;

    ge25519_p3_to_cached(&q_cached, q);
    ge25519_add_cached(&p1p1, p, &q_cached);
    ge25519_p1p1_to_p3(r, &p1p1);
}