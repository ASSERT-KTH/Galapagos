get_parameter (struct para_data_s *para, enum para_name key, int seq)
{
  struct para_data_s *r;

  for (r = para; r ; r = r->next)
    if ( r->key == key && !seq--)
      return r;
  return NULL;
}