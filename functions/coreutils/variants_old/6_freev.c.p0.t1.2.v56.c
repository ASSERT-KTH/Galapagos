freev (VALUE *v)
{
  if (v->type == string)
  {
    char *temp_string = v->u.s;
    free (temp_string);
  }
  else
  {
    mpz_t temp_mpz = v->u.i;
    mpz_clear (temp_mpz);
  }
  free (v);
}