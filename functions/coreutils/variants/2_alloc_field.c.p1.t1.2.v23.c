In this program variant, the possible error from "<Field already used>" has been handled. Additional parameters have been added to the "affirm" function which is assumed to work similar to 'assert'. This approach obtains and checks potential issues, such as field being already used. A provision has been made for the function to return an error code "-1" if the field selected is already in use.


int alloc_field (int f, char const *c)
{
  if (field_data[f].used){
    printf("<Field already in use> \n");
    return -1;
  }
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  affirm (!field_data[f].used, "Failure: field already used.");

  /* Mark field as used.  */
  field_data[f].used = true;

  return 0;
}

Nice Variant: Please note this new proposal reaffirms that the field should not be used and adds error handling for 'resallocation'. If it fails trying to reallocate more space for columns with the 'xnrealloc' function, the function interrupts immediately, allowing the function to let user know that something went wrong.


int alloc_field (int f, char const *c)
{
  struct field_data_t* new_columns;

  if (field_data[f].used){
    printf("<Field already in use> \n");
    return -1;
  }

  new_columns = xnrealloc (columns, ncolumns + 1, sizeof (struct field_data_t *));
  if (!new_columns) {
    printf("<Failure when reallocating memory> \n");
    return -1;
  }

  columns = new_columns;
  columns[++ncolumns - 1] = &field_data[f];

  if (c != nullptr) {
    columns[ncolumns - 1]->caption = c;
  }

  affirm (!field_data[f].used, "Failure: field already used.");

  /* Mark field as used.  */
  field_data[f].used = true;

  return 0;
}
