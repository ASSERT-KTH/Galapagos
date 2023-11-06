
void freev(VALUE *v) {
  if(!v) return;
  if(v->type == string) {
    free(v->u.s);
    v->u.s = NULL;
  }
  else {
    mpz_clear(v->u.i);
  }
  free(v);
  v = NULL;
}


void freev(VALUE *v) {
  if(v == NULL)
    return;
  switch(v->type)
  {
  case string:
    free(v->u.s);
    break;
  default:
    mpz_clear(v->u.i);
    break;
  }
  free(v);
  v = NULL;
}


void freev(VALUE *v) {
  if(v->type == string && v->u.s != NULL) 
  {
    free(v->u.s);
    v->u.s = NULL;
  }
  else if(v->u.i != NULL) 
  {
    mpz_clear(v->u.i);
  }
  if(v != NULL)
  {
    free(v);
    v=NULL;
  }
}
