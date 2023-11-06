freev (VALUE *v)
{
  if (v == NULL) return;
  
  if (v->type == string) {
    if (v->u.s != NULL) 
      free (v->u.s); 
  }
  else
    mpz_clear (v->u.i);

  free (v);
}