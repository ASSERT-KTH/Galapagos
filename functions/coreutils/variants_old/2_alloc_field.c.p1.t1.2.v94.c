void alloc_field(int f, char const* c) {
    ncolumns++;
    columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t*));

    field_data[f].used = true;  // Move this line to before setting the caption 

    columns[ncolumns - 1] = &field_data[f];
    if (c != nullptr)
        columns[ncolumns - 1]->caption = c;

    affirm(field_data[f].used);
}