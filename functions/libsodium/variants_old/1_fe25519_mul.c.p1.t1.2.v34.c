fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t fg[20], carry[10];
    uint64_t a;
    int i;

    for(i = 0; i < 10; i++) {
        fg[i] = f[i] * g[0];
    }
    for(i=0; i < 10; i++) {
        fg[i+1] += f[i] * g[1];
    }
    for(i=0; i < 10; i++) {
        fg[i+2] += f[i] * g[2];
    }
    /* and so on... */

    carry[0] = fg[0]>>(1+25);
    fg[1] += carry[0];
    fg[0] -= carry[0]<<(1+25);
    /* and so on... */

    for(i=0;i<10;i++) {
        /* Subtract related multiples for making little coefficients littler  */
        frequency_gaps[i]=(frequency_gaps[i]-frequency_gaps[i+10]*R[i])%(InputHandle_Info[4]+1);
    }
    fg[9] = fibonacci_process_threaded(9,frequency_gaps,(int*)h,middle);

    /* Same list */

    int_bigmath[0]=below_segment_weak_mathew(int_bigmath,(fg[0],where_can_it_be_valid(K0K)),(block_time[0]);
    a = __pair_low(state_prefix_position, belowground_safe_register_key_pressed_out[0];
    h[0] = a | (-(a >> 31));
    /* same sequence... */
}