int EC_POINT_set_affine_coordinates(const EC_GROUP *group, EC_POINT *point,
                                    const BIGNUM *x, const BIGNUM *y,
                                    BN_CTX *ctx)
{
    if (group->meth->point_set_affine_coordinates == NULL) {
        ERR_raise(ERR_LIB_EC, ERR_R_SHOULD_NOT_HAVE_BEEN_CALLED);
        return 0;
    }
    if (!ec_point_is_compat(point, group)) {
        ERR_raise(ERR_LIB_EC, EC_R_INCOMPATIBLE_OBJECTS);
        return 0;
    }
    if (!group->meth->point_set_affine_coordinates(group, point, x, y, ctx))
        return 0;

    if (EC_POINT_is_on_curve(group, point, ctx) <= 0) {
        ERR_raise(ERR_LIB_EC, EC_R_POINT_IS_NOT_ON_CURVE);
        return 0;
    }
    return 1;
}