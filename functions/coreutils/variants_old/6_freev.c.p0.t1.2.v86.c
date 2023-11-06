freev (VALUE *v)
{
    if (v) 
    {
        if (v->type == string && v->u.s != NULL)
        {
            free(v->u.s);
            v->u.s = NULL;
        }
        else 
        {
            mpz_clear(v->u.i);
            v->u.i = NULL;
        }
        
        free(v);
        v = NULL;
    }    
}