alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  
  /* Assign caption only if given 'c' is not null */
  if (c != nullptr)
    {
      columns[ncolumns - 1]->caption = c;
    }
  else
    {
       columns[ncolumns - 1]->caption = "N/A";
    }

  /* Check if field is already used */
  if(field_data[f].used)
    {
        printf("Error: Field is already used.");
        return;
    }

  /* Mark field as used.  */
  field_data[f].used = true;
}