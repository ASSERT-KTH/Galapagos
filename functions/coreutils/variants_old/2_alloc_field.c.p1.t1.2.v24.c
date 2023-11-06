void alloc_field (int f, char const *c)
{
  int i;
  for(i=0; i < ncolumns; i++)
  {
    //Check if the field is already allocated
    if(columns[i] == &field_data[f]) 
    {
      //It is so we update the caption if c isn't null and return
      if (c != nullptr && strcmp(columns[ncolumns - 1]->caption, c)!=0)
        columns[ncolumns - 1]->caption = c;
      return;
    }
  }

  //Program reaches this point only if field wasn't already allocated
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}