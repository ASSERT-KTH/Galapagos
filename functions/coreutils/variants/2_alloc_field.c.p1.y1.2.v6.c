
alloc_field_v1 (int f, char const* c)
{
   ncolumns++;
   columns = (struct field_data_t**) realloc (columns, ncolumns * sizeof(struct field_data_t*));
   columns[ncolumns - 1] = field_data + f;

   if (c != NULL)
      (columns[ncolumns - 1]) -> caption = c;

   assert (!(field_data[f].used));

   /* Mark field as used.  */
   field_data[f].used = 1;
}

alloc_field_v2(int f_p, const char *c_p)  
{  
    ncolumns = ncolumns + 1;  
    columns = (struct field_data_t **) realloc(columns, ncolumns * sizeof(struct field_data_t *));  
    *(columns + ncolumns - 1) = &field_data[f_p];
  
    if (c_p != NULL)
        columns[ncolumns - 1] -> caption = c_p;

    assert (field_data[f_p].used == 0);

    /* mark the field as used */

    field_data[f_p].used = true;
}

alloc_field_v3(int f_i, const char *c_i) 
{  
    ncolumns++;  
    columns = (struct field_data_t**)realloc(columns, ncolumns * sizeof(struct field_data_t*));  
    *(columns + ncolumns - 1) = field_data + f_i;
  
    if (c_i)
        (*(columns + ncolumns - 1)) -> caption = c_i;

    assert (field_data[f_i].used == false);
    
    /* set field to be used  */
    field_data[f_i].used = true;
}
