alloc_field (int f, char const *c)
{
  struct field_data_t** temp;
  temp = xnrealloc (columns, ncolumns + 1, sizeof (struct field_data_t *));
  if(temp != NULL) 
  {
    columns = temp;
    ncolumns++;
    columns[ncolumns - 1] = &field_data[f];
    if (c)
      columns[ncolumns - 1]->caption = c;

    if(!field_data[f].used){

      /* Mark field as used.  */
      field_data[f].used = true;
    }
  }
}