void freev (VALUE *v)
{
    ((v->type == string) ? free : mpz_clear)(v->u.s);
    free(v);
}