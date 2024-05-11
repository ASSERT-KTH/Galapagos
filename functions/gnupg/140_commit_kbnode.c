commit_kbnode( KBNODE *root )
{
    KBNODE n, nl;
    int changed = 0;

    for( n = *root, nl=NULL; n; n = nl->next ) {
	if( is_deleted_kbnode(n) ) {
	    if( n == *root )
		*root = nl = n->next;
	    else
		nl->next = n->next;
	    if( !is_cloned_kbnode(n) ) {
                free_packet (n->pkt, NULL);
		xfree( n->pkt );
	    }
	    free_node( n );
	    changed = 1;
	}
	else
	    nl = n;
    }
    return changed;
}