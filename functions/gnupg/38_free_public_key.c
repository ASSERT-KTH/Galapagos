free_public_key (PKT_public_key *pk)
{
  if (pk)
    {
      release_public_key_parts (pk);
      xfree(pk);
    }
}