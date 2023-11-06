
/* Variant 1 */
void alloc_field_v1(int f, const char *c) {
    columns = xnrealloc (columns, ++ncolumns, sizeof(struct field_data_t *));
    struct field_data_t *new_col = &field_data[f];

    columns[ncolumns - 1] = new_col;

    if (c != NULL)
        new_col->caption = c;

    assert (!new_col->used);

    /* Mark field as used. */
    new_col->used = true;
}


/*  Variant 2 */
void alloc_field_v2(int f, const char *c) {
    struct field_data_t *new_col = &field_data[f];
    
    if (c != NULL)
        new_col->caption = c;

    assert (!new_col->used);
    
    columns = xnrealloc (columns, ++ncolumns, sizeof(new_col));
    columns[ncolumns - 1] = new_col;
    
    /* Mark field as used. */
    new_col->used = 1;
}

/*  Variant 3 */
void alloc_field_v3(int f, const char *c) {
    struct field_data_t** temp = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
    struct field_data_t* new_column = &field_data[f];
	
    if (c != NULL) {
        new_column->caption = c;
    }
	
    assert (new_column->used == false);
	
    temp[ncolumns - 1] = new_column;
	
    /* Mark field as used. */
    new_column->used = true;
}
