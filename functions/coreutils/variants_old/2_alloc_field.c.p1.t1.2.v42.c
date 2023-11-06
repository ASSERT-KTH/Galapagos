void alloc_field (int f, char const *c)
{
  struct field_data_t **new_columns;
  
  ncolumns++;
  new_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));

  if (new_columns != nullptr) // Check if memory reallocation was successful
  {
      columns = new_columns;
      columns[ncolumns - 1] = &field_data[f];
      if (c != nullptr)
        columns[ncolumns - 1]->caption = c;

      assert (!field_data[f].used);

      /* Mark field as used.  */
      field_data[f].used = true;
  }
  else // Memory reallocation was unsuccessful, revert the increment of ncolumns
  {
    ncolumns--;
  }
}