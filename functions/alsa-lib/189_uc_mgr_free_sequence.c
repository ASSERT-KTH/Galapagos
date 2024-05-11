void uc_mgr_free_sequence(struct list_head *base)
{
	struct list_head *pos, *npos;
	struct sequence_element *seq;
	
	list_for_each_safe(pos, npos, base) {
		seq = list_entry(pos, struct sequence_element, list);
		list_del(&seq->list);
		uc_mgr_free_sequence_element(seq);
	}
}