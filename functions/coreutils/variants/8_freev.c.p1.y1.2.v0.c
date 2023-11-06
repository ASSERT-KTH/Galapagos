Version 1: Prefix notation:


freev (VALUE *v)
{
  if ((v->type) == string) {
    free ((v->u).s);
  } else {
    mpz_clear ((v->u).i);
  }

  free (v);
}


Version 2: Ternary operator:


freev (VALUE *v)
{
  (v->type == string) ? free(v->u.s) : mpz_clear (v->u.i);
  free (v);
}


Version 3: Use not equal instead of equal


freev (VALUE *v)
{
  if (v->type != string)
    mpz_clear (v->u.i);
  else
    free (v->u.s);

  free (v);
}
