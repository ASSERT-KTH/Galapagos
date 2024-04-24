jge_zero(jge_t *r) {
  fe_set(r->x, field_one);
  fe_set(r->y, field_one);
  fe_zero(r->z);

  r->inf = 1;
  r->aff = 0;
}