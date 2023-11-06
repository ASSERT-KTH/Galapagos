void freev (VALUE *v)
{
  switch (v->type)
  {
    case string:
      free (v->u.s);
      break;
    
    default:
      if (v->type >= integer && v->type <= rational)
      {
        mpz_clear (v->u.i);
      }
      break;
  }

  free (v);
}