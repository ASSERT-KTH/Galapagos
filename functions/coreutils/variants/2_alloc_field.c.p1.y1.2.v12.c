Version 1:

void alloc_field (int f, const char *c)
{
  columns = (field_data_t **) realloc(columns, ++ncolumns * sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
  if(c) // c != nullptr implies that c is not NIL (NULL)
  {
    columns[ncolumns - 1]->caption = c;
  }

  assert(field_data[f].used == false);

  /* Mark field as used. */
  field_data[f].used = true;
}

Version 2:

void alloc_field (int f, char const *c) 
{
  ncolumns += 1;

   columns = (struct field_data_t **) realloc(columns, ncolumns * sizeof (struct field_data_t *));

   columns[ncolumns - 1] = &field_data[f];
   if (c) 
   {
     columns[ncolumns - 1]->caption = c;
   }

  assert(!field_data[f].used);

  /* Mark field as used. */
  field_data[f].used = true;
}

Version 3:


void alloc_field (int f, char const *c) 
{
  columns = (struct field_data_t **)realloc(columns, (ncolumns + 1) * sizeof (struct field_data_t *));
  ncolumns++;

  struct field_data_t *data_col = columns[ncolumns - 1]; 
  
  data_col = &field_data[f];

  if (c) 
  {
    data_col->caption = c;
  }

  assert(field_data[f].used == false);

  /* Mark field as used. */
  field_data[f].used = 1; // true
}
