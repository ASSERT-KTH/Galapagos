openpgp_cipher_algo_name (cipher_algo_t algo)
{
  switch (algo)
    {
    case CIPHER_ALGO_IDEA:        return "IDEA";
    case CIPHER_ALGO_3DES:	  return "3DES";
    case CIPHER_ALGO_CAST5:	  return "CAST5";
    case CIPHER_ALGO_BLOWFISH:    return "BLOWFISH";
    case CIPHER_ALGO_AES:         return "AES";
    case CIPHER_ALGO_AES192:      return "AES192";
    case CIPHER_ALGO_AES256:      return "AES256";
    case CIPHER_ALGO_TWOFISH:     return "TWOFISH";
    case CIPHER_ALGO_CAMELLIA128: return "CAMELLIA128";
    case CIPHER_ALGO_CAMELLIA192: return "CAMELLIA192";
    case CIPHER_ALGO_CAMELLIA256: return "CAMELLIA256";
    case CIPHER_ALGO_NONE:
    default: return "?";
    }
}