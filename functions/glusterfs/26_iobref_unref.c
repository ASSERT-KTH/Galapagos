iobref_unref (struct iobref *iobref)
{
        int ref = 0;

        GF_VALIDATE_OR_GOTO ("iobuf", iobref, out);

        LOCK (&iobref->lock);
        {
                ref = (--iobref->ref);
        }
        UNLOCK (&iobref->lock);

        if (!ref)
                iobref_destroy (iobref);

out:
        return;
}