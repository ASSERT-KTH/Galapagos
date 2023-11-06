One possible variant of the program, introducing a switch statement instead of the if-else structure:


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


It has a slightly varied behavior but maintains the same essential functionality as initial version.