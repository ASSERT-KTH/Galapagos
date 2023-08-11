void alloc_field(int f, char const *c)
{
    columns = (struct field_data_t**)realloc(columns, (++ncolumns) * sizeof (struct field_data_t *));
    struct field_data_t *newFieldData = &field_data[f];

    newFieldData->used = true;

    if (c != nullptr)
        newFieldData->caption = c;

    columns[ncolumns - 1] = newFieldData;
}