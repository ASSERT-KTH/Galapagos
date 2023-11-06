void alloc_field(int f, const char *c)
{
  ncolumns += 1;
  columns = xnrealloc(columns, ncolumns * sizeof(struct field_data_t *));
  
  struct field_data_t *field_ptr = &field_data[f];
  columns[ncolumns - 1] = field_ptr;
  
  if(c) {
    field_ptr->caption = c;  
  }

  assert(field_ptr->used == false);

  field_ptr->used = true;
}