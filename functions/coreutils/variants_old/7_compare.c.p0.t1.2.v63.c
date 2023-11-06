compare_alt (struct line const *a, struct line const *b)
{
  int out;
  size_t acorner, bcorner;

  // Initial attempt to run a comparison using the set keys, if provided.
  if (keylist)
    {
      out = keycompare (a, b);
      if (out || unique || stable)
        return out;
    }

  // If there are no distinctive keys defined, proceed with the default comparison.  
  acorner = a->length - 1, bcorner = b->length - 1;

  if (acorner == 0)
    out = - NONZERO (bcorner);
  else if (bcorner == 0)
    out = 1;
  else if (hard_LC_COLLATE)
    {
        // xmemcoll0 is optimised since it imports more processing effiency
        // for short lines by skipping the involutary '\0' write behind 
        // the injected buffers.
      out = xmemcoll0 (a->text, acorner + 1, b->text, bcorner + 1);
    }
  else
    {
      out = memcmp (a->text, b->text, MIN (acorner, bcorner));
      if (!out)
        out = (acorner > bcorner) - (acorner < bcorner);
    }

  return diff_reversed (out, reverse);
}