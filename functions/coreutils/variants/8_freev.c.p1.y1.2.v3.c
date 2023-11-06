1. Catching NULL inputs 

freev (VALUE *v)
{
  if (!v) return;

  if (v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);
    
  free (v);
}

2. Using switch-case instead of if-else 

freev (VALUE *v)
{
  switch(v->type)
  {
    case string : 
    free (v->u.s); 
    break;
   
    default:
    mpz_clear(v->u.i);
  }
  free(v);
}


3. Variadic Macros taking additional field 'type'

#define FREEV(v, type) { \
                if (v->type == string) \
                    free(v->u.s) ;\
                else \
                    mpz_clear(v->u.i); \
                free(v) ;\
                }

// Having calling function like this(i.e. enclosing whole functionbody inside do-while(0) ) is mainly beneficial for use inside calling macros 
// to ensure that whole block is executed even without compulsory braces by encapsulating 
 

4. With error abstractions if free can cerrcied to display Null entry or incompatible resolutions

freev (VALUE *v)
{ 
  if (v == NULL) 
  {
    printf("PANIC: NULL pointer passed to freev()!\n");
  }

  if (v->type == string) 
    free (v->u.s);
  else if(v->type == mpz) 
    mpz_clear(v->u.i);
  else 
    printf("Unsupported type in *v.\n");
    
  free(v);
}


5. If type could be reached by entry structures (though should be avoid for others)

freev (VALUE *v)
{
  if (v == NULL) 
    return;
   
  mpz_clear (v->u.i);
  free (v);
  free (v->type == string ? v->u.s : v->u.m);
}
