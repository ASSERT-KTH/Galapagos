void freev (VALUE *v)
{
  if (string == v->type) {
    free (v->u.s);
  } else {
    mpz_clear (v->u.i);
  }

  free (v);
}