void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL)
        return;

    av_frame_unref(*frame);

    if (*frame != NULL) 
        av_freep(frame);
}
In the variant version, the function still performs the same actions, i.e unreference the AVFrame and free up the memory space. However instead of checking if `*frame` is not NULL along with 'frame' at the functionality's start, the checksum to `*frame` is done just before we 'free' it, which essentially leads to the same conclusion but constitutes a change in code structure. An application would check if the passed pointer (as well as the object it points to) isn't NULL before performing operations `av_frame_unref` and `av_freep` on it to avoid runtime errors.