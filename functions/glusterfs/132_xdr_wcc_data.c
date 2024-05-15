xdr_wcc_data (XDR *xdrs, wcc_data *objp)
{
	 if (!xdr_pre_op_attr (xdrs, &objp->before))
		 return FALSE;
	 if (!xdr_post_op_attr (xdrs, &objp->after))
		 return FALSE;
	return TRUE;
}