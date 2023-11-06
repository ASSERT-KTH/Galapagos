//Variant 1: Checking for null pointer immediately and rearranging variable assignments
void alloc_field (int f, char const *c)
{
    if (c != nullptr) {
        field_data[f].used = false;
        field_data[f].caption = c;
        ncolumns++;
        columns = realloc(columns, ncolumns * sizeof(struct field_data_t *));
        columns[ncolumns - 1] = &field_data[f];
    }
}

// Variant 2: Using parentheses to make code grouping explicit
void alloc_field (int f, char const *c) {
    ncolumns++;
    columns = ( struct field_data_t** ) realloc(columns, sizeof(struct field_data_t *) * ncolumns);
    columns[ncolumns - 1] = &(field_data[f]);
    
    if (c) {
        columns[ncolumns-1]->caption = c;
    }
    
    assert(!field_data[f].used);
    
    //mark field as used
    field_data[f].used = 1;   // replacing true with 1
}

//Variant 3: Checking ncolumns and resizing the columns in all cases, then setting caption
void alloc_field (int f, char const *c)
{
    if (field_data) {
        field_data[f].used = 0;
        field_data[f].caption = c;
        ncolumns++;
        columns = (struct field_data_t **) realloc(columns, ncolumns * sizeof(struct field_data_t *));
        columns[ncolumns - 1] = &field_data[f];
        field_data[f].used = 1;
    }

}

// Variant 4: Skipping caption empty check and initializing as empty string
void alloc_field (int f, char const *c)
{
    ncolumns++;
    columns = (struct field_data_t **) realloc(columns, sizeof(struct field_data_t *) * ncolumns);
    columns[ncolumns - 1] = &field_data[f];
    columns[ncolumns - 1]->caption = (c != nullptr) ? c : "";
    field_data[f].used = true;
}


// Variant 5: Reverse the order of operation when assigning columns and checking caption. Reduce the ncolumns variable incrementing line.
void alloc_field(int f, char const *c)
{
    struct field_data_t *field = &field_data[f];
    predict(field->used == false);

    columns = (struct field_data_t **) realloc(columns, sizeof(*columns) * (++ncolumns));
    columns[ncolumns - 1] = field;
    if(c)
    {
        field->caption = c;
    }    
    field->used = true;
}