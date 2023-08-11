void alloc_field (int f, char const *c)
{
  struct field_data_t * temp = &field_data[f];
  if (temp == nullptr)
    return;

  ncolumns++;
  columns = (struct field_data_t **)realloc(columns, ncolumns * sizeof(struct field_data_t *));
  if (columns == nullptr)
    return;

  columns[ncolumns - 1] = temp;

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;
  else
    columns[ncolumns - 1]->caption = "No caption provided";

  if (field_data[f].used == true)
    return;

  /* Mark field as used.  */
  field_data[f].used = true;
}
- Here I check `temp` and `columns` whether they are `NULL` or not after assignments.
- Step, `columns[ncolumns - 1]->caption = c;`, puts `null` if `c` is `null`. Instead, I have redesigned it so that, if `c` is `null`, the code assigns "No caption provided".