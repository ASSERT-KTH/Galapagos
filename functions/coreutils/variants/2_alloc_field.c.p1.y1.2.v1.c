1. Below is a variant that introduces local pointer programing.


alloc_field (int f, char const *c)
{
  struct field_data_t** new_columns;

  ncolumns++;
  new_columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  new_columns[ncolumns - 1] = &field_data[f];

  /* if caption is not NULL,assign caption*/
  if (c != nullptr)
    new_columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;

  columns = new_columns;
}


2. Below is a variant that reduces the redundancy by creating the 'column' once in the function instead of twice.


alloc_field (int f, char const *c)
{
  ++ncolumns;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t * new_column = &field_data[f];
  
  if (c != nullptr)
    new_column->caption = c;

  affirm (!new_column->used);

  /* Mark field as used.  */
  new_column->used = true;
    
  columns[ncolumns - 1] = new_column;
}


3. Unwind transforms to separate several different actions from any branches.


alloc_field (int f, char const *c)
{
  /* realloc the columns */
  char const * actualCaption;
  
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  
  /* Set current field */
  columns[ncolumns - 1] = &field_data[f];
  
  actualCaption = (c != nullptr) ? c : columns[ncolumns - 1]->caption;
  
  /* Set the caption */
  columns[ncolumns - 1]->caption = actualCaption;
  
  
  /* Assert if field is unused */
  affirm (!field_data[f].used);
  
  /* Mark as the field is used */
  field_data[f].used = true;
}
