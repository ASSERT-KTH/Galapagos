Here, before freeing up the memory points to by "v", a condition check is added to ensure that 'v' is not NULL.


void freev (VALUE *v)
{
  if (v == NULL)
    return;
  if (v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);
  free (v);
}
