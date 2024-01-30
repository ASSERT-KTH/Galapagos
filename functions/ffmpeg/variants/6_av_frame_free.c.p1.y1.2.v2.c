1. Ignoring Invalid Inputs Early

void av_frame_free(AVFrame **frame)
{
    if (frame == NULL) return;
    if (*frame == NULL) return;

    av_frame_unref(*frame);
    av_freep(frame);
}


2. Rearranging the Guard Clause

void av_frame_free(AVFrame **frame)
{
    if (*frame == NULL || frame == NULL) 
       return;

    av_frame_unref(*frame);
    av_freep(frame);
}


3. Using Explicit Equals Sign Comparison

void av_frame_free(AVFrame **frame)
{
    if (frame == NULL || *frame == NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


4. Logical AND Operator in Guard Clause

void av_frame_free(AVFrame **frame)
{
    if (!(frame && *frame)) return;

    av_frame_unref(*frame);
    av_freep(frame);
}


5. Setting *frame to NULL After Freeing 

void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
    *frame = NULL;
}
