alloc_field(int f, char const *c)
{
  ncolumns = ncolumns + 1;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  int lastIndex = ncolumns - 1;
  columns[lastIndex] = &field_data[f];
  
  if (c)
  {
    columns[lastIndex]->caption = c;
  }

  bool existedBefore = field_data[f].used;

  if (!existedBefore)
  {
    /* This code will only execute if field_data[f].used is initially false */
    field_data[f].used = true;
  }
  /* if field_data[f].used is initially true, this function doesn't really change its value */
}