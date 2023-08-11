freev (VALUE *v)
{
  if (v != NULL) {
    if (v->type == string) {
        if(v->u.s != NULL){
          free (v->u.s);
          v->u.s = NULL;
        }
    } else {
      mpz_clear (v->u.i);
    }
    free (v);
    v = NULL;
  }
}