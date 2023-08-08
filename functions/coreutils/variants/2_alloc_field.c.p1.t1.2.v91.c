Here's a variant of the code which creates the same functionality:


alloc_field(int f, char const *c)
{
    columns = (struct field_data_t**) realloc(columns, sizeof(struct field_data_t*) * (ncolumns + 1));

    if (columns != nullptr)
    {
        ncolumns++;
        struct field_data_t * curr = &field_data[f];
        columns[ncolumns - 1] = curr;

        if (!curr->used)
        {
            /* Mark field as used.  */
            curr->used = true;
            curr->caption = (c != nullptr) ? c : curr->caption;
            return;
        }
    }
    /* Handle allocation failure if necessary */
    printf("Failed to allocate memory.\n");
}

This variant doesn't use the function xnrealloc which checks for successful memory relocation unlike his original one, but its behavior depends on defining appropriate error processing logic. In this case, it’s a simple error message saying that the memory allocation has failed. The improved memory handling make the whole function more robust. Moreover, here caption is assigned only when the field is not used which makes the function more sensible - performing assignments on used fields doesn’t make sense in some particular situations resulting in distinct behavior which fulfills the task's requirements to provide a variant.