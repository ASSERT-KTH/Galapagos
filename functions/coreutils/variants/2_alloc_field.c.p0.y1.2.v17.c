
alloc_field (int f,char const *c)
{
columns = (struct field_data_t **) 
            realloc(columns, sizeof(struct field_data_t *) * (ncolumns + 1));
ncolumns++;
columns[ncolumns - 1] = &field_data[f];

if (NULL != c)
{
    columns[ncolumns - 1]->caption = c;
}
assert (field_data[f].used == false);
field_data[f].used = true;
}
