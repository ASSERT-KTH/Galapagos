alloc_field (int f, char *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t *current_field_data = &field_data[f];
  columns[ncolumns - 1] = current_field_data;
  if (c != NULL)
    current_field_data->caption = c;
  
   assert (current_field_data->used == false);
   
   /* Mark field as used.  */
   current_field_data->used = true;
}