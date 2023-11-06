Variant 1


alloc_field (int f, char const *c)
{
  ncolumns++;
  columns[ncolumns - 1] = &field_data[f];
  
  columns = (struct field_data_t **) 
            realloc(columns, ncolumns * sizeof (struct field_data_t *));
  columns[ncolumns - 1]->caption = (c != NULL) ? c : columns[ncolumns - 1]->caption;

  /* avoid concurrent usage  */
  assert (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}


Variant 2


alloc_field (int f, char const *c)
{
  ncolumns++;
  
  if (!field_data[f].used)
  {
    columns = (struct field_data_t **) 
              realloc(columns, ncolumns * sizeof (struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    columns[ncolumns - 1]->caption = (c != NULL) ? c : columns[ncolumns - 1]->caption;
    
    /* Mark field as used.  */
    field_data[f].used = true;
  }
  else 
  {
    printf("Field already used!\n"); 
  }
  
  assert(field_data[f].used);
}


Variant 3


alloc_field (int f, char const *c)
{
  if (!field_data[f].used)
  {
    ncolumns++;
    columns = (struct field_data_t **) 
              realloc(columns, ncolumns * sizeof (struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
  
    if (c != NULL) 
    {
       columns[ncolumns - 1]->caption = c;
    }
  
    /* Mark field as used.  */
    field_data[f].used = true;
  }
  
   /* avoid concurrent usage  */
  assert(field_data[f].used);
}
