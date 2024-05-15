void bdrv_delete(BlockDriverState *bs)
{
    assert(!bs->dev);
    assert(!bs->job);
    assert(!bs->in_use);

    /* remove from list, if necessary */
    bdrv_make_anon(bs);

    bdrv_close(bs);

    g_free(bs);
}