nfs3_stat_to_post_op_attr (struct iatt *buf)
{
        post_op_attr    attr = {0, };
        if (!buf)
                return attr;

        /* Some performance translators return zero-filled stats when they
         * do not have up-to-date attributes. Need to handle this by not
         * returning these zeroed out attrs.
         */
        attr.attributes_follow = FALSE;
        if (nfs_zero_filled_stat (buf))
                goto out;

        attr.post_op_attr_u.attributes = nfs3_stat_to_fattr3 (buf);
        attr.attributes_follow = TRUE;

out:
        return attr;
}