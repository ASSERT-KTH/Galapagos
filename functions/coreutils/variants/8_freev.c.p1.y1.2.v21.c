1.

freev (VALUE *v)
{
  switch (v->type) 
  {
    case string:
      free(v->u.s);
      break;

    default:
      mpz_clear(v->u.i);
      break;
  }
  free(v);
}


2.

freev (VALUE *v)
{
  v->type == string ? free(v->u.s) : mpz_clear(v->u.i);
  free (v);
}


3.

freev (VALUE *v)
{
  if (v->type == string)
    free (v->u.s);
    
  if (v->type != string)
    mpz_clear (v->u.i);
    
  free (v);
}
