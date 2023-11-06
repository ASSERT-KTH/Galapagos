freev (VALUE *v)
{
  assert(v != NULL);
  switch (v->type) {
    case string: 
      free(v->u.s);
      break;
    default:  // assuming the other possible type is integer
      mpz_clear(v->u.i);
      break;
  }
  free(v);
}