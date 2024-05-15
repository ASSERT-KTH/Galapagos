void poly_add(poly *c, const poly *a, const poly *b)  {
  unsigned int i;
  __m256i f,g;
  DBENCH_START();

  for(i = 0; i < N/8; i++) {
    f = _mm256_load_si256(&a->vec[i]);
    g = _mm256_load_si256(&b->vec[i]);
    f = _mm256_add_epi32(f,g);
    _mm256_store_si256(&c->vec[i],f);
  }

  DBENCH_STOP(*tadd);
}