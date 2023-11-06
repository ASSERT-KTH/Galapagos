You can modify the inner conditions on their own lines to separate checks. But the logic will be maintained:


void freev (VALUE *v)
{
  if (v == NULL)
    return;
  
  if (v->type == string) {
    if(v->u.s != NULL)
      free (v->u.s);
  } else {
     if(v->u.i != NULL)
       mpz_clear (v->u.i);
  }

  free (v);
}


Despite reordering and expanding the if statement, the amended code will perform similarly to the reference implementation. This variant incorporates NULL verifications providing better protection against potential NULL pointer dereferences.