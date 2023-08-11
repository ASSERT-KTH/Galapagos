void alloc_field (int f, char const *c)
{
  if(f < MAX_FIELD && f >= 0) {
    ncolumns++; 
    columns = (struct field_data_t **)xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    if (c) {
      columns[ncolumns - 1]->caption = c;
    }
      
    if(!field_data[f].used) {
      /* Mark field as used.  */
      field_data[f].used = true;
    } else {
      printf("Field already used");
    }
  } else {
    printf("Invalid field index");
  }   
}  

In this variant, it's added input validation to ensure f (field id) is a valid index within our field array (field_data) limits. References to "field_data[f]" are also appropriately checked. 

Additionally, the user receives a message to clarify if an operation to allocate a previously used field attempted.

Note : further verification should carry to account if printf should replace by a version that guarantees security, considering execution environment. Also, depending on your system's scope, some cleaner error treatment way should take place. Saying 'Invalid field index' or 'Field already used' is just a simple, visual way to show that errors are detected; the actual processing of the errors depends on your requirements.