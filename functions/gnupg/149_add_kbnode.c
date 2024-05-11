add_kbnode( KBNODE root, KBNODE node )
{
    KBNODE n1;

    for(n1=root; n1->next; n1 = n1->next)
	;
    n1->next = node;
}