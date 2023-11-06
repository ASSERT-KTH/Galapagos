Version 1:

void ldb_buffer_clear(ldb_buffer_t *z) {
    if (z->alloc > 0) {
        ldb_free(z->data);
        z->data = NULL;
    }
    z->size = 0;
    z->alloc = 0;
}


Version 2:

void ldb_buffer_clear(ldb_buffer_t *z) {
    if (z != NULL) {
        if (z->alloc > 0)
            ldb_free(z->data);
        
        z->data = NULL;
        z->size = 0;
        z->alloc = 0;
    }
}
 

Version 3:

void ldb_buffer_clear(ldb_buffer_t *z) {
    if (z && z->alloc > 0)
        ldb_free(z->data);
    
    if (z) {
        z->data = NULL;
        z->size = 0;
        z->alloc = 0;
    }
}


Version 4:

void ldb_buffer_clear(ldb_buffer_t *z) {
    if (z->alloc > 0) {
        ldb_free(z->data);
        z->data = NULL;
        z->alloc = 0;
    }
    
    if (z)
        z->size = 0;
}
