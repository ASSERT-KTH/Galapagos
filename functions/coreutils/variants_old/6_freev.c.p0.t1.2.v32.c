freev (VALUE *v)
{ 
  switch(v->type)
  {
     case string:
       free (v->u.s);
       v->u.s = NULL;
       break;
     default:
       mpz_clear (v->u.i);
       break;
  }
  free (v);
  v = NULL;
}