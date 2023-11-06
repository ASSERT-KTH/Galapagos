void alloc_field (int f, char const *c)
{
  struct field_data_t *temp;  // adding temp field pointer variable
  temp = &field_data[f];
  
  ncolumns++;
  columns = (struct field_data_t **)realloc(columns, ncolumns * sizeof (struct field_data_t *));
  if (columns == nullptr) {
     printf ("Memory allocation failed.\n");
     exit (EXIT_FAILURE);
  }  
  
  columns[ncolumns - 1] = temp;

  /* Added condition - if no caption is provided, use the default "No Caption" */
  if (c == nullptr)
  {
    columns[ncolumns - 1]->caption = "No Caption";
  }
  else
  {
    columns[ncolumns - 1]->caption = c;
  }

  affirm (!temp->used);

  /* Mark field as used.  */
  temp->used = true;
}