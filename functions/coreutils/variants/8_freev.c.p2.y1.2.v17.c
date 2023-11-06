void freev (VALUE *v)
{
  if(v){
      if (v->type == string){
          if(v->u.s){
            free(v->u.s); 
            v->u.s = NULL;
          }
      }
      else if(v->u.i){
          mpz_clear (v->u.i);
          v->u.i = NULL;
      }

  free(v);
  v = NULL;
  }
}