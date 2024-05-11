find_kbnode( KBNODE node, int pkttype )
{
    for( ; node; node = node->next ) {
	if( node->pkt->pkttype == pkttype )
	    return node;
    }
    return NULL;
}