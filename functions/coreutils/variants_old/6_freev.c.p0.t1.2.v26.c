freev_alternative (VALUE *v)
{
  assert(v != NULL);
  
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