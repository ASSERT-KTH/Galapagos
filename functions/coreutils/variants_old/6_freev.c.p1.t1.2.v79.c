void freev (VALUE *v)
{ 
    assert(v != NULL);

    if (v->type == string) {
        free(v->u.s);
        v->u.s = NULL;  // As an extra measure of safety against being reused after free
    } else {
        mpz_clear(v->u.i);
    }

    v->type = NULL;

    free(v);
    v = NULL;  // Same safety measure as above, if v is somehow still in use after this free call.
}