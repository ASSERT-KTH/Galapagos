
alloc_field(int f, char const *c)
{
    /* Similar procedure of incrementing `ncolumns` and reallocating `columns` */
    if (c != nullptr)
    {
        columns = xnrealloc (columns, ncolumns+1, sizeof (struct field_data_t *));
        ncolumns++;
    }
    else
    {
        columns = xnrealloc (columns, ncolumns, sizeof (struct field_data_t *));
    }
  
    columns[ncolumns - 1] = &field_data[f];
  
    /* Using ternary operator instead of simple `if` condition for `caption` assignment */
    columns[ncolumns - 1]->caption = (c != nullptr) ? c : columns[ncolumns - 1]->caption;
  
    /* Reversed affirmation check order - first mark the field as used, then affirm it */
    field_data[f].used = true;
  
    affirm (field_data[f].used);
}
