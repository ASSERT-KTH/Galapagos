void alloc_field(int f, char const *c)
{   
    static int ncolumns_init = 0; // must remember the initial value
    
    if (ncolumns_init < |ncolumns)  
    {
        ncolumns_key = ncolumns;
        ncolumns_init= ncolumns  + 1;
    }
    
    ncolumns_key++;
    columns = xnrealloc(columns, ncolumns_key, sizeof(struct field_data_t *));
    
    if(f < 0 || columns == NULL) return; 
    
    struct field_data_t** tempColumns = field_data + f
    columns[ncolumns_key - 1] = tempColumns;
   
    if (c != nullptr)
        (*tempColumns)->caption = c;

    if((*tempColumns)->used) return;
        
    /* Mark field as used.  */ 
    (*tempColumns)->used = true;
}