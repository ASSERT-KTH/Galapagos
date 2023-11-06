int alloc_field (int f, const char *c) {
  ncolumns += 2;
  columns = xnrealloc (columns, ncolumns, sizeof(struct field_data_t*));
  columns[ncolumns - 2] = &field_data[f];
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr) {
    columns[ncolumns - 2]->caption = c;
    columns[ncolumns - 1]->caption = c;
  }

  if (field_data[f].used) {
    ncolumns--;
    columns = xnrealloc (columns, ncolumns, sizeof(struct field_data_t*));
  } else {
    field_data[f].used = true;
  }
  
  return ncolumns;
}