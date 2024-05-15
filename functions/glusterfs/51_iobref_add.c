iobref_add (struct iobref *iobref, struct iobuf *iobuf)
{
        int  ret = -EINVAL;

        GF_VALIDATE_OR_GOTO ("iobuf", iobref, out);
        GF_VALIDATE_OR_GOTO ("iobuf", iobuf, out);

        LOCK (&iobref->lock);
        {
                ret = __iobref_add (iobref, iobuf);
        }
        UNLOCK (&iobref->lock);

out:
        return ret;
}