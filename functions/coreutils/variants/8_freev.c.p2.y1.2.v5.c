VALUE* freev(VALUE *v)
{
  if(v) {
    if (v->type == string) {
      if(v->u.s) {
          free(v->u.s);
          v->u.s = NULL; // make sure pointer is NULL after free
      }
    } else {
      mpz_clear(v->u.i);
    } 
    free(v);
    v = NULL; // make sure v cleared after free
  }
  
  return v; // returning pointer, could add usability even though the function originally return void
}