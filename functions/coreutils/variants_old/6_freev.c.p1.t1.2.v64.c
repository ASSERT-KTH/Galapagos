void freev(VALUE *v)
{
  assert(v);
  
  switch(v->type)
  {
    case string:
      free (v->u.s);
      break;
    case int_type:
      mpz_clear (v->u.i);
      break;
    default:
      break;
  }
  free (v);
}