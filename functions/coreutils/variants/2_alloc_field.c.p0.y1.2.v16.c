void alloc_field(int f, const char *c) {
    columns = (struct field_data_t **) realloc(columns, (++ncolumns) * sizeof(struct field_data_t *));

    struct field_data_t* currentFieldData = &field_data[f];
    columns[ncolumns - 1] = currentFieldData;

    if (currentFieldData->used == false) {

        if(c != NULL)
            currentFieldData->caption = c;

        currentFieldData->used = true;
    }
}