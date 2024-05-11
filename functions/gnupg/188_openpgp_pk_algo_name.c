openpgp_pk_algo_name (pubkey_algo_t algo)
{
  switch (algo)
    {
    case PUBKEY_ALGO_RSA:
    case PUBKEY_ALGO_RSA_E:
    case PUBKEY_ALGO_RSA_S:     return "RSA";
    case PUBKEY_ALGO_ELGAMAL:
    case PUBKEY_ALGO_ELGAMAL_E: return "ELG";
    case PUBKEY_ALGO_DSA:       return "DSA";
    case PUBKEY_ALGO_ECDH:      return "ECDH";
    case PUBKEY_ALGO_ECDSA:     return "ECDSA";
    case PUBKEY_ALGO_EDDSA:     return "EDDSA";
    case PUBKEY_ALGO_KYBER:     return "Kyber";
    default: return "?";
    }
}