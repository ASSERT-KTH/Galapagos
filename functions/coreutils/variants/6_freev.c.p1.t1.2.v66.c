void freev (VALUE *v)
{
  assert(v != NULL);
  if (v->type == string)
  {
    assert(v->u.s != NULL);
      free (v->u.s);
  }
  else
  {
    mpz_clear (v->u.i);
  }
 free (v);
}