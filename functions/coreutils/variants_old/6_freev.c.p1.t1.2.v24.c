void freev (VALUE *v)
{
  assert(v != NULL); // Ensure that pointer isn't null

  switch (v->type) 
  {
    case string:
      free (v->u.s);
      break;
    default:
      mpz_clear (v->u.i);
      break;
  }
  
  free (v);
}