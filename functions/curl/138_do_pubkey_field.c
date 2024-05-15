static CURLcode do_pubkey_field(struct Curl_easy *data, int certnum,
                                const char *label,
                                struct Curl_asn1Element *elem)
{
  CURLcode result;
  struct dynbuf out;

  Curl_dyn_init(&out, MAX_X509_STR);

  /* Generate a certificate information record for the public key. */

  result = ASN1tostr(&out, elem, 0);
  if(!result) {
    if(data->set.ssl.certinfo)
      result = ssl_push_certinfo_dyn(data, certnum, label, &out);
    Curl_dyn_free(&out);
  }
  return result;
}