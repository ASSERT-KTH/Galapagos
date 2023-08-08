fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f_elements[10];
    int32_t doubles_elements[10];
    int32_t series_carry[10];
    int32_t series_38_constants[] = {38, 19, 38, 19, 38};
    int64_t extended_ele_product[45];

    for (int i = 0; i < 10; i++)
    {
        f_elements[i] = f[i];

        if (i < 5)
        {
            doubles_elements[i] = 2 * f[i];
            doubles_elements[i + 5] =2 * f[i + 5];
        }
    }

    for (int a = 0; a < 10; a++)
    {
        for (int b = a; b < 10; b++)
        {
            if (a + b >= 19)
            {
                if (a == b)
                {
                    extended_ele_product[a+b] = f_elements[a] * ((int64_t) f_elements[b]);
                }
                else
                {
                    extended_ele_product[a+b] = doubles_elements[a] * ((int64_t) f_elements[b]);
                }

            }
            else if (a + b >= 15)
            {
                if (a == b)
                {
                    extended_ele_product[a+b] = f_elements[a] * ((int64_t) f_elements[b] * series_38_constants[a - 5]);
                }
                else
                {
                    extended_ele_product[a+b] = doubles_elements[a] * ((int64_t) f_elements[b] * series_38_constants[a - 5]);
                }
            }
            else if (a == b)
            {
                extended_ele_product[a+b] = f_elements[a] * ((int64_t) f_elements[b]);
            }
            else if ((a == b-1 && (a % 2 == 1)))
            {
                extended_ele_product[a+b] = doubles_elements[a] * ((int64_t) doubles_elements[b]);
            }
            else
            {
                extended_ele_product[a+b] = doubles_elements[a] * ((int64_t) f_elements[b]);
            }         
        } 

    }

    for (int series = 1; series < 5; series++)
    {
        series_carry[series - 1] = (extended_ele_product[series * 5 - 1] + (int64_t)(1L << (25 + (1 - series % 2)))) >> (26 - series % 2);
        extended_ele_product[series * 5] += series_carry[series - 1];
        extended_ele_product[series * 5 - 1] -= series_carry[series - 1] * ((uint64_t) 1L << (26 - series % 2));
        series_carry[series + 4] = (extended_ele_product[series * 5 + 4] + (int64_t)(1L << (25 + series % 2))) >> (26 - series % 2);   
        extended_ele_product[(series + 1) % 5 * 5] += series_carry[series + 4];
        extended_ele_product[series * 5 + 4] -= series_carry[series + 4] * ((uint64_t) 1L << (26 - series % 2));
        
    }
        
    series_carry[8] = (extended_ele_product[21] + (int64_t)(1L << 24)) >> 25;
    extended_ele_product[0] += series_carry[8] * 19;
    extended_ele_product[21] -= series_carry[8] * ((uint64_t) 1L << 25);


    series_carry[9] = (extended_ele_product[0] + (int64_t)(1L << 25)) >> 26;
    extended_ele_product[1] += series_carry[9];
    extended_ele_product[0] -= series_carry[9] * ((uint64_t) 1L << 26);

    for (int j = 0; j < 10; j++)
    {
        h[j] = (int32_t)extended_ele_product[j * 2 + 1];
    }   
}