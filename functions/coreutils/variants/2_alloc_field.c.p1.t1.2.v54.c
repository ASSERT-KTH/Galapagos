
alloc_field (int f, char const *c)
{
   /* Check if field is not used */
   if (!field_data[f].used){
       ncolumns++;
       columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
       columns[ncolumns - 1] = &field_data[f];
  
       if (c != nullptr)
           columns[ncolumns - 1]->caption = c;
       /* Mark field as used */
       field_data[f].used = true;
  }
  /* added functionality, if field is already used, we release a previous field making space for new */
  else {
       /* Check for any previous field that can be freed */
       for (int i = 0; i < f; i++){
            if (field_data[i].used) {
                field_data[i].used = false;
                break;
            }
       }

       /* re-assign the free field to new f */
       ncolumns++; 
       columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
       columns[ncolumns - 1] = &field_data[f];
  
       if (c != nullptr)
           columns[ncolumns - 1]->caption = c;
   
       /* Mark field f as used */
       field_data[f].used = true;
    }
}
