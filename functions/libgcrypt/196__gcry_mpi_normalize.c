_gcry_mpi_normalize( gcry_mpi_t a )
{
    if( mpi_is_opaque(a) )
	return;

    for( ; a->nlimbs && !a->d[a->nlimbs-1]; a->nlimbs-- )
	;
}