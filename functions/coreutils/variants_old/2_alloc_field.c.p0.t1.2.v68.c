alloc_field (int f, char const *c)
{
  assert(f >= 0);
  
  columns = (struct field_data_t **) realloc(columns, (ncolumns + 1) * sizeof(struct field_data_t *));
  if (columns == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  
  ncolumns++;
  columns[ncolumns - 1] = &field_data[f];
  
  if (field_data[f].used)
  {
    printf("Field already used.\n");
    return;
  }

  if (c != nullptr)
  {
    columns[ncolumns - 1]->caption = c;
  }

  /* Mark field as used.  */
  field_data[f].used = true;
}