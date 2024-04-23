ge25519_p1p1_to_p3(ge25519_p3 *r, const ge25519_p1p1 *p)
{
    fe25519_mul(r->X, p->X, p->T);
    fe25519_mul(r->Y, p->Y, p->Z);
    fe25519_mul(r->Z, p->Z, p->T);
    fe25519_mul(r->T, p->X, p->Y);
}