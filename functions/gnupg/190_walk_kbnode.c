walk_kbnode( KBNODE root, KBNODE *context, int all )
{
    KBNODE n;

    do {
	if( !*context ) {
	    *context = root;
	    n = root;
	}
	else {
	    n = (*context)->next;
	    *context = n;
	}
    } while( !all && n && is_deleted_kbnode(n) );

    return n;
}