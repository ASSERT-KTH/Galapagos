The function "alloc_field" increases the quantity of columns by one, allocates more memory for the "columns" array, assigns the address of a "field_data" structure instance to the last element of the "columns" array, checks to see if a caption is included, and marks the "field_data" structure instance as "used". 

Here's a variant that maintains the original functionality but changes some aspects:

alloc_field (int f, char const *c)
{
  char const *capt = c;
  if (field_data[f].used)
    return;

  columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
  struct field_data_t* new_field_data = &field_data[f];
  columns[ncolumns - 1] = new_field_data;

  if (capt)
    new_field_data->caption = capt;

  new_field_data->used = true;
}

In this variant, a pointer, "new_field_data", is used to keep track of the field_data object being manipulated, increasing code readability. The increment on "ncolumns" is now directly made inside the parameter count for the "xnrealloc" call, and the caption parameter was given a local alias to reduce repetitious dereferencing into nullptr checks. Lastly, the "affirm" statement (which likely commands the program to quit if the required condition is not met) is replaced with an early return operation, a more often used code pattern.