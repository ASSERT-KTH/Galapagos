TCHAR *Curl_auth_build_spn(const char *service, const char *host,
                           const char *realm)
{
  char *utf8_spn = NULL;
  TCHAR *tchar_spn = NULL;
  TCHAR *dupe_tchar_spn = NULL;

  (void) realm;

  /* Note: We could use DsMakeSPN() or DsClientMakeSpnForTargetServer() rather
     than doing this ourselves but the first is only available in Windows XP
     and Windows Server 2003 and the latter is only available in Windows 2000
     but not Windows95/98/ME or Windows NT4.0 unless the Active Directory
     Client Extensions are installed. As such it is far simpler for us to
     formulate the SPN instead. */

  /* Generate our UTF8 based SPN */
  utf8_spn = aprintf("%s/%s", service, host);
  if(!utf8_spn)
    return NULL;

  /* Allocate and return a TCHAR based SPN. Since curlx_convert_UTF8_to_tchar
     must be freed by curlx_unicodefree we'll dupe the result so that the
     pointer this function returns can be normally free'd. */
  tchar_spn = curlx_convert_UTF8_to_tchar(utf8_spn);
  free(utf8_spn);
  if(!tchar_spn)
    return NULL;
  dupe_tchar_spn = _tcsdup(tchar_spn);
  curlx_unicodefree(tchar_spn);
  return dupe_tchar_spn;
}