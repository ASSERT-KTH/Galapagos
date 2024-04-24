BIO *BIO_push(BIO *b, BIO *bio)
{
    BIO *lb;

    if (b == NULL)
        return bio;
    lb = b;
    while (lb->next_bio != NULL)
        lb = lb->next_bio;
    lb->next_bio = bio;
    if (bio != NULL)
        bio->prev_bio = lb;
    /* called to do internal processing */
    BIO_ctrl(b, BIO_CTRL_PUSH, 0, lb);
    return b;
}