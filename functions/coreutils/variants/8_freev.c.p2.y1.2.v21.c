freev (VALUE *v)
{
  if(NULL != v)
  {
    if (v->type == string)
    {
      if(NULL != v->u.s){
        free(v->u.s);
      }
    }
    else
    {
      mpz_clear(v->u.i);
    }
    free(v);
    v = NULL;
  }
}