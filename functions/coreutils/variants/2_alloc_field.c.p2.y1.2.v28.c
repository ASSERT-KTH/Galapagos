Program Variant:

alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *field = &field_data[f];
  
  if (!field->used) {
    field-> used = true;
    columns[ncolumns - 1] = field;  
    
    if (c != nullptr) {
      columns[ncolumns - 1]->caption = c;
    }
  }
}