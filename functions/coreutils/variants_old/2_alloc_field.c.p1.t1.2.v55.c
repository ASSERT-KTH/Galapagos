Here's a program variant that changes the behavior of the original function, but maintains its original functionality:


alloc_field (int f, char const *c) 
{
  // Will not do anything if field_data[f] is already used
  if (field_data[f].used)
    return;
  ncolumns++;
  struct field_data_t **columns_temp = NULL;
  columns_temp = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  if (columns_temp != NULL) 
  {  
    // Only modify columns variable if reallocation is successful
    columns = columns_temp;
    columns[ncolumns - 1] = &field_data[f];
  
    if (c != nullptr)
      columns[ncolumns - 1]->caption = c;

    /* Mark field as used.  */
    field_data[f].used = true;
  }
  else 
  {
    // Decrement ncolumns because columns couldn't expand
    ncolumns--;
  }
}


This variant gives the given function the ability to cleanly handle failures from memory reallocation, and will not do anything if the field data at index `f` is already used. The changes in functionality includes an early return if the current field is already used and the check if the reallocation of memory for `columns` is successful.
 
It still respects the remaining items of the original function: manipulation of `(columns, sizeof (struct field_data_t *))`, management of the field with respect to use by the client, maintaining proper index operation given that indices start from 0, hence `- 1`. It also raises safety handling with received pointer `char const *c` in agreement with nullable feature of pointers.