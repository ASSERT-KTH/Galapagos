void poly_nttunpack(poly *a) {
  DBENCH_START();

  nttunpack_avx(a->vec);

  DBENCH_STOP(*tmul);
}