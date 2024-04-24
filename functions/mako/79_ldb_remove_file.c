ldb_remove_file(const char *filename) {
  if (LDBIsWindowsNT()) {
    ldb_wide_t path;
    int rc = LDB_OK;

    if (!ldb_wide_import(&path, filename))
      return LDB_INVALID;

    if (!DeleteFileW(path.data))
      rc = LDB_WIN32_ERROR(GetLastError());

    ldb_wide_clear(&path);

    return rc;
  }

  if (!DeleteFileA(filename))
    return LDB_WIN32_ERROR(GetLastError());

  return LDB_OK;
}