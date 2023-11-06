The variant program shifts the freeing of the VALUE *v object into the conditional branches for slightly disparate execution paths yet maintains the original function's functionality.


void freev(VALUE *v)
{
  if (v->type == string)
  {
    free(v->u.s);
    free(v);
  }
  else
  {
    mpz_clear(v->u.i);
    free(v);
  }
}
