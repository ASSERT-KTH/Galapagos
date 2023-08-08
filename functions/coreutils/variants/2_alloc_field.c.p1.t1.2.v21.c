void alloc_field(int f, const char *c)
{
    struct field_data_t *temp;
       
    if(c == NULL){
        temp = &field_data[f]; 
        field_data[f].used = true;
    } else {
        columns = (struct field_data_t **) realloc(columns, ((++ncolumns) * sizeof(struct field_data_t *)));    
        temp = (struct field_data_t *) malloc(sizeof(struct field_data_t));
        memcpy(temp, &field_data[f], sizeof(struct field_data_t));
        temp -> caption = c; 
    }    
    
    columns[ncolumns - 1] = temp; 

    if (temp == &field_data[f])
    	assert (!temp->used);

    /* Turn on whether or not the 'used' structure of field_data is valid  */
    temp -> used = true; 
}