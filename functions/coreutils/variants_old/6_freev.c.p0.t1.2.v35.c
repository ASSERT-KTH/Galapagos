freev (VALUE *v)
{
  assert(v != NULL);
  
  if(v->type == string)
  {
    if(v->u.s != NULL)
      free(v->u.s);
    v->u.s = NULL;  //zeroing pointers after deallocating
  }

  else
  {
    mpz_clear(v->u.i);
    v->u.i = NULL;   //zeroing pointers after deallocating
  }

  free(v);
  v = NULL;  //zeroing pointers after deallocating
}