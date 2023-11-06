alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data *new_field = &field_data[f];
  columns[ncolumns - 1] = new_field;

  if (new_field != nullptr)
    new_field->used = true;

  if (c != nullptr)
    new_field->caption = c;

  else
    new_field->caption = "No Caption Provided";

  assert (!field_data[f].used);
}