The program variant below uses the same original functionality as the provided C code, but changes the flow of behavior. Instead of checking at the end whether `field_data[f].used` equals false, it checks this at the beginning, throwing an error if it doesn't. Adding this error-checking step at the beginning rather than the end can be useful to stop things earlier if something is already wrong.


alloc_field(int f, char const *c)
{
  if (field_data[f].used)                                                    
  {
    fprintf(stderr, "Field already used!\n");
    exit(EXIT_FAILURE);          
  }
  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
  columns[ncolumns - 1] = &field_data[f];
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;  

  /* Mark field as used.  */
  field_data[f].used = true;
}


This behavioral change should maintain the original functionality of the C code provided while changing the order in which certain processes are completed. Again, your expectations for the correct output and compensations for error should inform whether you would want to use a variant with this kind of change.