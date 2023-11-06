Variant 1:

alloc_field (int f, char const *c)
{   
    columns = xnrealloc (columns, ++ncolumns, sizeof (struct field_data_t *));
    struct field_data_t *new_field = &field_data[f];

    columns[ncolumns - 1] = new_field;
    if (c != nullptr)
        new_field->caption = c;

    affirm (!new_field->used); 
    new_field->used = true;
}


Variant 2: 

alloc_field (int f, char const *c)
{
    ncolumns++;
    struct field_data_t *temp = &field_data[f];
    
    columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    columns[ncolumns - 1] = temp; 
    
    affirm (!temp->used);
    temp->used = true;
    
    if (c != nullptr)
      temp->caption = c;
}
 

Variant 3:

alloc_field (int f, char const *c)
{
   ncolumns++;
   columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));

   assert(!field_data[f].used);
   
   /* Mark field as used.  */
   field_data[f].used = true;
   
   columns[ncolumns - 1] = &field_data[f];

   if (c != nullptr)
      columns[ncolumns - 1]->caption = c;
}
 

Variant 4:
 
alloc_field (int f, char const *c)
{
   struct field_data_t **columns_copy = xnrealloc (columns, ncolumns + 1, sizeof (struct field_data_t *));
   
   assert(!field_data[f].used);
   
   /* Mark field as used.  */
   field_data[f].used = true;

   columns = columns_copy;
   columns[ncolumns++] = &field_data[f];

   if (c != nullptr)
      columns[ncolumns - 1]->caption = c;
}
