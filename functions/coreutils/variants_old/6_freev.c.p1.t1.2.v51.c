void freev (VALUE *v)
{
  if (v)
  {
    if (v->type == string)
    {
      free(v->u.s);
      v->u.s = NULL;
    }
    else if(v->type == integer)
    {
      mpz_clear (v->u.i);
    }
      
    free(v);
    v = NULL;
  }
}