alloc_field (int f, char const *c)
{
  struct field_data_t *p = &field_data[f];
  
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = p;
  
  /* Verify if c is not a null pointer and assign it as a caption */
  if (c)
    columns[ncolumns - 1]->caption = c;

  /* Assert that field_data is not already used */
  affirm (!p->used);

  /* Mark field as used.  */
  p->used = true;
}