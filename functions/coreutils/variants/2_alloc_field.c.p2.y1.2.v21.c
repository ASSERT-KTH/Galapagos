alloc_field (int f, char const *c)
{
    struct field_data_t *field_col = &field_data[f];
    affirm (!field_col->used);

    field_col->used = true;

    columns = (struct field_data_t **)realloc(columns, (++ncolumns) * sizeof(struct field_data_t *));
    columns[ncolumns - 1] = field_col;
    
    if (c)
      field_col->caption = c;
}