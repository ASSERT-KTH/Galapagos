k5_json_release(k5_json_value val)
{
    struct value_base *p;

    if (val == NULL)
        return;
    p = PTR2BASE(val);
    assert(p->ref_cnt != 0);
    p->ref_cnt--;
    if (p->ref_cnt == 0) {
        if (p->isa->dealloc != NULL)
            p->isa->dealloc(val);
        free(p);
    }
}