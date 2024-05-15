_libssh2_wincng_ecdsa_decode_uncompressed_point(
    IN const unsigned char *encoded_point,
    IN size_t encoded_point_len,
    OUT _libssh2_ecdsa_point *point)
{
    unsigned int curve;

    if(!point) {
        return LIBSSH2_ERROR_INVAL;
    }

    /* Verify that the point uses uncompressed format */
    if(encoded_point_len == 0 || encoded_point[0] != 4) {
        return LIBSSH2_ERROR_INVAL;
    }

    for(curve = 0; curve < ARRAY_SIZE(_wincng_ecdsa_algorithms); curve++) {
        if(_wincng_ecdsa_algorithms[curve].point_length ==
            (encoded_point_len - 1) / 2) {

            point->curve = curve;

            point->x = encoded_point + 1;
            point->x_len = _wincng_ecdsa_algorithms[curve].point_length;

            point->y = point->x + point->x_len;
            point->y_len = _wincng_ecdsa_algorithms[curve].point_length;

            return LIBSSH2_ERROR_NONE;
        }
    }

    return LIBSSH2_ERROR_INVAL;
}