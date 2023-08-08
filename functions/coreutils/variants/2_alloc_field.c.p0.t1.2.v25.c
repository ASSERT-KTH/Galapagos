alloc_field (int f, char const *c)
{
   assert (f >= 0);

   columns = (struct field_data_t **)xrealloc (columns, (ncolumns+1)*sizeof (struct field_data_t *));
   columns[ncolumns] = &field_data[f];
   ncolumns++;
   
   assert (!field_data[f].used);   

   if (c != nullptr)
      columns[ncolumns - 1]->caption = strdup(c);
   
   /* Mark field as used.  */
   field_data[f].used = 1;
}