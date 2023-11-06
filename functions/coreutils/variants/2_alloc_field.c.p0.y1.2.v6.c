void alloc_field (int f, char const *c) {
  columns = (struct field_data_t **)realloc(columns, sizeof(struct field_data_t *) * (++ncolumns));

  assert(!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
  
  columns[ncolumns - 1] = &field_data[f];
  if (c)
    columns[ncolumns - 1]->caption = c;
}