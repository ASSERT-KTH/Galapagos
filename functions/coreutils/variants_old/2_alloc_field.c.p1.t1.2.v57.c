Okay, I got it. You want a variant that should be logically equivalent but differently implemented. Here it is:


void alloc_field(int f, const char *c) {
    struct field_data_t *new_col = &field_data[f];
    
    if (!new_col->used) {
        new_col->used = true;
        new_col->caption = (c != nullptr) ? c : new_col->caption;
        
        columns = xnrealloc(columns, ++ncolumns, sizeof(struct field_data_t *));
        columns[ncolumns - 1] = new_col;
    } else {
        printf("Field %d is already used.\n", f);
    }
}
 

This program counterpart basically does the same task but differently. The reorder of statements can help to catch the error sooner about if the field is already used. Plus, only makes the memory reallocation after ensuring the field can be used, i.e., after checking the field isn't being used yet. In the new version, it updates the caption only when it's not null, instead doing an attribution all the times. If the caption insert attempt comes to a reclaimed field it will feedback this situation with a respective warning with the field specific number, `f`.