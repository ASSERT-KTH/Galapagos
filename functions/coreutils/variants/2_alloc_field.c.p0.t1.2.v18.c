alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t* newField = &field_data[f];
  columns[ncolumns - 1] = newField;

  if (c)
    newField->caption = c;

  if(field_data[f].used == false) 
  {
    /* Mark field as used if not used before.  */
    field_data[f].used = true;
  }
}