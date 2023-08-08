In this variant, we will check if the specified field id `f` already exists in `field_data`. If it does, the function will not go on to mark any field as used. This change introduces additional functionality of checking for the field in the data before marking it used.


alloc_field (int f, char const *c)
{
  int field_exists = 0;
  for (int i = 0; i < ncolumns; i++) {
      if (&field_data[i] == &field_data[f]) {
          field_exists = 1;
          break;
      }
  }
  
  if (field_exists == 0) {
      ncolumns++;
      columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
      columns[ncolumns - 1] = &field_data[f];
      
      if (c != nullptr)
          columns[ncolumns - 1]->caption = c;

      affirm (!field_data[f].used);

      /* Mark field as used.  */
      field_data[f].used = true;
  }
}

So basically, the functionality here checks if the `field_data[f]` is not yet assigned, only then do the rest declaration and allocation. 
This implementation assumes that array `columns` maintains a list of unique field_data pointers, and if the pointer is present, it is not added again.