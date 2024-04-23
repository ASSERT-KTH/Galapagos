uc_is_general_category (ucs4_t uc, uc_general_category_t category)
{
  if (category.generic)
    return category.lookup.lookup_fn (uc, category.bitmask);
  else
    return bitmap_lookup (category.lookup.table, uc);
}