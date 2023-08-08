Here is a variant of the function where the conditional statement used to select which union member to clean up is replaced by a switch-case statement. With only two possible type values, both implementations function identically. The switch-case mechanism is generally considered cleaner and less error-prone when managing more numerous possibilities.

void freev (VALUE *v)
{
  switch(v->type) {
    case string: free (v->u.s); break;
    default: mpz_clear (v->u.i);
  }
  free (v);
}
