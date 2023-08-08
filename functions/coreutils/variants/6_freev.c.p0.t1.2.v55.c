freev (VALUE *v)
{
  if (v != NULL) 
  {
    if (v->type == string)
      free (v->u.s);
    else
      mpz_clear (v->u.i);
 
     memset(v, 0, sizeof(VALUE));
     free(v);
   }
}