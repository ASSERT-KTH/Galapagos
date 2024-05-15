changelog_color_fop_and_inc_cnt (xlator_t *this, changelog_priv_t *priv,
                                                 changelog_local_t *local)
{
        if (!priv || !local)
                return;

        LOCK (&priv->lock);
        {
                local->color = priv->current_color;
                changelog_inc_fop_cnt (this, priv, local);
        }
        UNLOCK (&priv->lock);
}