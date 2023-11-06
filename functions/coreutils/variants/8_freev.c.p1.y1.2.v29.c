Variant 1:

freev (VALUE *v)
{
  switch(v->type) {
      case string:
      	free(v->u.s);
      	break;
      default:
	mpz_clear(v->u.i);
  }
  free (v);
}


Variant 2: 

freev (VALUE *v)
{
  if (v == NULL) return;

  if (v->type == string)
    free(v->u.s);
  else 
    mpz_clear(v->u.i);

  free(v);
}


Variant 3:

freev (VALUE *v)
{
  if (string == v->type)
    free(v->u.s);
  else 
    mpz_clear(v->u.i);

  free(v);
}
`Common
