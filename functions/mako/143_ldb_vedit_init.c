ldb_vedit_init(ldb_vedit_t *edit) {
  ldb_buffer_init(&edit->comparator);

  edit->log_number = 0;
  edit->prev_log_number = 0;
  edit->last_sequence = 0;
  edit->next_file_number = 0;
  edit->has_comparator = 0;
  edit->has_log_number = 0;
  edit->has_prev_log_number = 0;
  edit->has_next_file_number = 0;
  edit->has_last_sequence = 0;

  ldb_vector_init(&edit->compact_pointers);
  rb_set_init(&edit->deleted_files, file_entry_compare, NULL);
  ldb_vector_init(&edit->new_files);
}