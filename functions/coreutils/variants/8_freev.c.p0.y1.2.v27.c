void freev (VALUE *v)
{
  bool isString = (v->type == string);

  if (isString) {
      free(v->u.s);
  } else {
      mpz_clear(v->u.i);
  }

  free(v);
}