compute_tag_length (size_t n)
{
  int needed = 0;

  if (n < 128)
    needed += 2; /* tag and one length byte */
  else if (n < 256)
    needed += 3; /* tag, number of length bytes, 1 length byte */
  else if (n < 65536)
    needed += 4; /* tag, number of length bytes, 2 length bytes */
  else
    {
      log_error ("object too larger to encode\n");
      return 0;
    }
  return needed;
}