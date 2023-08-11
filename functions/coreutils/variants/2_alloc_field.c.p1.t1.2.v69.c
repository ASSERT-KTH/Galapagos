
alloc_field (int f, char const *c)
{
  struct field_data_t **tmp_columns = (struct field_data_t **) realloc(columns, (ncolumns+1) * sizeof(struct field_data_t *));
  if (tmp_columns == NULL)
  {
    perror("Not enough memory for realloc");
    return;
  }
  else
  {
    columns = tmp_columns;
  }

  ncolumns++;
  field_data[f].used = false;
  columns[ncolumns - 1] = &field_data[f];

  if (c != nullptr) 
    columns[ncolumns-1]->caption = strdup(c);

  assert(!field_data[f].used);

  /* Mark field as used.  */
  field_data[f].used = true;
}


This variant checks whether realloc can actually allocate the necessary additional space requested. If not, a failure message is printed and the function returns, which means the function exits before a possible reference to a null pointer row. Additionally, this version uses the `strdup(Data)` function to duplicate the caption, ensuring that every field now has its own independent copy of the caption string. This is instead of every new 'column' potentially pointing to the same memory location as the input string, which could cause issues if that string was dynamically allocated and subsequently free'd. It sets `field_data_t.used` to `false` before setting the new column up, just to make absolutely sure `field_data[f].used` is only set to `true` after these operations are completed. This version of the function could seem potentially safer due to the memory allocation check. It appears harsher memory management and provides an explicit copy of the caption string per each field column.