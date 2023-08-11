int compare(struct line const *a, struct line const *b)
{
  int comparison;
  int alength, blength;

  if(keylist)
  {
    comparison = keycompare(a, b);
    if(comparison || unique || stable)
      return comparison;
  }

  alength = a->length - 1;
  blength = b->length - 1;

  if(alength == 0)
    comparison = blength == 0 ? 0 : -1;
  else if(blength == 0)
    comparison = 1;
  else if(hard_LC_COLLATE)
    comparison = strcmp(b->text, a->text) == 0 ? 0 : 1;
  else
  {
    comparison = strncmp(a->text, b->text, alength < blength ? alength: blength);
    if(comparison == 0)
      comparison = (alength > blength ? 1: alength < blength ? -1 : 0);
  }

  return diff_reversed(comparison, reverse);
}