void freev (VALUE *v)
{
  assert(v != NULL); 

  if (v->type == string && v->u.s != NULL)
  {
    free(v->u.s);
    v->u.s = NULL; 
  }
  else if (v->u.i != NULL)
  {
    mpz_clear(v->u.i);
    v->u.i = NULL;
  }

  free(v);
  v = NULL; 
}