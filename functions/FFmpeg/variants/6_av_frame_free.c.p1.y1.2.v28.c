1. Code Variant with separated "if" conditions:

void av_frame_free(AVFrame **frame)
{
    if (!frame)
        return;
    if (!*frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


2. Using local variable:

void av_frame_free(AVFrame **frame)
{
    AVFrame *local_frame;

    if (!frame)
        return;
    local_frame = *frame;
    if (!local_frame)
        return;

    av_frame_unref(local_frame);
    av_freep(frame);
}


3. Variant with early return check:

void av_frame_free(AVFrame **frame)
{
    if(frame == NULL)
    {
        return;
    }

    if(*frame == NULL)
    {
        return;
    }

    av_frame_unref(*frame);
    av_freep(frame);
}


4. Variant with negated logic (ref and freep will not execute if frame checks are not met):

void av_frame_free(AVFrame **frame)
{
    if (frame && *frame) {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}


5. Using multiple if statements with return:

void av_frame_free(AVFrame **frame)
{
    if (frame == NULL) {
        return;
    }

    if (*frame == NULL) {
        return;
    }

    av_frame_unref(*frame);
    av_freep(frame);
}
