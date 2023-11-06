alloc_field (int f, char const *c)
{
  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
  {
    int len = strlen(c)+1;
    char* new_caption = malloc(len);
    memcpy(new_caption, c, len);
    columns[ncolumns - 1]->caption = new_caption; 
  }
}