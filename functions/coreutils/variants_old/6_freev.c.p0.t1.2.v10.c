freev (VALUE *v)
{
    assert(v != NULL);

    if (string == v->type)
        free (v->u.s);
    else
        mpz_clear (v->u.i);

    memset(v, 0, sizeof(VALUE));
    free (v);
}