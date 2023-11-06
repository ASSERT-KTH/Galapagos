alloc_field (int f, char const *c)
{
  struct field_data_t* data_to_alloc = &field_data[f];
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = data_to_alloc;

  if (c != nullptr)
  {
    data_to_alloc->caption = c;
  }

  assert (!data_to_alloc->used);
  data_to_alloc->used = true; // Mark field as used
}