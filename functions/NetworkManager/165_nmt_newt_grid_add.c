nmt_newt_grid_add(NmtNewtGrid *grid, NmtNewtWidget *widget, int x, int y)
{
    NmtNewtGridPrivate *priv = NMT_NEWT_GRID_GET_PRIVATE(grid);
    NmtNewtGridChild    child;

    NMT_NEWT_CONTAINER_CLASS(nmt_newt_grid_parent_class)->add(NMT_NEWT_CONTAINER(grid), widget);

    memset(&child, 0, sizeof(child));
    child.widget = widget;
    child.x      = x;
    child.y      = y;
    child.flags  = NMT_NEWT_GRID_FILL_X | NMT_NEWT_GRID_FILL_Y;
    g_array_append_val(priv->children, child);

    if (x > priv->max_x)
        priv->max_x = x;
    if (y > priv->max_y)
        priv->max_y = y;
}