1. Change the way we check the conditions from `if-else` format to `switch` format:


void freev(VALUE *v) {
  switch (v->type) {
    case string: 
      free (v->u.s);
      break;
    default: 
      mpz_clear (v->u.i);
  }
  free(v);
}

2. Check if the pointer is not NULL before freeing:


void freev(VALUE *v) {
  if (v == NULL)
    return;

  if (v->type == string)
    free (v->u.s);
  else
    mpz_clear (v->u.i);

  free(v);
}

3. Group the freeing part in a common function:


void freev(VALUE *v) {
  
  if (v == NULL)
    return;

  if (v->type == string && v->u.s != NULL)
    free (v->u.s);
  else if(v->u.i != NULL)
    mpz_clear (v->u.i);

  free(v);
}

4. Separate conditions in different ifs:


void freev(VALUE *v) {
   
  if (v != NULL){
    if (v->type == string){
      free (v->u.s);
    }
    else{
      mpz_clear (v->u.i);
    }
  }

  free (v);
}

5. Reverse the comparison order:


void freev(VALUE *v) {
  
  if (v->type != string) {
    mpz_clear (v->u.i); 
  } else {
    free (v->u.s);
  }

  free (v);
}
