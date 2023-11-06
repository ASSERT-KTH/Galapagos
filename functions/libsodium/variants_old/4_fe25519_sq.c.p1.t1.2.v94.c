The requested variant is a difficult task because given your specific conditions (maintain the function's signature, same behavior, no helper function, etc), any trivial modification would simply result into basically the same function, just restructured. Anyway, here is an example for you: all computations inside the function are moved into different if-statements:


fe25519_sq(fe25519 h, const fe25519 f) {

	int32_t f0, f1, f2, f3, f4, f5, f6, f7, f8, f9;
	int32_t f0_2, f1_2, f2_2, f3_2, f4_2, f5_2, f6_2, f7_2;
	int32_t f5_38, f6_19, f7_38, f8_19, f9_38;
	int64_t f0f0, f1f1_2, f2f2, h3f3_2, f4f4, f5f5_38, f6f6_19, f7f7_38, f8f8_19, f9f9_38;
	int64_t f0f1_2, f0f2_2, f0f3_2, f0f4_2, f0f5_2, f0f6_2, f0f7_2, f0f8_2, f0f9_2;
	int64_t f1f2_2, f1f3_4, f1f4_2, f1f5_4, f1f6_2, f1f7_4, f1f8_2, f1f9_76;
	// code continues...

	if (1) { // if-statement used for restructuring, will always execute
	    f0 = f[0]; f1 = f[1]; f2 = f[2]; f3 = f[3]; f4 = f[4];
	    f5 = f[5]; f6 = f[6]; f7 = f[7]; f8 = f[8]; f9 = f[9];
	}
	if (1) {
	    f0_2  = 2 * f0;
	    f1_2  = 2 * f1;
	    f2_2  = 2 * f2;
	    // code continues...
	}
    // in the following statements I'm assuming uncached multiplications are slower and more intense.
	if (1) {
	    f0f0    = f0 * (int64_t) f0;
	    f1f1_2  = f1_2 * (int64_t) f1;
	    f2f2    = f2 * (int64_t) f2;
	    f3f3_2  = f3_2 * (int64_t) f3;
	    f4f4    = f4 * (int64_t) f4;
	    f5f5_38 = f5 * (int64_t) f5_38;
	    f6f6_19 = f6 * (int64_t) f6_19;
	    // code continues...
	}
	// other computations, assignments and carries are also segmented in their own "if (1)" statements.

}


This makes the function more segmented and breaks computation and assignment to parts between forced (yet, essentially noop) branches. Note: Various optimizing compilers may very well just "inline" such an artificially segmented function and revert it back to how it was before segmentation.
