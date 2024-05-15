void Curl_auth_cleanup_ntlm(struct ntlmdata *ntlm)
{
  /* Free the target info */
  Curl_safefree(ntlm->target_info);

  /* Reset any variables */
  ntlm->target_info_len = 0;
}