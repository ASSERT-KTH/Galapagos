Here is a variant of the original function that changes the behavior while maintaining the original functionality:


void alloc_field(int f, char const *c)
{
    static struct field_data_t *new_field_data = NULL;
    
    if (new_field_data != NULL)
    {
        ncolumns++;
        columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
        columns[ncolumns - 1] = &new_field_data[f];
        if (c != nullptr)
            columns[ncolumns - 1]->caption = c;

        affirm(!new_field_data[f].used);

        /* Mark field as used */
        new_field_data[f].used = true;
    }
    else
    {
        ncolumns++;
        columns = xnrealloc(columns, ncolumns, sizeof(struct field_data_t *));
        columns[ncolumns - 1] = &field_data[f];
        
        if (c != nullptr)
            columns[ncolumns - 1]->caption = c;

        affirm(!field_data[f].used);

        /* Copy field_data to new_field_data */
        new_field_data = malloc(ncolumns * sizeof(struct field_data_t));
        memcpy(new_field_data, field_data, ncolumns * sizeof(struct field_data_t));       

        /* Mark field as used */
        field_data[f].used = true;
    }
}


This variant function creates a static pointer `new_field_data`. On the first call, it behaves exactly like the original. However, on subsequent call it uses `new_field_data` in place of `field_data`, even if the content within `fields_data` may change (due to ‘used’ fields being different). Also the variant has an additional layer of copying functionality related to the fields data and check for any newly allocated space for further implementation.
However, it could lead to over-consumption of memory over time since `new_field_data` is static and therefore not deallocated after function exit that again will depend on the original requirement and upon further utilization or manipulation that requires this specific functionality. 
The function still fits with the purpose of allocating multiple 'columns', setting field descriptions and affirming if a column is not already utilized according its caption and tagging its utilization.