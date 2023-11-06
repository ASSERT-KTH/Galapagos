#include <stdlib.h>
#include <string.h>

// Assuming `field_data` and `ncolumns` are global variables

alloc_field (int f, char const *c)
{
  // Check field as used and abort if already used
  if(field_data[f].used) 
    return;

  field_data[f].used = true;

  struct field_data_t **new_columns = malloc((ncolumns + 1) * sizeof(*columns));
  if(new_columns != NULL) {
    if(columns != NULL && ncolumns>0) {
      memcpy(new_columns, columns, ncolumns * sizeof(*columns));
      free(columns);
    }

    new_columns[ncolumns] = &field_data[f];

    if (c != NULL)
      new_columns[ncolumns]->caption = c;
      
    columns = new_columns;
    ncolumns++;
  }
}