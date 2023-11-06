Variant 1: Changing the order of sequence

alloc_field(int f, char const *c) {
    if (c != nullptr)
        field_data[f].caption = c;
    
    ncolumns++;
    columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    
    affirm(!field_data[f].used);

    field_data[f].used = true;
}


Variant 2: Including the condition to realloc only on used field

alloc_field(int f, char const *c) {
    affirm(!field_data[f].used);
    if (!field_data[f].used) {
        ncolumns++;
        columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
        columns[ncolumns - 1] = &field_data[f];
        if (c != nullptr) 
            columns[ncolumns - 1]->caption = c;

        field_data[f].used = true;
    }
}


Variant 3: Using a temporary variable to store the new column info

alloc_field(int f, char const *c) {
    struct field_data_t *temp = xnrealloc(columns, ncolumns+1, sizeof(struct field_data_t *));
    if (temp != nullptr) {
        ncolumns++;
        columns = temp;
        columns[ncolumns - 1] = &field_data[f];
        if (c != nullptr)
            columns[ncolumns - 1]->caption = c;
        affirm(!field_data[f].used);
        field_data[f].used = true;
    }
}


Variant 4: Expanding if condition for improved readability

alloc_field(int f, char const *c) {
    ncolumns++;
    columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
    {
        columns[ncolumns - 1]->caption = c;
    }

    affirm(!field_data[f].used);

    field_data[f].used = true;
}


Variant 5: Flattening the if condition

alloc_field(int f, char const *c) {
    ncolumns++;
    columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
    columns[ncolumns - 1] = &field_data[f];
    
    affirm(!field_data[f].used);
    
    if (c)
    {
        columns[ncolumns - 1]->caption = c;
    }

    field_data[f].used = true;
}
