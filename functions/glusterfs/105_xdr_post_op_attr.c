xdr_post_op_attr (XDR *xdrs, post_op_attr *objp)
{
	 if (!xdr_bool (xdrs, &objp->attributes_follow))
		 return FALSE;
	switch (objp->attributes_follow) {
	case TRUE:
		 if (!xdr_fattr3 (xdrs, &objp->post_op_attr_u.attributes))
			 return FALSE;
		break;
	case FALSE:
		break;
	default:
		return FALSE;
	}
	return TRUE;
}