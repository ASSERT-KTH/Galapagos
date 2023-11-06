alloc_field (int f, char const *c)
{
  ncolumns +=1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t * curr_field = &field_data[f];
  columns[ncolumns - 1] = curr_field;

  if (c != nullptr)
    curr_field->caption = c;

  assert (!curr_field->used);

  /* Mark field as used.  */
  curr_field->used = true;
}