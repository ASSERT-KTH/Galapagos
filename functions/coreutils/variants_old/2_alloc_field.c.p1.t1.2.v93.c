Here's a variant that encapsulated further functionality:


alloc_field (int f, char const *c)
{
  if(f < 0)
    return;

  if(!field_data) {
    field_data = (struct field_data_t *)malloc(sizeof(field_data_t));
  }
  else{
      field_data = (struct field_data_t*)realloc(field_data, (f + 1) * sizeof(struct field_data_t));
  }

  if (!field_data)
    exit(EXIT_FAILURE);

  ncolumns++;
  columns = (struct field_data_t **)realloc(columns, ncolumns * sizeof (struct field_data_t *));

  if (!columns)
    exit(EXIT_FAILURE);

  columns[ncolumns - 1] = &field_data[f];
  assert(NULL != columns[ncolumns - 1]); 

  if (c != nullptr && strlen(c) > 0)
    strcpy( columns[ncolumns - 1]->caption , c );

  assert(false == field_data[f].used);

  /* Mark field as used. This field can be used hereafter for assignment. */
  field_data[f].used = true;
  column[ncolumns - 1] = f;
   
  assert(true == field_data[column[ncolumns -1]].used);
}


Let's examine the changes:

In case the invoked field does not exist, it creates that particular field and, if needed, expands the memory block pointed by the array of field.
Also, in place of if the code block uses assert for program robustness against possible nullptr exceptions.

An extra check has been added in case caption c parameter string has nonzero length, and appropriate caption string is then copied to field's caption. Manual control statements are replaced with standard calloc/malloc + realloc calls improving readability . 

Checking assertions after adequate memory allocation and after marking fields as `used` ensures robust field existence before and after corresponding assignments.
