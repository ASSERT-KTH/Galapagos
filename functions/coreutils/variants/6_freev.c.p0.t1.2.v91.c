freev(VALUE *v)
{
    if (v->type == string) {
        if(v->u.s != NULL) {
            free (v->u.s);
            v->u.s = NULL;
        }
    } 
    else {
        mpz_clear(v->u.i);
        v->u.i = mpz_init(0);
    }
    free(v);
    v = NULL;
}