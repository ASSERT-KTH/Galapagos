find_next_kbnode( KBNODE node, int pkttype )
{
    for( node=node->next ; node; node = node->next ) {
	if( !pkttype )
	    return node;
	else if( pkttype == PKT_USER_ID
		 && (	node->pkt->pkttype == PKT_PUBLIC_KEY
		     || node->pkt->pkttype == PKT_SECRET_KEY ) )
	    return NULL;
	else if( pkttype == PKT_SIGNATURE
		 && (	node->pkt->pkttype == PKT_USER_ID
		     || node->pkt->pkttype == PKT_PUBLIC_KEY
		     || node->pkt->pkttype == PKT_SECRET_KEY ) )
	    return NULL;
	else if( node->pkt->pkttype == pkttype )
	    return node;
    }
    return NULL;
}