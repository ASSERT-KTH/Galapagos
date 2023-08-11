alloc_field (int f, char const *c)
{
  /* Mark field as used first. */
  field_data[f].used = true;

  int new_position = ncolumns;
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[new_position] = &field_data[f];

  if (c != nullptr)
    columns[new_position]->caption = c;

  /* Remove the affirmation section, since it's already handled at the beginning */
  // affirm (!field_data[f].used);
}