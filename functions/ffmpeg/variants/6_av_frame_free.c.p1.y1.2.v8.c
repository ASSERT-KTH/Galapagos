1. Swapping the conditions:

void av_frame_free(AVFrame **frame)
{
    if (!*frame || !frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

2. Using separate if checks for the two conditions instead of using the "or" operator:

void av_frame_free(AVFrame **frame)
{
    if (!frame)
        return;

    if (!*frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

3. Using checks "is equal to NULL" instead of using contrasts (! operator):

void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}

4. Writing the "if" statement in a single line:

void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame) return;

    av_frame_unref(*frame);
    av_freep(frame);
}

5. Replace return in `if` condition with rest of code under `else` statement:

void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame) {} 
    else {
        av_frame_unref(*frame);
        av_freep(frame);
    }
}
