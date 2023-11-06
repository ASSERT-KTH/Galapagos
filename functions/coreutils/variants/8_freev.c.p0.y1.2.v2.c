void freev (VALUE *v)
{
  if (v->type == string)
  {
    free(v->u.s);
    v->u.s = NULL;
  }
  else
  {
    mpz_clear(v->u.i);
    v->u.i = NULL;
  }
  free(v);
  v = NULL;
}