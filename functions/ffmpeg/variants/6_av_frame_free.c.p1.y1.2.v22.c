1. Change the ordering of freeing methods

void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame)
        return;

    av_freep(frame);
    av_frame_unref(*frame);
}


2. Breaking into multiple if statements

void av_frame_free(AVFrame **frame)
{
    if (!frame)
        return;
    if (!*frame)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}


3. Using ternary operators instead of if statements

void av_frame_free(AVFrame **frame)
{
    (!frame || !*frame) ? : av_frame_unref(*frame);
    (!frame || !*frame) ? : av_freep(frame);
}


4. Using guards for freeing call

void av_frame_free(AVFrame **frame)
{
    if (frame)
        if(*frame){
            av_frame_unref(*frame);
            av_freep(frame);
        }
}


5. Adding extra check for null pointer

void av_frame_free(AVFrame **frame)
{
    if (!frame || !*frame || *frame==NULL)
        return;

    av_frame_unref(*frame);
    av_freep(frame);
}
