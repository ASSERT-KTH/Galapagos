alloc_field (int f, char const *c)
{
  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    if(strlen(c) > 0)
      columns[ncolumns - 1]->caption = c;
    else
      columns[ncolumns - 1]->caption = "Empty";

  if(!field_data[f].used){
    /* Mark field as used.  */
    field_data[f].used = true;
  }
}