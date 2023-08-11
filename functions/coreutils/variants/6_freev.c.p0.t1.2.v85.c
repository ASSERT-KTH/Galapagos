freev (VALUE *v)
{
  if (v != NULL)
  {
    if (v->type == string)
      free (v->u.s);
    else
      mpz_clear (v->u.i);
    free (v);
    v = NULL;
  }
}