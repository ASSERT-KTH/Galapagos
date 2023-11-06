1. Transformation using switch:


void freev (VALUE *v)
{
    switch (v->type) 
    {
        case string:
          free (v->u.s);
          break;
  
        default:
          mpz_clear (v->u.i);
          break;
    }
    free (v);  
}


2. Transformation using small expansion space:


void freev(VALUE *v)
{
  if (v == NULL)
    return;

  if (v->type == string) {
    free(v->u.s);
  }
  
  if (v->type != string) {
    mpz_clear(v->u.i);
  }
  
  free(v);
}


3. Transformation using negation:


void freev (VALUE *v)
{
    if (v->type != string)
      mpz_clear (v->u.i);
    else  
      free (v->u.s);
    
    free (v);
}
