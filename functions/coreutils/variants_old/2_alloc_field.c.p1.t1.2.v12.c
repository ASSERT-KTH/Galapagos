This program variant uses the same function signature of the original function but modifies slightly with a check to see if the field is already used. It eliminates the option for the same field to be used multiple times. The new function only allows a field to be marked as used if it has not been used previously.


alloc_field (int f, char const *c)
{
  if (!field_data[f].used){
    ncolumns++;
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
      columns[ncolumns - 1]->caption = c;


    /* Mark field as used.  */
    field_data[f].used = true;
  } else {
    fprintf(stderr, "Field %d is already used.\n", f);
    exit(1);
  }
}

This function still increment the columns, allocate more memory for the added column, set the column to a specified field, assign the caption if not NULL, and mark the field as used. However, if the field was already marked as used, this function will terminate the program with a message stating that the field is already used. In this variant, reusing a field is deemed unnecessary.