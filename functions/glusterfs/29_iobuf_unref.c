iobuf_unref (struct iobuf *iobuf)
{
        int  ref = 0;

        GF_VALIDATE_OR_GOTO ("iobuf", iobuf, out);

        LOCK (&iobuf->lock);
        {
                __iobuf_unref (iobuf);
                ref = iobuf->ref;
        }
        UNLOCK (&iobuf->lock);

        if (!ref)
                iobuf_put (iobuf);

out:
        return;
}