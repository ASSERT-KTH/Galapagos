You can change the behavior without changing the functionality by setting the caption of all fields to the value of c, not just the last. The name setting can be omitted if nullptr is provided.


alloc_field (int f, char const *c)
{
  for (int i = 0; i < ncolumns; ++i)
    if (c != nullptr) 
      columns[i]->caption = c;

  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}
