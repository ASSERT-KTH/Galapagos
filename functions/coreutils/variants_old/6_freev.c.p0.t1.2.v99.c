freev (VALUE *v)
{
    switch(v->type)
    {
        case string:
           free (v->u.s);
           break;

        // cover unstated types
        default:
           mpz_clear (v->u.i);
    };
    free (v);
}