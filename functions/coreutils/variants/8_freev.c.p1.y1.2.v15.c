Variation 1:

freev (VALUE *v)
{
   mpfr_clr(mprf_init(v->u.i));
   mpz_clear (v->u.i);
   free(v);
}


Variation 2:

freev (VALUE *v)
{
   if (v != NULL && v->u.i != NULL) {
       mpz_clear (v->u.i);
       free (v);
   }
   else if (v != NULL && v->u.s != NULL) {
       free (v->u.s);
       free (v);
   }
}


Variation 3:

freev (VALUE *v)
{
  if (v != NULL) {
    switch (v->type) {
    case string:
      free (v->u.s);
      break;
    default:  /* implies integer and else*/
      mpz_clear (v->u.i);
      break;
    }
    free (v);
  }
}


Variation 4:

freev (VALUE *v)
{
  if(v){
    if(v->type == string){
      free(v->u.s);
    }else{
      mpz_clear(v->u.i);
    }
    free(v);
  }
}


Please note that all of these variations assume that struct VALUE and the lifecycle and behavior of each member types (string, i) along with `mpz_clear`, `free` methods are classified as they are generally in C programming.