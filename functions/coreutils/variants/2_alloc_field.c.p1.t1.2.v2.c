
alloc_field(int f, char const *c) 
{
    ncolumns++;
    columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
    struct field_data_t *tmp = &field_data[f];
      
    if(!tmp->used){
       tmp->used = true;
       columns[ncolumns - 1] = tmp;
            
       if (c != nullptr) 
          columns[ncolumns - 1]->caption = c;
   }
   else 
        printf("This field is already used");
}
