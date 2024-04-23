static int FUNC(group_of_pictures_header)(CodedBitstreamContext *ctx, RWContext *rw,
                                          MPEG2RawGroupOfPicturesHeader *current)
{
    int err;

    HEADER("Group of Pictures Header");

    ui(8,  group_start_code);

    ui(25, time_code);
    ui(1,  closed_gop);
    ui(1,  broken_link);

    return 0;
}