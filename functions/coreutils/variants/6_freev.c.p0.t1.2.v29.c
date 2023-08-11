freev (VALUE *v) 
{
  if (v == NULL)
     return; 

  if (v -> type == string)
  {
     free (v->u.s);
     v->u.s = NULL; 
  }
  else
  {
     mpz_clear (v->u.i); 
  }

  free (v);
  v = NULL;
}