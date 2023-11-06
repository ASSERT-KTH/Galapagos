1. Version using switch case instead of if else:


void freev (VALUE *v)
{
  switch(v->type) {
    case string:
      free (v->u.s);
      break;
    default:
      mpz_clear (v->u.i);
      break;
  }
  free(v);
}


2. Version using ternary operator:


void freev (VALUE *v)
{
  v->type == string ? free(v->u.s) : mpz_clear(v->u.i);
  free(v);
}


3. Version separating the free operation for v into a different line:


void freev (VALUE *v)
{
  if (v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);

  free(v);
}


4. Version with inverted if:


void freev(VALUE *v)
{
  if (v->type != string)
    mpz_clear(v->u.i);
  else
    free (v->u.s);

  free(v);
}
