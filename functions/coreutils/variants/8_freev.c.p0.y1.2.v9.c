void freev(VALUE *v)
{
  if(v != NULL)
  {
    if(string == v->type) 
    {
      if(v->u.s != NULL) 
      {
        free(v->u.s);
      }
    }
    else
    {
      mpz_clear(v->u.i);
    }
    free(v);
  }
}