alloc_field (int f, char const *c)
{
  struct field_data_t **columns_bkp = columns;
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if(columns == nullptr) //code to check insufficient memory 
  {
      columns = columns_bkp;
      ncolumns--;
      return;
  }
  columns[ncolumns - 1] = &field_data[f];
  if (c)
    columns[ncolumns - 1]->caption = strdup(c); //create a unique copy for this field

  if(field_data[f].used) //avoid changing the field status if it was previously marked
      return;

  /* Mark field as used.  */
  field_data[f].used = true;
}