void alloc_field (int f, char const *c)
{
  /* Conditional incrementation of ncolumns */
  if (ncolumns < 100) // Here Add a condition, be aware what max value should be for your case
  {
     ncolumns++;
     columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
     
     if (!columns) return; // handle the case if xnrealloc fails 

     columns[ncolumns - 1] = &field_data[f];
     if (c != nullptr)
       columns[ncolumns - 1]->caption = c;
  }

  affirm (!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}