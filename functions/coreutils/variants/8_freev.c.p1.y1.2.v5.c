1. Swapping Conditions 

freev (VALUE *v)
{
  if (v->type != string)
    mpz_clear (v->u.i);
  else 
    free (v->u.s);
    
  free (v);
}


2. Using Ternary Operator

freev (VALUE *v)
{
  (v->type == string) ? free (v->u.s) : mpz_clear (v->u.i);
  free (v);
}


3. Negating initial condition

freev (VALUE *v)
{
  if (!(v->type != string))
    free (v->u.s);
  else 
    mpz_clear (v->u.i);
  free (v);
}


4. Explicit value checking on type
 
freev (VALUE *v)
{
  if (v->type == 0) // Let's assume 0 is string
    free (v->u.s);
  else 
    mpz_clear (v->u.i);
  free (v);
}


5. Perform free regardless (but employ null-checking)

freev (VALUE *v)
{
  if (v->type == string)
  {
    free (v->u.s);
    v->u.s = NULL;
  }
  else
  {
    mpz_clear (v->u.i);
    v->u.i = NULL; // Operation assuming mpz_t can be set to NULL
  }
  free(v);
}
