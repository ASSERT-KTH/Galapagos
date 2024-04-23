canonicalize_filename_mode (const char *name, canonicalize_mode_t can_mode)
{
  struct realpath_bufs bufs;
  scratch_buffer_init (&bufs.rname);
  scratch_buffer_init (&bufs.extra);
  scratch_buffer_init (&bufs.link);
  char *result = canonicalize_filename_mode_stk (name, can_mode, &bufs);
  scratch_buffer_free (&bufs.link);
  scratch_buffer_free (&bufs.extra);
  scratch_buffer_free (&bufs.rname);
  return result;
}