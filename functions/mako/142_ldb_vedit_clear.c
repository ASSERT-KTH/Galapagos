ldb_vedit_clear(ldb_vedit_t *edit) {
  size_t i;

  for (i = 0; i < edit->compact_pointers.length; i++)
    ikey_entry_destroy(edit->compact_pointers.items[i]);

  for (i = 0; i < edit->new_files.length; i++)
    meta_entry_destroy(edit->new_files.items[i]);

  ldb_buffer_clear(&edit->comparator);
  ldb_vector_clear(&edit->compact_pointers);
  rb_set_clear(&edit->deleted_files, file_entry_destruct);
  ldb_vector_clear(&edit->new_files);
}