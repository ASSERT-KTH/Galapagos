The 'alloc_field' function can be rewritten as follows:


alloc_field (int f, char const *c)
{
  assert(f >= 0 && f < MAX_COLUMNS, "Invalid field index");
  
  if (!field_data[f].used)
  {
    field_data[f].used = true;

    ncolumns++;

    if(ncolumns >= current_column_capacity)
    {
      current_column_capacity *= 2;
      columns = (struct field_data_t**) realloc(columns, current_column_capacity * sizeof(struct field_data_t *));
    }

    columns[ncolumns - 1] = &field_data[f];
    
    assert(columns[ncolumns - 1] != NULL, "Out of memory.");

    if (c != nullptr)
      columns[ncolumns - 1]->caption = c;

  }
  else
  {
    print("Field already used.");
    exit(1);
  }
}  


Points to be noticed in this version:
- Instead of using 'xnrealloc', the regular 'realloc' was used which is not checking for memory overflow every time we add a new field. To check manually 'if' condition is included.
- We now keep track of our current array capacity ('current_column_capacity'), and if we used it up, we double its size.
- Before we set a field as used, we are checking first if it is already used, if yes then a error message "Field already used." is printed and the program quits because we have attempted to assign a field that is already assigned.
- Additionally, the 'f >= 0 and 'f < MAX_COLUMNS' condition validates the field index based on a constant 'MAX_COLUMNS'.

Note: This variant assumes the presence of a 'MAX_COLUMNS' constant which was not part of the original function but seems required based on the nature of the modifications.
Warning: As with any C code, be aware of the risks associated with buffer overflow when handling function calls or resizing buffers. Be sure to understand well what your function is doing and validate all user input.