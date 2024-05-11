keyid_from_pk (PKT_public_key *pk, u32 *keyid)
{
  u32 dummy_keyid[2];

  if (!keyid)
    keyid = dummy_keyid;

  if (!pk->fprlen)
    compute_fingerprint (pk);

  keyid[0] = pk->keyid[0];
  keyid[1] = pk->keyid[1];

  if (pk->fprlen == 32)
    return keyid[0];
  else
    return keyid[1];
}