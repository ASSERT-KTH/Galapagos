void freev (VALUE *v)
{
  if (v->type == string){
    free (v->u.s);
  }
  
  if (v->type != string){
    mpz_clear (v->u.i);
  }
  
  free(v);
}