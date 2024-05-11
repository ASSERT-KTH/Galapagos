new_armor_context (void)
{
  armor_filter_context_t *afx;
  gpg_error_t err;

  afx = xcalloc (1, sizeof *afx);
  if (afx)
    {
      err = gcry_md_open (&afx->crc_md, GCRY_MD_CRC24_RFC2440, 0);
      if (err != 0)
	{
	  log_error ("gcry_md_open failed for GCRY_MD_CRC24_RFC2440: %s",
		    gpg_strerror (err));
	  xfree (afx);
	  return NULL;
	}

      afx->refcount = 1;
    }

  return afx;
}