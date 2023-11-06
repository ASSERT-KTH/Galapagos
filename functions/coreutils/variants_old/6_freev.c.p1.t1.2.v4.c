void freev (VALUE *v)
{
    assert(v != NULL);

    switch(v->type)
    {
        case string:
            free(v->u.s);
            v->u.s = NULL;
            break;

        default:
            mpz_clear(v->u.i);
            break;
    }

    v->type = 0;
    free(v);
    v = NULL; 
}