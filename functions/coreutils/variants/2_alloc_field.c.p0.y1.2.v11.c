void alloc_field (int f, char const *c)
{
    ncolumns++;
    columns = realloc (columns, ncolumns * sizeof(struct field_data_t *));

    if (columns != NULL) {
        columns[ncolumns - 1] = &field_data[f];
        if (NULL != c)
            columns[ncolumns - 1]->caption = c;

        assert(0 == field_data[f].used);

        /* Mark field as used. */
        field_data[f].used = 1;
    } else {
        exit(-1);
    }
}