Here's another version of the alloc_field code. It maintains the functionality, error checking is just done at a different location and information is cleared after making it used.


alloc_field (int f, char const *c)
{
  /* Here, affirm is used at the beginning */
  affirm (!field_data[f].used);
  
  ncolumns++;
  columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  /* Mark field as used and clean up data */
  field_data[f].used = true;
  field_data[f].caption = nullptr;
}

This variant allocates incremented columns array. The field_data[ncolumns-1] assumes a field_data[f] content: if conclusion other than the nullptr is reached within initial allocation if statements, the nfields[ncolumns - 1] assumes this additional column's content value, i.e., its earlier innates caption. 

Checking whether the field was previously used occurs at begin of logic (as nothing should prevent array allocations enforcement). Still, an allocated field gets reverted to initial occupation state by clean up assignment - the  use is signified setting it to true.