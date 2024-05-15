ucisprop(krb5_ui_4 code, krb5_ui_4 mask1, krb5_ui_4 mask2)
{
    krb5_ui_4 i;

    if (mask1 == 0 && mask2 == 0)
      return 0;

    for (i = 0; mask1 && i < 32; i++) {
        if ((mask1 & masks32[i]) && _ucprop_lookup(code, i))
          return 1;
    }

    for (i = 32; mask2 && i < _ucprop_size; i++) {
        if ((mask2 & masks32[i & 31]) && _ucprop_lookup(code, i))
          return 1;
    }

    return 0;
}