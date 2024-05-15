cursor_t cursor_create(size_t size)
{
  cursor_t cursor;
  cursor.buf = (char*)malloc(size);
  cursor.size = size;
  cursor.pos = 0;
  FUZZ_ASSERT(cursor.buf);
  return cursor;
}