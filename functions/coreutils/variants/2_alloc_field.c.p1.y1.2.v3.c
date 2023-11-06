1. Start allocation from 0 to ensure same functionality.

alloc_field (int f, char const *c)
{
  struct field_data_t **p = realloc(columns, sizeof(struct field_data_t *) * (ncolumns+1));
  
  if(p) {
    columns = p;
    columns[ncolumns] = &field_data[f];
    ncolumns++;

    if (c != nullptr) columns[ncolumns - 1]->caption = c;

    affirm (!field_data[f].used);

    /* Mark field as used.  */
    field_data[f].used = true;
  }
}

2. Conditioning allocation only when element is not used.

alloc_field (int f, char const *c)
{
  if (!field_data[f].used) 
  {
    columns = (struct field_data_t **)realloc(columns, sizeof(struct field_data_t *) * (ncolumns+1));

    if (columns != NULL)
    {
      columns[ncolumns] = &field_data[f];
      ncolumns++;

      if (c != nullptr)
        columns[ncolumns - 1]->caption = c;


      /* Mark field as used. */
      field_data[f].used = true;
      affirm (field_data[f].used);
    }
  }
}

3. Implicit order of statement execution changed with if condition to avoid unnecessary increment of `nColumns` and allocation.

alloc_field (int f, char const *c)
{
   affirm (!field_data[f].used);
  
  if(!field_data[f].used) 
  {  
    columns = (struct field_data_t **)realloc(columns, sizeof(struct field_data_t *) * (ncolumns+1));

    if(NULL != columns)
    {
      columns[ncolumns++] = &field_data[f];

      if(NULL != c)
          columns[ncolumns - 1]->caption = c;

    /* Mark field as used. */
    
      field_data[f].used = true;
    }
  }
}
