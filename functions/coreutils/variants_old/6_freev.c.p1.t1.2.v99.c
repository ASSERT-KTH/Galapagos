void freev (VALUE *v)
{
  assert(v != NULL);

  switch (v->type) {
  case string:
    free (v->u.s);
    break;
  case i:
    mpz_clear (v->u.i);
    break;
  default:
    break;
  }

  free (v);
}