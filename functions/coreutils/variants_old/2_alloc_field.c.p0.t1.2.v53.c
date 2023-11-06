alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t* field = &field_data[f];
  columns[ncolumns - 1] = field;

  if (c != nullptr)
  {
    field->caption = c;
  }

  assert (!field->used);

  /* Mark field as used. */
  field->used = true;
}