freev (VALUE *v)
{
  if (v->type == string)
  {
    free (v->u.s);
    v->u.s = NULL; // Setting pointer to NULL after free
  }
  else
  {
    mpz_clear (v->u.i);
    v->u.i = 0; // Setting value to 0 after clear
  }

  free (v);
  v = NULL; // Setting pointer to NULL after free
}