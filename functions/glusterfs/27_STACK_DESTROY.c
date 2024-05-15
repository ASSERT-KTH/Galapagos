STACK_DESTROY (call_stack_t *stack)
{
        void *local = NULL;

        LOCK (&stack->pool->lock);
        {
                list_del_init (&stack->all_frames);
                stack->pool->cnt--;
        }
        UNLOCK (&stack->pool->lock);

        if (stack->frames.local) {
                local = stack->frames.local;
                stack->frames.local = NULL;
        }

        LOCK_DESTROY (&stack->frames.lock);
        LOCK_DESTROY (&stack->stack_lock);

        while (stack->frames.next) {
                FRAME_DESTROY (stack->frames.next);
        }

	GF_FREE (stack->groups_large);

        mem_put (stack);

        if (local)
                mem_put (local);
}