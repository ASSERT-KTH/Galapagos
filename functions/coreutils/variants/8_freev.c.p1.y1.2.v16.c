1. Moving condition to a variable:

freev (VALUE *v)
{
  int is_string = (v->type == string);

  if (is_string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);

  free (v);
}

2. Inverted boolean check:

freev (VALUE *v)
{
  if (v->type != string)
    mpz_clear (v->u.i);
  else
    free (v->u.s);

  free (v);
}

3. Using ternary operator:

freev (VALUE *v)
{
  v->type == string ? free(v->u.s) : mpz_clear (v->u.i);
  free (v);
}


4. Using switch case:

freev (VALUE *v)
{
  switch(v->type)
  {
    case string:
      free (v->u.s);
      break;
    default:
      mpz_clear(v->u.i);
  }
  free (v);
}

Please note that these all transformations equivalent and choice should be dictated by maintability or style guide of given codebase.