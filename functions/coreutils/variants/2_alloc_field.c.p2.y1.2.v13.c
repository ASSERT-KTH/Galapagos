int alloc_field (int f, char const *c)
{
  columns = (struct field_data_t **) realloc (columns, (++ncolumns) * sizeof (struct field_data_t *));

  if (columns != nullptr)
  {
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
      columns[ncolumns - 1]->caption = c;
  
    if (!field_data[f].used)
    {
      field_data[f].used = true;
    }
  }
  else // handle realloc failure
  {
    --ncolumns; // restore original number of columns
  }
  
  return (columns != nullptr) ? 0 : -1; // successful allocation return 0
}