Variant 1:

void freev (VALUE *v) 
{
  v->type == string ? (free (v->u.s)) : (mpz_clear (v->u.i));
  free (v);
}

Variant 2:

void freev (VALUE *v) 
{
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
}

Variant 3:

void freev (VALUE *v)
{
   (v->type == string && (free (v->u.s), true)) || mpz_clear(v->u.i);
   free(v);
}

Variant 4:

void freev (VALUE *v)
{   
    if (string != v->type){
         mpz_clear(v->u.i);
    }else {
         free(v->u.s);
    }
    free(v);
}

Variant 5:

#define FREEIF(type, v, var, func)  if (v->type == type) func(v->var)

void freev (VALUE *v){
    FREEIF(string, v, u.s, free);
    FREEIF(*an Unspecified Enumerator Name*, v, u.i, mpz_clear)
    free(v);
}
#undef FREEIF
