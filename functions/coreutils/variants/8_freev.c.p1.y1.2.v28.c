
void freev (VALUE *v)
{
  switch (v->type) {
    case string:
      free (v->u.s);
      break;
      
    default:
      mpz_clear (v->u.i);
      break;
  }
  free (v);
}



void freev (VALUE *v)
{
  v->type == string ? free (v->u.s): mpz_clear (v->u.i);
  free (v);
}



void freev (VALUE *v)
{
  if (v->type == string) {
    free (v->u.s);
  }
  if (v->type != string) {
    mpz_clear (v->u.i);
  }
  free (v);
}



void freev (VALUE *v)
{
  if (string == v->type) 
    free (v->u.s);
  if (string != v->type) 
    mpz_clear (v->u.i);
  free (v);
}
