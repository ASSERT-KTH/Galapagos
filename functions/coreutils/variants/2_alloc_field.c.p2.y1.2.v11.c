alloc_field(int f, char const *c)
{
    ncolumns++;

    /* Resize buffer before using it */
    columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
    
    /* Initialize new field data */
    struct field_data_t d;
    d.used = true;

    if(c != nullptr)
        d.caption = c;
    
    /* Affirm field not used */
    affirm(!field_data[f].used);

    /* Update field data and reference in columns*/
    field_data[f] = d;
    columns[ncolumns - 1] = &field_data[f];    
}