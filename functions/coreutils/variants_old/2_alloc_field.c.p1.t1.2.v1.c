void alloc_field (int f, char const *c)
{
    struct field_data_t * temp;
    
    ncolumns++;

    temp = (struct field_data_t *)realloc(columns, ncolumns*sizeof (struct field_data_t *));
    if(temp != NULL) { // ensure that realloc was successful
        columns = temp;
        columns[ncolumns - 1] = &field_data[f];
      
        if (c != nullptr)
            columns[ncolumns - 1]->caption = c;
      
        if(!field_data[f].used) {
            /* Mark field as used.  */
            field_data[f].used = true;
        } else {
            // do nothing
        }
      
   } else {
        // handle error here
   }
}
Consider this program variant uses realloc directly instead of a utility function xnrealloc from the original implementation. It checks whether allocated memory is successfully created by comparing against NULL. It also completed an error check to handle any failure in memory allocation, potentially reducing chances of runtime error.