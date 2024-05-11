dispose(GObject *object)
{
    NMNDisc *ndisc = NM_NDISC(object);

    _cleanup(ndisc);

    G_OBJECT_CLASS(nm_lndp_ndisc_parent_class)->dispose(object);
}