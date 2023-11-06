alloc_field(int f, const char *c){
  columns = xnrealloc(columns, ++ncolumns, sizeof(struct field_data_t *));
  struct field_data_t * lastColumn = &field_data[f];

  assert(!lastColumn->used);

  columns[ncolumns - 1] = lastColumn;
  lastColumn->used = true;

  if(c != nullptr){
     lastColumn->caption = c;
  }
}