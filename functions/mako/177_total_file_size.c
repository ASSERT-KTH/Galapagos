total_file_size(const ldb_vector_t *files) {
  int64_t sum = 0;
  size_t i;

  for (i = 0; i < files->length; i++) {
    const ldb_filemeta_t *f = files->items[i];

    sum += f->file_size;
  }

  return sum;
}