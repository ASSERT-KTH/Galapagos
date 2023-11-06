void freev (VALUE *v)
{
  if (v == NULL) return;

  switch (v->type) 
  {
    case t_string:
      free(v->u.s);
      break;

    case t_big_int:
      mpz_clear (v->u.i);
      break;

    default:
      fprintf(stderr, "unknown type\n");
      break;
  }

  free(v);
}