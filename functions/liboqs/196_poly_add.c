void poly_add(poly *c, const poly *a, const poly *b)  {
    unsigned int i;
    DBENCH_START();

    for (i = 0; i < N; ++i) {
        c->coeffs[i] = a->coeffs[i] + b->coeffs[i];
    }

    DBENCH_STOP(*tadd);
}