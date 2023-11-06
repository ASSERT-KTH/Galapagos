// Variant 1: Replacing the function calls with actual implementations

void alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = realloc (columns, sizeof (struct field_data_t *) * ncolumns ); // replacing xnrealloc with realloc
  if (columns == NULL) exit(1);  // Adding error handling
  columns[ncolumns - 1] = &field_data[f];
  
  if (c != nullptr)
    columns[ncolumns - 1]->caption = c;

  assert (!field_data[f].used);  // Replacing affirm with assert

  field_data[f].used = true;
}

// Variant 2: Without any affirmations or assertions

void alloc_field(int f, char const *c)
{
    ncolumns++;
    columns = realloc(columns, ncolumns * sizeof(struct field_data_t *));
    if (columns)
    {
        columns[ncolumns - 1] = &field_data[f];
        if (c) 
        {
            columns[ncolumns - 1]->caption = c;
        }
        if(!field_data[f].used)
        {
          field_data[f].used = true;  
        }
    }
}

//Variant 3: Using array index instead of pointer

void alloc_field (int f, char const *c)
{
  ncolumns++;
  columns = (field_data_t **)realloc(columns, ncolumns * sizeof(struct field_data_t *));
  
  if (columns == NULL) exit(1);
  
  struct field_data_t* newFData = &field_data[f];
  columns[ncolumns-1] = newFData;
  
  assert (!newFData->used);  //Using new array

  /* Mark field as used.  */
  newFData->used = true;     //Keeping field in the used state
  
  /*Handling the caption of the field here as well */
  if(c)
    newFData->caption = c;
}

//Variant 4: Using parentheses around sizes in realloc(maximum readability)

void alloc_field(int f, char const *c)
{
    ncolumns++;
    columns = realloc(columns,( sizeof(struct field_data_t *) * ncolumns ));
      if(columns == NULL) exit(1);;

    struct field_data_t* currentField = &field_data[f];
    columns[ncolumns - 1] = currentField;

    if (!currentField->used)
   {
      currentField->used = true;    
   }
    
    if(c)
        currentField->caption = c;
}