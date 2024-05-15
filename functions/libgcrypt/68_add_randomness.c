add_randomness (const void *buffer, size_t length, enum random_origins origin)
{
  const unsigned char *p = buffer;
  size_t count = 0;

  gcry_assert (pool_is_locked);

  rndstats.addbytes += length;
  rndstats.naddbytes++;
  while (length-- )
    {
      rndpool[pool_writepos++] ^= *p++;
      count++;
      if (pool_writepos >= POOLSIZE )
        {
          /* It is possible that we are invoked before the pool is
             filled using an unreliable origin of entropy, for example
             the fast random poll.  To avoid flagging the pool as
             filled in this case, we track the initial filling state
             separately.  See also the remarks about the seed file. */
          if (origin >= RANDOM_ORIGIN_SLOWPOLL && !pool_filled)
            {
              pool_filled_counter += count;
              count = 0;
              if (pool_filled_counter >= POOLSIZE)
                pool_filled = 1;
            }
          pool_writepos = 0;
          mix_pool(rndpool); rndstats.mixrnd++;
          just_mixed = !length;
	}
    }
}