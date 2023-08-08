alloc_field (int f, const char *c)
{
  if (!field_data[f].used)
  {
    field_data[f].used = true; /* Mark field as used.  */
    ncolumns++;
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    if (c)
        columns[ncolumns - 1]->caption = c;
   }
   else
   {
       printf("Field is already in use");
   }
}