get_inv_recpsgnr_code (gpg_error_t err)
{
  const char *errstr;

  switch (gpg_err_code (err))
    {
    case GPG_ERR_NO_PUBKEY:       errstr = "1"; break;
    case GPG_ERR_AMBIGUOUS_NAME:  errstr = "2"; break;
    case GPG_ERR_WRONG_KEY_USAGE: errstr = "3"; break;
    case GPG_ERR_CERT_REVOKED:    errstr = "4"; break;
    case GPG_ERR_CERT_EXPIRED:    errstr = "5"; break;
    case GPG_ERR_NO_CRL_KNOWN:
    case GPG_ERR_INV_CRL_OBJ:     errstr = "6"; break;
    case GPG_ERR_CRL_TOO_OLD:     errstr = "7"; break;
    case GPG_ERR_NO_POLICY_MATCH: errstr = "8"; break;

    case GPG_ERR_UNUSABLE_SECKEY:
    case GPG_ERR_NO_SECKEY:       errstr = "9"; break;

    case GPG_ERR_NOT_TRUSTED:     errstr = "10"; break;
    case GPG_ERR_MISSING_CERT:    errstr = "11"; break;
    case GPG_ERR_MISSING_ISSUER_CERT: errstr = "12"; break;
    default:                      errstr = "0"; break;
    }

  return errstr;
}