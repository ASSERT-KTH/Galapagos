Transformed variant #1: Code brushing

alloc_field(int field_index, char const *capt)
{
    ++ncolumns;
    columns = xnrealloc (columns, ncolumns, sizeof(*columns));
    columns[ncolumns - 1] = &field_data[field_index];

  if (capt)
    columns[ncolumns - 1]->caption = capt;
  
  assert(!field_data[field_index].used);

  /* field marked as used */
  field_data[field_index].used = true;
}


Transformed variant #2: Use ternary operators

alloc_field (int fieldIndx, char const *capt)
{
  ncolumns++;
  columns = xnrealloc(columns, ncolumns, sizeof(*columns));
  columns[ncolumns - 1] = &field_data[fieldIndx];
  columns[ncolumns - 1]->caption = (capt != nullptr) ? capt : columns[ncolumns - 1]->caption;

  assert(!field_data[fieldIndx].used);

  /* field has been marked as used */
  field_data[fieldIndx].used = (field_data[fieldIndx].used == false) ? true : field_data[fieldIndx].used;  
}


Transformed variant #3: Minor refactoring

alloc_field(int fieldId, char const *descrip)
{
    struct field_data_t * current;

    ncolumns++;
    columns = xnrealloc(columns, ncolumns, sizeof(current));
    current = &field_data[fieldId];
   
    columns[ncolumns - 1] = current;
    
    if(descrip != nullptr)
        current->caption = descrip;
    
    assert(!(current->used));
    
    /* Mark as used */
    current->used = true;
}
