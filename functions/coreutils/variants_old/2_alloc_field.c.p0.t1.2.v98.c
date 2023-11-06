alloc_field (int f, char const *c) {            
  if (f < 0 || !c)             
    return;                    
  field_data[f].used = true;
    
  ncolumns++;                  
  columns = (struct field_data_t**) xnrealloc (columns, ncolumns, sizeof (struct field_datat_t*));     
  columns[ncolumns-1] = &field_data[f];                 
                                             
  if (c != nullptr)
    columns[ncolumns-1]->caption = strdup(c);
                                                    
  /* Ensuring the field is free before being allocated.  */
  if (!field_data[ncolumns - 1].used) {
    /* Mark field as used.  */
    field_data[ncolumns - 1].used = true;
  }
}