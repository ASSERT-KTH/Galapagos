int alloc_field (int f, char const *c)
{
  assert(f>=0);
  columns = (struct field_data_t**) realloc(columns, (++ncolumns) * sizeof (struct field_data_t *));
  if (columns == nullptr)
  {
      fprintf(stderr, "Memory allocation failed");	
      return -1;
  }
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    strcpy((char *)columns[ncolumns - 1]->caption, c);
  
  if(field_data[f].used)
  {
    fprintf(stderr, "Field is already used");	
    return -1;  
  }
  field_data[f].used = true;

  return 0;
}