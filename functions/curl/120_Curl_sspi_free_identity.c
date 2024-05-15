void Curl_sspi_free_identity(SEC_WINNT_AUTH_IDENTITY *identity)
{
  if(identity) {
    Curl_safefree(identity->User);
    Curl_safefree(identity->Password);
    Curl_safefree(identity->Domain);
  }
}