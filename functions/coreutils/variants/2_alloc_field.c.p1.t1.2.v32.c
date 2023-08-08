The following function will still do what is intended - increase an array of columns to keep a reference to a field input (f) alongside a string caption (c). Fields are marked as used after being allocated. A small description of why the field is marked as used has been added.


alloc_field (int f, char const *c)
{
  ncolumns++; 
 
  // Reallocate columns array to fit more items
  columns = (struct field_data_t **) realloc(columns, ncolumns * sizeof (struct field_data_t *));
  
  // Assert the columns got reallocated correctly.
  assert(columns != NULL); 

  // Store the address of the field at the now-available final position.
  columns[ncolumns - 1] = field_data + f; // Equivalent to &field_data[f];
  
  // Store the input string c if it was provided
  if (c != NULL){
    columns[ncolumns - 1]->caption = c; 
  } 
  // Checking if field data is already used or not.
  assert(!field_data[f].used);

  // Now a field has been referenced in a column, it's reported as used subsequent call will not surprise program.
  field_data[f].used = true; 
}


In this version, `realloc()` has been used instead of the `xnalloc` variant that the original code used, which exists presumably to exit when allocation fails. Standard `assert()` has been used twice to protect from disasters when memory allocation and utilizing a previously-used field happens. Also other fields are adjusted or paraphrases (row retriever, setting the caption). Please make sure that the memory blocks you aim to reallocate have originally been allocated with malloc(), calloc() or realloc() to be standard compliant if you chose to use this over the first example.