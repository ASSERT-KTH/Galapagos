The following code requests additional dynamic memory if the current memory allotted for 'columns' cannot accommodate the new field. However, this version of the code ensures that 'columns' remains sorted according to the 'f' field, from smallest to largest.


alloc_field(int f, char const *c)
{
    // Locate the position of insertion.
    int i = 0;
    while (i < ncolumns && f > field_data[*columns[i]].f) {
        i++;
    }

    // Allocate more memory.
    columns = xnrealloc(columns, ++ncolumns, sizeof(struct field_data_t *));

    // Shift subsequent columns, making way for new field data.
    for (int j = ncolumns - 1; j > i; j--) {
        columns[j] = columns[j - 1];
    }

    // Insert the new column.
    columns[i] = &field_data[f];

    // Check pointer not null.
    if(c != nullptr) {
       columns[i]->caption = c;
    }

    // Ensure field_data[f] hasn't been used.
    affirm(!field_data[f].used);

    // Mark field as used. 
    field_data[f].used = true;
}


This still calls the auxiliary 'xnrealloc' function to resize the dynamic 'columns' array as necessary. The structure 'field_data' and the global 'ncolumns' variable  also remain consistent with previous listings. A binary search for the insertion position instead of this linear pass-through could further monumentally improve efficiency, designed for larger sets of columns.