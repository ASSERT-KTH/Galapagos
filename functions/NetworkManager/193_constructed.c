constructed(GObject *object)
{
    NMSetting      *self  = NM_SETTING(object);
    NMSettingClass *klass = NM_SETTING_GET_CLASS(self);

    /* we don't support that NMSetting subclasses override constructed.
     * They all must have no G_PARAM_CONSTRUCT/G_PARAM_CONSTRUCT_ONLY
     * properties, otherwise the automatism of _init_direct() needs
     * careful adjustment. */
    nm_assert(G_OBJECT_CLASS(klass)->constructed == constructed);

    /* we always initialize the defaults of the (direct) properties. Note that:
     *
     * - we don't use CONSTRUCT properties, because they have an overhead during
     *   each object creation. Via _init_direct() we can do it more efficiently.
     *
     * - we always call this, because we want to get all default values right.
     *   We even call this for NMSetting subclasses that (historically) are not
     *   yet aware of this happening.
     */
    _init_direct(self);

    G_OBJECT_CLASS(nm_setting_parent_class)->constructed(object);
}