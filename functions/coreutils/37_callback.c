callback (struct callback_locals *locals, uintptr_t start, uintptr_t end)
{
# if STACK_DIRECTION < 0
  if (locals->address >= start && locals->address <= end - 1)
    {
      locals->vma->start = start;
      locals->vma->end = end;
      locals->vma->prev_end = locals->prev;
      locals->retval = 0;
      return 1;
    }
  locals->prev = end;
# else
  if (locals->stop_at_next_vma)
    {
      locals->vma->next_start = start;
      locals->stop_at_next_vma = 0;
      return 1;
    }
  if (locals->address >= start && locals->address <= end - 1)
    {
      locals->vma->start = start;
      locals->vma->end = end;
      locals->retval = 0;
      locals->stop_at_next_vma = 1;
      return 0;
    }
# endif
  return 0;
}