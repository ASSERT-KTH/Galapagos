Here's the program variant maintaining the same functionality but with a different structure.

freev (VALUE *v)
{
  switch (v->type) 
  {
    case string:
      free (v->u.s);
      break;

    default:
      mpz_clear (v->u.i);
  }
  
  free (v);
}
