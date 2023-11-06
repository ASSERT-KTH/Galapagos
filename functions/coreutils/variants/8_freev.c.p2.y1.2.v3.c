VALUE *freev (VALUE **vp)
{
  VALUE *v = *vp;
  if (v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);
   
  free(v);
  *vp = NULL;
  return NULL;
}