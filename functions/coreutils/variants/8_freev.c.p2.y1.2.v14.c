void freev (VALUE *v) 
{
  assert(v != NULL); // This guards the entire function rather than individual types only

  switch(v->type) 
  {
    case string:
      free (v->u.s);
      break;
    case int:
      mpz_clear (v->u.i);
      break;
    default:
      fprintf(stderr, "Unexpected type\n");
      break;
  }
  
  free(v);
}