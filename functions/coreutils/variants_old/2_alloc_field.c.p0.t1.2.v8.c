alloc_field (int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  struct field_data_t * tmp = &field_data[f];
  columns[ncolumns - 1] = tmp;

  if (c != nullptr)
  {
    columns[ncolumns - 1]->caption = c;
  }
  else
  {
    columns[ncolumns - 1]->caption = "No caption provided";
  }      

  if(!field_data[f].used)
  {
    /* Mark field as used.  */
    field_data[f].used = true;
  }
  else
  {
    printf("Error: Field already used");
  }
}