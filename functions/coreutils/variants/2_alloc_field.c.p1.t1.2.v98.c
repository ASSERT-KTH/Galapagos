Here is a variant of the function keeping its signature and major functionality tags. In this variant, it's easy to catch and debug if the condition of 'field_data[f].used = false' is not met. It will also return a useful error code to where the function might be called in the program.


#include <stdlib.h>

#define FIELD_DATA_ERROR_CODE -1

int alloc_field(int f, char const *c) {
    if (field_data[f].used) {
        fprintf(stderr, "Error: field already in use\n");
        return FIELD_DATA_ERROR_CODE; // returning an error code
    }
  
    ncolumns++;
    columns = (field_data_t**)realloc(columns, ncolumns * sizeof(struct field_data_t*));

    if (!columns) {
        fprintf(stderr, "Error: could not allocate memory for columns\n");
        return FIELD_DATA_ERROR_CODE; // Can't allocate more memory for column. System out of memory
    }

    columns[ncolumns - 1] = &field_data[f];

    if (c != NULL) {
        columns[ncolumns - 1]->caption = c;
    }

    /* Mark field as used.  */
    field_data[f].used = true;

    return 0; // operation successful.
}


All error checks may not be needed depending on how guardedly we assume that the function would be used. However, it significantly improves the stability as it catches runtime errors. Please remember to replace 'field_data_t' to the correct struct name as it's generic in the above code.