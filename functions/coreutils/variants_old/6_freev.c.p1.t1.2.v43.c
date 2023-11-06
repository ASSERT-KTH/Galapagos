void freev(VALUE *v) {
    if (v == NULL) return;

    if (v->type == string) {
        if(v->u.s != NULL){
            free(v->u.s);
            v->u.s = NULL;
        }
    }
    else {
        mpz_clear (v->u.i);
        v->u.i = NULL;
    }

    free(v);
    v=NULL;
}