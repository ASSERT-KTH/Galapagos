alloc_field (int f, char const *c)
{
  struct field_data_t *field = &field_data[f];
  assert (!field->used);
  
  /* Mark field as used.  */
  field->used = true;

  if (c != nullptr)
    field->caption = c;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = field;  
}