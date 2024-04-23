uc_joining_group_name (int joining_group)
{
  if (joining_group >= 0
      && joining_group < sizeof (joining_group_index) / sizeof (joining_group_index[0]))
    return joining_group_stringpool + joining_group_index[joining_group];
  return NULL;
}