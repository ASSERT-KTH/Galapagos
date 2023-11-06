alloc_field (int f, char const *c)
{
  int new_column = ncolumns++;
  struct field_data_t **new_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  new_columns[new_column] = &field_data[f];

  if (new_columns[new_column]->caption != c) {
    if (c != nullptr)  
      new_columns[new_column]->caption = c;
  }

  /*If field is already marked as used, do nothing and return. This will avoid unnecessary operations and slightly optimize our function in case we already allocated our field */
  if (field_data[f].used)
    return;

  /*If field is not used, then we allocate and set to used*/
  columns = new_columns;
  field_data[f].used = true;   
}
