Variant 1:

void alloc_field_alternative_1(int f, char const *c)
{
    ncolumns++;

    columns = (struct field_data_t **)realloc(columns, sizeof(*columns) * ncolumns);
    assert(columns != NULL);

    columns[ncolumns - 1] = &field_data[f];

    if (c != NULL)
    {
        columns[ncolumns - 1]->caption = c;
    }

    assert(!field_data[f].used);

    field_data[f].used = 1;
}

Note: In this variant, we use alternative function realloc for reallocation memory and then checks if return value is NULL or not using assert function.

Variant 2:

void alloc_field_alternative_2(int f, char const *c) 
{
    columns = xnrealloc(columns, ++ncolumns, sizeof (struct field_data_t *));
    
    if (!columns) exit(1);  /* terminate the program if realloc failed*/

    columns[ncolumns - 1] = &field_data[f];

    if (c)
    {
        cells[ncolumns - 1]->caption = c;
    }

    if(field_data[f].used) 
        exit(1);  /* terminate if the field is already used*/

    /* Mark field as used.  */
    field_data[f].used = true;
}

Note: In this variant instead of using "affirm", we now use just a simple "if".

Variant 3: 

alloc_field_alternative_3(int f, char const *c)
{
    ncolumns++;
    columns=(struct field_data_t **)realloc(columns,sizeof(struct field_data_t *)*ncolumns);
   
    if(columns == NULL) { // If malloc is unable of reserving requested storage terminate the program
        perror("Error allocating memory");
        exit(0);
    }
  
    columns[ncolumns - 1]= &field_data[f];
    if (c)
        columns[ncolumns - 1]->caption = c;

    if(field_data[f].used) {
        perror("Field is already used.");
        exit(EXIT_FAILURE);
    }

    /* Mark field as used.  */
    field_data[f].used = true;
}

This variant handles memory allocation errors and terminates the program when the field is already used.