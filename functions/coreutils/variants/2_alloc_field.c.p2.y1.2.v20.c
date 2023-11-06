alloc_field (int f, char const *c)
{
    struct field_data_t *new_field;
    columns = (struct field_data_t **) realloc(columns, sizeof(struct field_data_t*) * (++ncolumns));  

    if (columns == nullptr)
        return; // If the request fails, the function early exits.
          
    new_field = &field_data[f];

    if(!new_field->used) // If it's not being used, then allocates the respective memory.
    {
        new_field->used = true;  
        new_field->caption = (c != nullptr) ? c : nullptr; 
        columns[ncolumns - 1] = new_field;
    }
}