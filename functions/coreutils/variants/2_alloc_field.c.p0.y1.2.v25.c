alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = (field_data_t**) xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  struct field_data_t *new_field = &field_data[f];
  columns[ncolumns - 1] = new_field;

  if (c)
    new_field->caption = c;
    
  assert (!new_field->used);

  /* This indicates the field is used */
  new_field->used = true;
}