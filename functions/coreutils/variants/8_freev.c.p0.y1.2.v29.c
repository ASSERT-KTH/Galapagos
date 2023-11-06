void freev (VALUE *v)
{
  if (v->type == string)
  {
    free (v->u.s);
  }
  else
  {
    if (v->type == integer) 
    {
      mpz_clear (v->u.i);
    }
  }
  free (v);  
}