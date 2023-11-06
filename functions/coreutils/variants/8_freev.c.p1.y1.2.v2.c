1. Swapping the if/else block

void freev (VALUE *v)
{
  if (v->type != string)
    mpz_clear (v->u.i);
  else
    free (v->u.s);

  free (v);
}

2. Add return at the end of function

void freev (VALUE *v)
{
  if (v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);
    
  free (v);
  
  return;
}

3. Using ternary operator instead of if/else

void freev (VALUE *v)
{
  (v->type == string) ? free (v->u.s) : mpz_clear (v->u.i);
  free (v);
}

4. Removing the space after "if"

void freev (VALUE *v)
{
  if(v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);

  free (v);
}

5. Moving free (v) into the if/else structure

void freev (VALUE *v)
{
  if (v->type == string)
  {
    free (v->u.s);
    free (v);
  }
  else
  {
    mpz_clear (v->u.i);
    free (v);
  }
}
