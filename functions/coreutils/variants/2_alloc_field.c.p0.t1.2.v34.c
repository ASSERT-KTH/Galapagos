alloc_field (int f, char const *c)
{
  /* Adjust number of columns first.  */
  ncolumns++;

  /* Reallocate memory to accommodate new fields.  */
  columns = xnrealloc (columns, ncolumns * sizeof (struct field_data_t *));

  /* Mark field as used.  */
  field_data[f].used = true;

  /* Use the new column to capture the field's data. */
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
  {
    /* Assign an optional caption to the field. */
    columns[ncolumns - 1]->caption = c;
  }
  else
  {
    /* No caption, keeping the memory clean. */
    columns[ncolumns - 1]->caption = "";
  }
}