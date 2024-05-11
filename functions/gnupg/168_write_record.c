write_record (ctrl_t ctrl, TRUSTREC *rec)
{
  int rc = tdbio_write_record (ctrl, rec);
  if (rc)
    {
      log_error(_("trust record %lu, type %d: write failed: %s\n"),
			    rec->recnum, rec->rectype, gpg_strerror (rc) );
      tdbio_invalid();
    }
}