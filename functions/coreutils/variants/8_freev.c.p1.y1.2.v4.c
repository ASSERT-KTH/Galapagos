1.

void freev (VALUE *v)
{
  switch(v->type) {
    case string:
      free (v->u.s);
      break;
    default:
      mpz_clear (v->u.i);
  }
  free (v);
}


2.

void freev (VALUE *v)
{
  if (string == v->type)
    free (v->u.s);
  if (string != v->type)
    mpz_clear (v->u.i);
  free (v);
}


3.

void freev (VALUE *v)
{
  if (string == v->type) {
    free (v->u.s);
  } 
  if (int == v->type) {
    mpz_clear (v->u.i);
  }
  free (v);
}

4.

void freev (VALUE *v)
{
  v->type == string ? free (v->u.s) : mpz_clear (v->u.i);
  free (v);
}
