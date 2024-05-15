iobref_ref (struct iobref *iobref)
{
        GF_VALIDATE_OR_GOTO ("iobuf", iobref, out);

        LOCK (&iobref->lock);
        {
                iobref->ref++;
        }
        UNLOCK (&iobref->lock);

out:
        return iobref;
}