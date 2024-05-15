_gcry_mpih_sub_n( mpi_ptr_t res_ptr, mpi_ptr_t s1_ptr,
				  mpi_ptr_t s2_ptr, mpi_size_t size)
{
  mpi_limb_t x, y, cy;
  mpi_size_t j;

  /* The loop counter and index J goes from -SIZE to -1.  This way
     the loop becomes faster.  */
  j = -size;

  /* Offset the base pointers to compensate for the negative indices.  */
  s1_ptr -= j;
  s2_ptr -= j;
  res_ptr -= j;

  cy = 0;
  do 
    {
      y = s2_ptr[j];
      x = s1_ptr[j];
      y += cy;		  /* add previous carry to subtrahend */
      cy = y < cy;		  /* get out carry from that addition */
      y = x - y;		  /* main subtract */
      cy += y > x;		  /* get out carry from the subtract, combine */
      res_ptr[j] = y;
    } 
  while( ++j );

  return cy;
}