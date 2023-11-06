void release_value (VALUE *val)
{
  if (val->type == string)
    free (val->u.s);
  else
    mpz_clear (val->u.i);
    
  free (val);
}