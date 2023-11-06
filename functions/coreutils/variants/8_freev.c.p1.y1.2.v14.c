1. Swap Independent Commands:


void freev (VALUE *v)
{
  free (v);
  if (v->type == string)
    free (v->u.s);
  else 
    mpz_clear (v->u.i);
}


2. Using Ternary Operator instead of If-Else:


void freev (VALUE *v)
{
 (v->type == string) ? free (v->u.s) : mpz_clear (v->u.i);
 free(v);
}


3. Conditional Execution using AND Operator:


void freev (VALUE *v)
{
  (v->type == string && (free (v->u.s), 1)) || mpz_clear (v->u.i);
  free (v);
}


4. Embed Else If Case:


void freev (VALUE *v)
{
  if (v->type == string)
  {
    free (v->u.s);
  } 
  else if (v->type != string)
  {
    mpz_clear (v->u.i);
  }
  free(v);
}


5. Focus Error Case First:


void freev (VALUE *v)
{
  if (v->type != string)
  {
    mpz_clear(v->u.i);
  }
  else
  {
    free(v->u.s);
  }
  free(v);
}
