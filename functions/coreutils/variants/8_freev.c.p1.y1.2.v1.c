Option 1:

freev (VALUE *v)
{
  switch(v->type)
  {
    case string:
      free(v->u.s);
      break;
    default:
      mpz_clear(v->u.i);
  }
  free(v);
}


Option 2:

freev (VALUE *v)
{
  if (v != NULL) 
  {
    if (v->type == string) 
      free(v->u.s);
    else
      mpz_clear(v->u.i);
  
    free(v);
  }
}


Option 3:

freev (VALUE *v)
{
  v->type == string ? free(v->u.s) : mpz_clear(v->u.i);
  free(v);
}
