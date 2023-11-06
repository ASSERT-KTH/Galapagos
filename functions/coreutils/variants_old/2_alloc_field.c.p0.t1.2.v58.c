alloc_field (int f, char const *c)
{
  struct field_data_t *col;
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  col = &field_data[f];
  
  if (col->used)
  {
    fprintf(stderr, "The field is already in use.");
    exit(1);
  }

  if (c != nullptr)
    col->caption = c;

  /* Mark field as used.  */
  col->used = true;
  
  columns[ncolumns - 1] = col;
}