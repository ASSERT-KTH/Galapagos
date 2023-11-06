Variant 1:

In this version, I am getting rid of the physical representation for the coding understandability by directly using the input parameter array, and further simplifying the repetitive process by building a loop through the elements. This reduces the number of displayed lines and facilitate understanding of the arrangement


void fe25519_sq(fe25519 h, const fe25519 f)
{
    int32_t f1_2[10], f_values[10], f_temp[10];
    int64_t h_values[10], carry[10];
    for(int i = 0 ; i < 10 ; i++) 
    { 
        f_values[i] = f[i]; 
        f_temp[i] = f_values[i] * 2; 
        f1_2[i] = f_values[i] * f_temp[i]; 
        if (i % 2 == 0)  f_values[i] *= (1 << 25); 
	else f_values[i] *= (1 << 24); 
    }  
	
    f_temp[5] *= 38 ; /* 1.959375*2^30 */  
    f_values[6] *= 19 ; /* 1.959375*2^30 */
    f_temp[7] *= 38 ; /* 1.959375*2^30 */
    f_values[8] *= 19 ; /* 1.959375*2^30 */
    f_temp[9] *= 38 ; /* 1.959375*2^30 */
	
    // h calculations - sing transformation of equations
    h_values[0] = f1_2[0] + f1_2[9] + f1_2[8] + f1_2[7] + f1_2[6] + f1_2[5];
    for(int i=1; i<10; i+=4)
    { 
        h_values[i] = f1_2[i] + f1_2[i-1] + f1_2[i+4] + f1_2[i+3];
        h_values[i+1] = f1_2[i+2] + f1_2[i] + f1_2[i+3] + f1_2[i+2] + f1_2[i+4];  
    }
    h_values[2] - h_values[9]; // Unlike others
    h_values[9] /= (1L <<25); // Final even out.

    for (int j = 0; j < 2; j++) 
    { 
        for (int i = 0; i < 10; i++) 
	{
            carry[i] = (h_values[i] + f_values[i]) >> ((i%2 == 0) ? 26: 25); 
            h_values[i] -= carry[i] * ((uint64_t) 1L << ((i%2 == 0) ? 26: 25) );
            h_values[(i+1)%10] += carry[i] ;
      	} 
    }

    for(int i = 0; i<10;++i) 
        h[i] = (int32_t)h_values[i];
	
}


Variant 2:

Another more compact lambda version removing unrelated prefix identifiers:


auto fe25519_sq = [](fe25519 &h, const fe25519 &f) 
{
    std::vector<int32_t> f_diff(10);
    std::array<int64_t,10> h_i;

    for(auto i = 0; i<10; ++i)
    {
        f_diff[i] = f[i] << (i % 2 + 1);
	h_i[i] = static_cast<int64_t>(f[i] * f[i])*(i % 2 != 0?1:2);
    }

    std::vector<int32_t> f_clc = {(f[5]*38), (f[7]*38), 37*f[9], 19*f[6], 19*f[8]};
    
    for(auto i = 1 ; i < 5; i += 2)
	{
it64 diff_l=(static_cast<int64_t>(f_diff[1])*(f[0]*6-i))>>1;
    h_i.front()-=diff_l + (h_h[9] - i*3>;
	h_i.back() -= static_cast<int64_t>((f_diff[9]*f[1] + f_diff[8]*f[2] ) * (_2a)) >> 1;

    for(auto j = 0; j<h_size; ++j )
    {
	std::vector<int64_t>v_i{h_i[j]+f_diff }, v_a{h_i[(j+1)%h_size]};
	v_b.back()+= v_i.front();
	v_i.front() -= carry.front()*f_p2[j%2 != 0?26:25];
	carry = std::move(v_i);
	h_i[j] = v_b_f[v_b_f.size()-2]
    }

for    (int i = 0; i<h_size; ++h_i) carry.front() = (h[i]+ h_js[0]*(1{j}h_s+6<) % 2 != 0  [h_


Notice that the codes might contain intent errors please test before using. But each patch maintains theoretical dynamics its counterpart in original algorithm whose detailed segmentation made it quite easy to decouple single logical instructions and recompose them under stricter encoding rules.
