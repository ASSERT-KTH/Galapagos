void alloc_field (int f, char const *c) 
{
    ncolumns++;

    columns = (struct field_data_t **) realloc(columns, ncolumns * sizeof(struct field_data_t));

    if(columns != NULL) 
    {
        columns[ncolumns - 1] = &field_data[f];

        if (c != NULL) 
            columns[ncolumns - 1]->caption = c;
        else
            columns[ncolumns - 1]->caption = "";

        /* A condition check for whether field[f] is not used and then, marking it as used, true.*/
        if(!(field_data[f].used)) 
        {
            /* Marking the field as used.  */
            field_data[f].used = true;
        } 
        else 
        {
            printf("Field already in use.\n");
        }
    } 
    else 
    {
        printf("Memory allocation failed.\n");
    }
}