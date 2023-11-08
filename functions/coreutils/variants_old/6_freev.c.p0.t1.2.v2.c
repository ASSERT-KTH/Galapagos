freev (VALUE *v)
{
  if (v != NULL) {
     if (v->type == string) {
        if(v->u.s != NULL) {
          free (v->u.s);
        }
     }  
     else {
        if(v->u.i != NULL) {
          mpz_clear (v->u.i);
        }
     }
     free (v);
     v = NULL;
  }
}