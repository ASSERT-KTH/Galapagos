void freev (VALUE *v)
{
  if (v != NULL) {
    if (v->type == string) {
      free (v->u.s);
      v->u.s = NULL;
    } else {
      mpz_clear (v->u.i);
    }
    v->type = 0; 
    free (v);
    v = NULL;
  }
}