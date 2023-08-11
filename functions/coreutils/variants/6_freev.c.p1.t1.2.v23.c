void freev (VALUE *v)
{
  if (!v) return; // add null checker for better robustness

  switch (v->type)
  {
    case string:
      free(v->u.s);
      break;

    default:
      mpz_clear(v->u.i);
      break;
  }

  free(v);
}