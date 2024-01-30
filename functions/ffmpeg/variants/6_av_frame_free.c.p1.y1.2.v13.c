1)

void av_frame_free(AVFrame **frame)
{
    if (frame == NULL) 
        return;
        
    if (*frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

Compare the two "if" statements separately.

2)

void av_frame_free(AVFrame **frame)
{
    if (frame && *frame) {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}

Convert "return" to an "if" statement and perform the operations inside this "if" statement.

3)

void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

Merge the two "if" conditions together. 

4)

void av_frame_free(AVFrame **frame)
{
    if (!(frame && *frame))
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

Negate the single "if" condition.