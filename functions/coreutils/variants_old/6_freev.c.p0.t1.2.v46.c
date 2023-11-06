freev (VALUE *v)
{
  if (v != NULL) {
    if (v->type == string)
      free (v->u.s);
    else
      mpz_clear (v->u.i);

    v->u.s = NULL;
    v->u.i = mpz;
    free (v);
  }
}