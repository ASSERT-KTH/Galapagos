jge_set_wge(jge_t *r, const wge_t *p) {
  fe_select(r->x, p->x, field_one, p->inf);
  fe_select(r->y, p->y, field_one, p->inf);
  fe_select(r->z, field_one, field_zero, p->inf);

  r->inf = p->inf;
  r->aff = p->inf ^ 1;
}