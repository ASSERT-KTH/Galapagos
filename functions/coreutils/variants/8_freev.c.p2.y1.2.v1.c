void freev (VALUE *v)
{
  if (v == NULL) return;
  switch(v->type)
  {
    case string:
      free (v->u.s);
      break;
    case integer:
      mpz_clear (v->u.i);
      break;
  }
  free (v);
}