synctask_new (struct syncenv *env, synctask_fn_t fn, synctask_cbk_t cbk,
              call_frame_t *frame, void *opaque)
{
	struct synctask *newtask = NULL;
	int              ret = 0;

	newtask = synctask_create (env, fn, cbk, frame, opaque);
	if (!newtask)
		return -1;

        if (!cbk)
		ret = synctask_join (newtask);

        return ret;
}