void alloc_field (int f, char const *c)
{
  assert (f >= 0);
  assert (f < field_data_size);

  /* Mark field as used.  */
  if(field_data[f].used) return;
  
  field_data[f].used = true;

  ncolumns++;
  void *tmp = realloc(columns, ncolumns * sizeof (struct field_data_t *));
  if(tmp == NULL)
    exit(-1);
  
  columns = tmp;
  columns[ncolumns - 1] = &field_data[f];
  
  if (c != NULL)
  {
    size_t size = strlen(c) + 1;
  
    char *cpy = malloc(size);
    if(!cpy) 
      exit(-1);
  
    strncpy(cpy, c, size);
    columns[ncolumns - 1]->caption = cpy;
  }
}