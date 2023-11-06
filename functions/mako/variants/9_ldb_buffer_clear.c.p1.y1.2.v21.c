Variant 1:

void ldb_buffer_clear(ldb_buffer_t *z) 
{
  if (z == NULL) return;

  ldb_free(z->data);

  z->data = NULL;
  z->size = z->alloc = 0;
}


Variant 2:

void ldb_buffer_clear(ldb_buffer_t *z) 
{
  if (z == NULL) {
    return;
  }

  if (NULL != z->data)
  {
    ldb_free(z->data);
  }

  z->data = NULL;
  z->size = z->alloc = 0;
}


Variant 3:

void ldb_buffer_clear(ldb_buffer_t *z) 
{
  if (!z || !z->data) return;

  ldb_free(z->data);

  z->data = NULL;
  z->size = z->alloc = 0;
}


Variant 4:

void ldb_buffer_clear(ldb_buffer_t *z) 
{
  if (z != NULL) 
  {
    if (z->alloc > 0)
    {
      ldb_free(z->data);
    }

    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}


Variant 5:

void ldb_buffer_clear(ldb_buffer_t *z) 
{
  if (z->$alloc > 0) 
  {
    ldb_free(z->$data);
    z->data = NULL;
    z->size = 0;
    z->alloc = 0;
  }
}
