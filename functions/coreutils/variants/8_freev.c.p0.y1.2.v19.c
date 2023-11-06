void freev (VALUE *v)
{
  if (v->type == string) {
      free(v->u.s);
  }
  else if (v->type == number) {
      mpz_clear(v->u.i);
  }
  free(v);
}