alloc_field (int f, char const *c)
{
  if(field_data[f].used == false)
  {
     ncolumns++;
     columns = (field_data_t **)xrealloc (columns, ncolumns * sizeof (struct field_data_t *));
     columns[ncolumns -1] = &field_data[f];
     if(c){
       columns[ncolumns-1]->caption = strdup(c);
     }  
     field_data[f].used = true; 
  }
  else
  {
    affirm(!field_data[f].used);
  }    
}