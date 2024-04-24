void BIO_free_all(BIO *bio)
{
    BIO *b;
    int ref;

    while (bio != NULL) {
        b = bio;
        ref = b->references;
        bio = bio->next_bio;
        BIO_free(b);
        /* Since ref count > 1, don't free anyone else. */
        if (ref > 1)
            break;
    }
}