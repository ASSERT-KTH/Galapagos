Variant 1:


alloc_field(int f, char const *c)
{
    ncolumns += 1;
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    struct field_data_t* cur_field = &field_data[f];
    columns[ncolumns - 1] = cur_field;

    if (c != nullptr){
        cur_field->caption = c;
    }

    affirm (!cur_field->used);

    // Updating the field as used
    cur_field->used = true;
}


Variant 2:


alloc_field(int f, char const *c) 
{
    columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
    
    columns[ncolumns - 1] = &field_data[f];
    
    if (c != NULL) {
        columns[ncolumns - 1]->caption = c;
    }

    assert(!field_data[f].used);
    field_data[f].used = true;
}


Variant 3:


alloc_field(int f, char const *c) 
{
    struct field_data_t * new_field = &field_data[f];
    columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
    columns[ncolumns - 1] = new_field;
      
    if (c){
        new_field->caption = c;
    }

    affirm (!(new_field->used));
    
    // Mark field as used
    new_field->used = true;
}
