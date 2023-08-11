int alloc_field (int f, char const *c)
{
  ncolumns++;

  /* modifying the field prior to reallocating the columns could vary the program's behavior slightly */
  field_data[f].used = true;
  if (c != nullptr) {
    field_data[f].caption = c;
  }

  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  assert (!field_data[f].used);

  /* Revert the 'used' flag back to 'true' since we've finished using it */
  field_data[f].used = true;

  return 0;
}