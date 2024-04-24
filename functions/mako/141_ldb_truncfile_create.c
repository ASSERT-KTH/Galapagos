ldb_truncfile_create(const char *filename, ldb_wfile_t **file) {
  HANDLE handle = LDBCreateFile(filename,
                                GENERIC_WRITE,
                                0,
                                NULL,
                                CREATE_ALWAYS,
                                FILE_ATTRIBUTE_NORMAL,
                                NULL);

  if (handle == INVALID_HANDLE_VALUE)
    return LDB_WIN32_ERROR(GetLastError());

  *file = ldb_malloc(sizeof(ldb_wfile_t));

  ldb_wfile_init(*file, handle);

  return LDB_OK;
}