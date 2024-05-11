release_kbnode( KBNODE n )
{
    KBNODE n2;

    while( n ) {
	n2 = n->next;
	if( !is_cloned_kbnode(n) ) {
            free_packet (n->pkt, NULL);
            xfree( n->pkt );
	}
	free_node( n );
	n = n2;
    }
}