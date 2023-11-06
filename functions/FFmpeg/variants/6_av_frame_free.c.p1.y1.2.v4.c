Version 1

void av_frame_free(AVFrame **frame)
{
    AVFrame **input = frame;
    
    if (!input || !*input)
        return;

    av_frame_unref(*input);
    av_freep(input);
}


Version 2

void av_frame_free(AVFrame **frame)
{
    if (!frame)
        return;

    if(!*frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


Version 3

void av_frame_free(AVFrame **frame)
{
    if (!frame)
        return;
        
    if (*frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


Version 4

void av_frame_free(AVFrame **frame)
{
    if (!(frame && *frame))
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


Version 5

void av_frame_free(AVFrame **frame)
{
    if (frame != NULL && *frame != NULL) {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}
