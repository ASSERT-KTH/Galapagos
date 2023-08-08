void alloc_field (int f, char const *c)
{
  assert(f >= 0);
  if(c != nullptr) field_data[f].caption = strdup(c);

  /* In this version, we do not care whether the field was used or not. */
  
  /* Mark field as used. */
  if (!field_data[f].used)
  {
      field_data[f].used = true;
      ncolumns++;
  }

  columns = (struct field_data_t **)realloc(columns, ncolumns * sizeof(struct field_data_t*));
  if(columns == nullptr) 
  {
    fprintf(stderr, "Memory allocation failed!\n");
    exit(1);
  }
  
  columns[ncolumns - 1] = &field_data[f];
}