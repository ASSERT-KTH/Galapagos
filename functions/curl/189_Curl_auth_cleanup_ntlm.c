void Curl_auth_cleanup_ntlm(struct ntlmdata *ntlm)
{
  /* Free our security context */
  if(ntlm->context) {
    s_pSecFn->DeleteSecurityContext(ntlm->context);
    free(ntlm->context);
    ntlm->context = NULL;
  }

  /* Free our credentials handle */
  if(ntlm->credentials) {
    s_pSecFn->FreeCredentialsHandle(ntlm->credentials);
    free(ntlm->credentials);
    ntlm->credentials = NULL;
  }

  /* Free our identity */
  Curl_sspi_free_identity(ntlm->p_identity);
  ntlm->p_identity = NULL;

  /* Free the input and output tokens */
  Curl_safefree(ntlm->input_token);
  Curl_safefree(ntlm->output_token);

  /* Reset any variables */
  ntlm->token_max = 0;

  Curl_safefree(ntlm->spn);
}