void freev (VALUE *v)
{
  if (v)
  {  
    if (v->type == string)
      free (v->u.s);
    else
      mpz_clear (v->u.i);

    v = NULL;
  }
  free (v);
}