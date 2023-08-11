alloc_field (int f, char const *c)
{
  if (field_data[f].used)
    return;

  field_data[f].used = true;
  columns = (struct field_data_t **)
            xf1 (columns, sizeof (struct field_data_t *), ++ncolumns);
  columns[ncolumns - 1] = &field_data[f];

  if (c)
   {
    if(strlen(c)>0) 
    columns[ncolumns - 1]->caption = c;
   }
}