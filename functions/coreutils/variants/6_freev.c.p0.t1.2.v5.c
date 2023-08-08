freev (VALUE *v)
{
    assert(v != NULL);

    if (v->type == string)
    {
        if (v->u.s != NULL)
        {
            free(v->u.s);
            v->u.s = NULL;
        }
    }
    else
    {
        mpz_clear(v->u.i);
    }

    memset(v, 0, sizeof(VALUE));
    free(v);
    v = NULL; 
}