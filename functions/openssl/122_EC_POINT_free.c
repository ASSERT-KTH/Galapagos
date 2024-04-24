void EC_POINT_free(EC_POINT *point)
{
    if (point == NULL)
        return;

    if (point->meth->point_finish != 0)
        point->meth->point_finish(point);
    OPENSSL_free(point);
}