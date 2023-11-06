alloc_field (int f, char const *c)
{
  struct field_data_t *new_field = &field_data[f];

  affirm (!new_field->used);
  /* Mark field as used upfront. */
  new_field->used = true;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = new_field;
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
}