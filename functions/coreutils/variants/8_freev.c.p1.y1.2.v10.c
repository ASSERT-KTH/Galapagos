1) Changing the order of check/execution:

void freev (VALUE *v)
{
  if (v->type != string)
    mpz_clear (v->u.i);
  else
    free (v->u.s);

  free (v);
}


2) Using `switch` block instead of `if` block:

void freev (VALUE *v)
{
  switch(v->type)
  {
    case string:
      free(v->u.s);
      break;
    default:
      mpz_clear(v->u.i);
      break;
  }

  free (v);
}


3) Selectively assigning deallocation function into function pointer:

void freev (VALUE *v)
{
  void (*dealloc_func)(void*);

  if (v->type == string)
    dealloc_func = &free;
  else
    dealloc_func = &mpz_clear;
  
  dealloc_func((v->type == string) ? (void *)v->u.s : (void *)v->u.i);
  
  free(v);
}


4) Using `do... while` loop for implementing the `if` part:

void freev (VALUE *v)
{
  do
  {
    if (v->type == string)
    {
      free(v->u.s);
      break;
    }
      
    mpz_clear(v->u.i);
  }
  while(0);
  
  free (v);
}


5) Implementing with `ternary` expression:

void freev (VALUE *v)
{
  (v->type == string) ? free(v->u.s) : mpz_clear(v->u.i);

  free (v);
}

Please note - Section 3 uses function pointers, since free and mpz_clear functions have different function signatures these may not work in a real scenario. I listed it here because it does show a different approach provided you have reusable functions with similar signatures.