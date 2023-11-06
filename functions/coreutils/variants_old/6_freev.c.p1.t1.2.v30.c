void freev(VALUE *v) 
{
  switch(v->type)
  {
    case string:
      free(v->u.s);
      break;

    case integer: //Assuming second type is 'integer'
    default:
      mpz_clear(v->u.i);
      break;
  }

  free(v);
}