Variant 1:

void freev (VALUE *v)
{
  if (v != NULL) 
  {
    if (v->type == string)
      free (v->u.s);
    else
      mpz_clear (v->u.i);
    free (v);
  }
}

Variant 2:

void freev(VALUE *v)
{
  switch (v->type) 
  {
      case string: 
          free(v->u.s);
          break;
      default: 
          mpz_clear(v->u.i);
  }
  free(v);
}


Variant 3:

void freev(VALUE *v)
{
  string == v->type ? free(v->u.s) : mpz_clear(v->u.i);
  free(v);
}


Variant 4:

void freev(VALUE *v)
{
  if ((string == v->type) && NULL != v->u.s)
  {
    free(v->u.s);
  }
  else if (NULL != v->u.i)
  {
    mpz_clear(v->u.i);
  }
  if (NULL != v)
  {
    free(v);
  }
}


Variant 5:

void freev(VALUE *v)
{
  if (v->type == string) 
  {
    free (v->u.s);
  }
  
  if (v->type == int)
  {
    mpz_clear(v->u.i);
  }
  
  free(v);
}
