; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/0_alaw_to_s16_2.bc'
source_filename = "gomodule"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

module asm "\09.section \22.go_export\22,\22e\22,@progbits"
module asm "\09.ascii \22v3;\\n\22"
module asm "\09.ascii \22package \22"
module asm "\09.ascii \22main\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22pkgpath \22"
module asm "\09.ascii \22main\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22import \22"
module asm "\09.ascii \22runtime\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22runtime\22"
module asm "\09.ascii \22 \\\22\22"
module asm "\09.ascii \22runtime\22"
module asm "\09.ascii \22\\\22\\n\22"
module asm "\09.ascii \22init\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22cpu\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22internal_1cpu..import\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22runtime\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22runtime..import\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22abi\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22~internal_1abi\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22bytealg\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22~internal_1bytealg\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22goarch\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22~internal_1goarch\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22goexperiment\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22~internal_1goexperiment\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22goos\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22~internal_1goos\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22atomic\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22~runtime_1internal_1atomic\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22math\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22~runtime_1internal_1math\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22sys\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22~runtime_1internal_1sys\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22init_graph\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \221\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \220\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22types 2 1\22"
module asm "\09.ascii \22 32\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -20>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22alawToS16\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22aVal\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -20>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:782>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/0_alaw_to_s16_2.go:3\\n aVal = (aVal ^ $convert(<type -20>, 85 )) //4\\n var t <type -3> = $convert(<type -3>, (aVal & $convert(<type -20>, 127 ))) //5\\n { //6\\n  if (t >= $convert(<type -3>, 16 )) { //6\\n   var seg <type -3> = ((t >> $convert(<type -12>, 4 )) & 7 ) //7\\n   t = (((t & $convert(<type -3>, 15 )) << $convert(<type -12>, 4 )) + $convert(<type -3>, 264 )) //8\\n   t = (t << (seg - $convert(<type -3>, 1 ))) //9\\n  } else { //10\\n   t = ((t << $convert(<type -12>, 4 )) + $convert(<type -3>, 8 )) //11\\n  } //6\\n } //12\\n { //13\\n  if ((aVal & $convert(<type -20>, 128 )) != $convert(<type -20>, 0 )) { //13\\n   { //14\\n    $ret0 = t //14\\n    return //14\\n   } //0\\n  } //13\\n } //15\\n { //16\\n  $ret0 = -t //16\\n  return //16\\n } //0\\n\22"
module asm "\09.ascii \22checksum 3B0011DD29E55449FD2C26BC72D4C11243A141E1\\n\22"
module asm "\09.text"

%functionDescriptor.0 = type { i64 }

@main.struct_4runtime_0gList_cruntime_0n_bint32_5..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main.struct_4runtime_0gList_cruntime_0n_bint32_5..eq to i64) }
@main._632_7uintptr..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._632_7uintptr..eq to i64) }
@main._6256_7uint64..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._6256_7uint64..eq to i64) }
@main._661_7struct_4Size_buint32_cMallocs_buint64_cFrees_buint64_5..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._661_7struct_4Size_buint32_cMallocs_buint64_cFrees_buint64_5..eq to i64) }
@main.struct_4Size_buint32_cMallocs_buint64_cFrees_buint64_5..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main.struct_4Size_buint32_cMallocs_buint64_cFrees_buint64_5..eq to i64) }
@main._6122_7uintptr..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._6122_7uintptr..eq to i64) }
@main._68_7uint64..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._68_7uint64..eq to i64) }
@main._6128_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._6128_7uint8..eq to i64) }
@main._64096_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._64096_7uint8..eq to i64) }
@main._668_7uint16..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._668_7uint16..eq to i64) }
@main._633_7float64..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._633_7float64..eq to i64) }
@main._665_7uint32..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._665_7uint32..eq to i64) }
@main._64_7uintptr..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._64_7uintptr..eq to i64) }
@main._65_7uint..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._65_7uint..eq to i64) }
@main._6512_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._6512_7uint8..eq to i64) }
@main._6249_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._6249_7uint8..eq to i64) }
@main._6129_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._6129_7uint8..eq to i64) }
@main._632_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._632_7uint8..eq to i64) }
@main._627_7string..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._627_7string..eq to i64) }
@main._61024_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._61024_7uint8..eq to i64) }
@main._62_7int32..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._62_7int32..eq to i64) }
@main._664_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._664_7uint8..eq to i64) }
@main._6256_7uint8..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._6256_7uint8..eq to i64) }
@main..types = constant { i64, [1 x ptr] } zeroinitializer
@internal_1cpu..types = external externally_initialized global { i64, [1 x ptr] }
@runtime..types = external externally_initialized global { i64, [1 x ptr] }
@internal_1abi..types = external externally_initialized global { i64, [1 x ptr] }
@internal_1bytealg..types = external externally_initialized global { i64, [1 x ptr] }
@internal_1goarch..types = external externally_initialized global { i64, [1 x ptr] }
@internal_1goexperiment..types = external externally_initialized global { i64, [1 x ptr] }
@internal_1goos..types = external externally_initialized global { i64, [1 x ptr] }
@runtime_1internal_1atomic..types = external externally_initialized global { i64, [1 x ptr] }
@runtime_1internal_1math..types = external externally_initialized global { i64, [1 x ptr] }
@runtime_1internal_1sys..types = external externally_initialized global { i64, [1 x ptr] }
@go..typelists = internal constant [11 x ptr] [ptr @internal_1cpu..types, ptr @runtime..types, ptr @internal_1abi..types, ptr @internal_1bytealg..types, ptr @internal_1goarch..types, ptr @internal_1goexperiment..types, ptr @internal_1goos..types, ptr @runtime_1internal_1atomic..types, ptr @runtime_1internal_1math..types, ptr @runtime_1internal_1sys..types, ptr @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(ptr nest nocapture readnone %nest.29) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(ptr nest undef, i64 11, ptr @go..typelists)
  call void @internal_1cpu..import(ptr nest undef)
  call void @runtime..import(ptr nest undef)
  ret void
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid willreturn memory(none)
define i32 @main.alawToS16(ptr nest nocapture readnone %nest.0, i8 zeroext %aVal) local_unnamed_addr #1 {
entry:
  %xor.0 = and i8 %aVal, 127
  %iand.0 = xor i8 %xor.0, 85
  %zext.0 = zext i8 %iand.0 to i32
  %icmp.2 = icmp ugt i8 %iand.0, 15
  br i1 %icmp.2, label %then.0, label %else.0

then.0:                                           ; preds = %entry
  %0 = lshr i32 %zext.0, 4
  %iand.2 = shl nuw nsw i32 %zext.0, 4
  %shl.0 = and i32 %iand.2, 240
  %add.0 = or i32 %shl.0, 264
  %sub.0 = add nsw i32 %0, -1
  %shl.1 = shl i32 %add.0, %sub.0
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %else.0, %then.0
  %t.0 = phi i32 [ %shl.1, %then.0 ], [ %add.1, %else.0 ]
  %icmp.3.not = icmp sgt i8 %aVal, -1
  %sub.1 = sub i32 0, %t.0
  %common.ret.op = select i1 %icmp.3.not, i32 %sub.1, i32 %t.0
  ret i32 %common.ret.op

else.0:                                           ; preds = %entry
  %shl.2 = shl nuw nsw i32 %zext.0, 4
  %add.1 = or i32 %shl.2, 8
  br label %fallthrough.0
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid willreturn memory(none)
define void @main.main(ptr nest nocapture %nest.1) local_unnamed_addr #1 {
entry:
  ret void
}

; Function Attrs: noreturn null_pointer_is_valid
declare void @runtime.panicmem(ptr) local_unnamed_addr #2

; Function Attrs: null_pointer_is_valid
define i8 @main.struct_4runtime_0gList_cruntime_0n_bint32_5..eq(ptr nest nocapture readnone %nest.6, ptr readonly %key1, ptr readonly %key2) #0 {
entry:
  %icmp.8 = icmp eq ptr %key1, null
  br i1 %icmp.8, label %then.9, label %else.9, !make.implicit !3

then.9:                                           ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.9:                                           ; preds = %entry
  %icmp.9 = icmp eq ptr %key2, null
  br i1 %icmp.9, label %then.10, label %else.10, !make.implicit !3

then.10:                                          ; preds = %else.9
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.10:                                          ; preds = %else.9
  %tmpv.12.sroa.0.0.cast.10.sroa_idx = bitcast ptr %key1 to ptr
  %tmpv.12.sroa.0.0.copyload = load i64, ptr %tmpv.12.sroa.0.0.cast.10.sroa_idx, align 8
  %tmpv.13.sroa.0.0.cast.15.sroa_idx = bitcast ptr %key2 to ptr
  %tmpv.13.sroa.0.0.copyload = load i64, ptr %tmpv.13.sroa.0.0.cast.15.sroa_idx, align 8
  %icmp.10.not = icmp eq i64 %tmpv.12.sroa.0.0.copyload, %tmpv.13.sroa.0.0.copyload
  br i1 %icmp.10.not, label %else.13, label %common.ret

common.ret:                                       ; preds = %else.13, %else.10
  %common.ret.op = phi i8 [ 0, %else.10 ], [ %., %else.13 ]
  ret i8 %common.ret.op

else.13:                                          ; preds = %else.10
  %field.8 = getelementptr inbounds i8, ptr %key1, i64 8
  %0 = bitcast ptr %field.8 to ptr
  %.field.ld.0 = load i32, ptr %0, align 4
  %field.9 = getelementptr inbounds i8, ptr %key2, i64 8
  %1 = bitcast ptr %field.9 to ptr
  %.field.ld.1 = load i32, ptr %1, align 4
  %icmp.14.not = icmp eq i32 %.field.ld.0, %.field.ld.1
  %. = zext i1 %icmp.14.not to i8
  br label %common.ret
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._632_7uintptr..eq(ptr nest nocapture readnone %nest.7, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.3 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 256)
  ret i8 %call.3
}

; Function Attrs: nofree null_pointer_is_valid memory(argmem: read)
declare i8 @runtime.memequal(ptr, ptr, ptr, i64) local_unnamed_addr #4

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._6256_7uint64..eq(ptr nest nocapture readnone %nest.8, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.4 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 2048)
  ret i8 %call.4
}

; Function Attrs: null_pointer_is_valid
define i8 @main._661_7struct_4Size_buint32_cMallocs_buint64_cFrees_buint64_5..eq(ptr nest nocapture readnone %nest.9, ptr readonly %key1, ptr readonly %key2) #0 {
entry:
  %cast.20 = bitcast ptr %key1 to ptr
  %cast.21 = bitcast ptr %key2 to ptr
  %icmp.17 = icmp eq ptr %key1, null
  br i1 %icmp.17, label %then.17.split, label %entry.split, !make.implicit !3

entry.split:                                      ; preds = %entry
  %icmp.20 = icmp eq ptr %key2, null
  br i1 %icmp.20, label %then.19.split, label %then.23, !make.implicit !3

label.0:                                          ; preds = %then.23
  %add.2 = add nuw nsw i64 %tmpv.26.018, 1
  %exitcond.not = icmp eq i64 %add.2, 61
  br i1 %exitcond.not, label %common.ret, label %then.23

then.17.split:                                    ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

then.19.split:                                    ; preds = %entry.split
  call void @runtime.panicmem(ptr nest undef)
  unreachable

common.ret:                                       ; preds = %then.23, %label.0
  %common.ret.op = phi i8 [ 0, %then.23 ], [ 1, %label.0 ]
  ret i8 %common.ret.op

then.23:                                          ; preds = %label.0, %entry.split
  %tmpv.26.018 = phi i64 [ %add.2, %label.0 ], [ 0, %entry.split ]
  %tmpv.28.sroa.4.0.cast.24.sroa_idx7 = getelementptr [61 x { i32, i64, i64 }], ptr %cast.20, i64 0, i64 %tmpv.26.018, i32 2
  %tmpv.28.sroa.4.0.copyload = load i64, ptr %tmpv.28.sroa.4.0.cast.24.sroa_idx7, align 8
  %tmpv.28.sroa.3.0.cast.24.sroa_idx6 = getelementptr [61 x { i32, i64, i64 }], ptr %cast.20, i64 0, i64 %tmpv.26.018, i32 1
  %tmpv.28.sroa.3.0.copyload = load i64, ptr %tmpv.28.sroa.3.0.cast.24.sroa_idx6, align 8
  %tmpv.28.sroa.0.0.cast.24.sroa_idx = getelementptr [61 x { i32, i64, i64 }], ptr %cast.20, i64 0, i64 %tmpv.26.018, i32 0
  %tmpv.28.sroa.0.0.copyload = load i32, ptr %tmpv.28.sroa.0.0.cast.24.sroa_idx, align 8
  %tmpv.29.sroa.0.0.cast.29.sroa_idx = getelementptr [61 x { i32, i64, i64 }], ptr %cast.21, i64 0, i64 %tmpv.26.018, i32 0
  %tmpv.29.sroa.0.0.copyload = load i32, ptr %tmpv.29.sroa.0.0.cast.29.sroa_idx, align 8
  %tmpv.29.sroa.3.0.cast.29.sroa_idx4 = getelementptr [61 x { i32, i64, i64 }], ptr %cast.21, i64 0, i64 %tmpv.26.018, i32 1
  %tmpv.29.sroa.3.0.copyload = load i64, ptr %tmpv.29.sroa.3.0.cast.29.sroa_idx4, align 8
  %tmpv.29.sroa.4.0.cast.29.sroa_idx5 = getelementptr [61 x { i32, i64, i64 }], ptr %cast.21, i64 0, i64 %tmpv.26.018, i32 2
  %tmpv.29.sroa.4.0.copyload = load i64, ptr %tmpv.29.sroa.4.0.cast.29.sroa_idx5, align 8
  %icmp.21 = icmp eq i32 %tmpv.28.sroa.0.0.copyload, %tmpv.29.sroa.0.0.copyload
  %icmp.22 = icmp eq i64 %tmpv.28.sroa.3.0.copyload, %tmpv.29.sroa.3.0.copyload
  %tmpv.35.0.in = select i1 %icmp.21, i1 %icmp.22, i1 false
  %icmp.23 = icmp eq i64 %tmpv.28.sroa.4.0.copyload, %tmpv.29.sroa.4.0.copyload
  %tmpv.36.0.in = select i1 %tmpv.35.0.in, i1 %icmp.23, i1 false
  br i1 %tmpv.36.0.in, label %label.0, label %common.ret
}

; Function Attrs: null_pointer_is_valid
define i8 @main.struct_4Size_buint32_cMallocs_buint64_cFrees_buint64_5..eq(ptr nest nocapture readnone %nest.10, ptr readonly %key1, ptr readonly %key2) #0 {
entry:
  %icmp.26 = icmp eq ptr %key1, null
  br i1 %icmp.26, label %then.24, label %else.24, !make.implicit !3

then.24:                                          ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.24:                                          ; preds = %entry
  %icmp.27 = icmp eq ptr %key2, null
  br i1 %icmp.27, label %then.25, label %else.25, !make.implicit !3

then.25:                                          ; preds = %else.24
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.25:                                          ; preds = %else.24
  %field.16 = bitcast ptr %key1 to ptr
  %.field.ld.2 = load i32, ptr %field.16, align 4
  %field.17 = bitcast ptr %key2 to ptr
  %.field.ld.3 = load i32, ptr %field.17, align 4
  %icmp.28.not = icmp eq i32 %.field.ld.2, %.field.ld.3
  br i1 %icmp.28.not, label %else.28, label %common.ret

common.ret:                                       ; preds = %else.31, %else.28, %else.25
  %common.ret.op = phi i8 [ 0, %else.25 ], [ 0, %else.28 ], [ %., %else.31 ]
  ret i8 %common.ret.op

else.28:                                          ; preds = %else.25
  %field.18 = getelementptr inbounds i8, ptr %key1, i64 8
  %0 = bitcast ptr %field.18 to ptr
  %.field.ld.4 = load i64, ptr %0, align 8
  %field.19 = getelementptr inbounds i8, ptr %key2, i64 8
  %1 = bitcast ptr %field.19 to ptr
  %.field.ld.5 = load i64, ptr %1, align 8
  %icmp.31.not = icmp eq i64 %.field.ld.4, %.field.ld.5
  br i1 %icmp.31.not, label %else.31, label %common.ret

else.31:                                          ; preds = %else.28
  %field.20 = getelementptr inbounds i8, ptr %key1, i64 16
  %2 = bitcast ptr %field.20 to ptr
  %.field.ld.6 = load i64, ptr %2, align 8
  %field.21 = getelementptr inbounds i8, ptr %key2, i64 16
  %3 = bitcast ptr %field.21 to ptr
  %.field.ld.7 = load i64, ptr %3, align 8
  %icmp.34.not = icmp eq i64 %.field.ld.6, %.field.ld.7
  %. = zext i1 %icmp.34.not to i8
  br label %common.ret
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._6122_7uintptr..eq(ptr nest nocapture readnone %nest.11, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.5 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 976)
  ret i8 %call.5
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._68_7uint64..eq(ptr nest nocapture readnone %nest.12, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.6 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 64)
  ret i8 %call.6
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._6128_7uint8..eq(ptr nest nocapture readnone %nest.13, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.7 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 128)
  ret i8 %call.7
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._64096_7uint8..eq(ptr nest nocapture readnone %nest.14, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.8 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 4096)
  ret i8 %call.8
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._668_7uint16..eq(ptr nest nocapture readnone %nest.15, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.9 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 136)
  ret i8 %call.9
}

; Function Attrs: null_pointer_is_valid
define i8 @main._633_7float64..eq(ptr nest nocapture readnone %nest.16, ptr readonly %key1, ptr readonly %key2) #0 {
entry:
  %cast.40 = bitcast ptr %key1 to ptr
  %cast.41 = bitcast ptr %key2 to ptr
  %icmp.39 = icmp eq ptr %key1, null
  br i1 %icmp.39, label %then.35.split, label %entry.split, !make.implicit !3

entry.split:                                      ; preds = %entry
  %icmp.40 = icmp eq ptr %key2, null
  br i1 %icmp.40, label %then.36.split, label %then.38, !make.implicit !3

label.0:                                          ; preds = %then.38
  %add.3 = add nuw nsw i64 %tmpv.53.011, 1
  %index.2.1 = getelementptr [33 x double], ptr %cast.40, i64 0, i64 %add.3
  %.index.ld.0.1 = load double, ptr %index.2.1, align 8
  %index.3.1 = getelementptr [33 x double], ptr %cast.41, i64 0, i64 %add.3
  %.index.ld.1.1 = load double, ptr %index.3.1, align 8
  %fcmp.0.1 = fcmp une double %.index.ld.0.1, %.index.ld.1.1
  br i1 %fcmp.0.1, label %common.ret, label %label.0.1

label.0.1:                                        ; preds = %label.0
  %add.3.1 = add nuw nsw i64 %tmpv.53.011, 2
  %index.2.2 = getelementptr [33 x double], ptr %cast.40, i64 0, i64 %add.3.1
  %.index.ld.0.2 = load double, ptr %index.2.2, align 8
  %index.3.2 = getelementptr [33 x double], ptr %cast.41, i64 0, i64 %add.3.1
  %.index.ld.1.2 = load double, ptr %index.3.2, align 8
  %fcmp.0.2 = fcmp une double %.index.ld.0.2, %.index.ld.1.2
  br i1 %fcmp.0.2, label %common.ret, label %label.0.2

label.0.2:                                        ; preds = %label.0.1
  %add.3.2 = add nuw nsw i64 %tmpv.53.011, 3
  %exitcond.not.2 = icmp eq i64 %add.3.2, 33
  br i1 %exitcond.not.2, label %common.ret, label %then.38

then.35.split:                                    ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

then.36.split:                                    ; preds = %entry.split
  call void @runtime.panicmem(ptr nest undef)
  unreachable

common.ret:                                       ; preds = %then.38, %label.0.2, %label.0.1, %label.0
  %common.ret.op = phi i8 [ 0, %then.38 ], [ 0, %label.0 ], [ 0, %label.0.1 ], [ 1, %label.0.2 ]
  ret i8 %common.ret.op

then.38:                                          ; preds = %label.0.2, %entry.split
  %tmpv.53.011 = phi i64 [ %add.3.2, %label.0.2 ], [ 0, %entry.split ]
  %index.2 = getelementptr [33 x double], ptr %cast.40, i64 0, i64 %tmpv.53.011
  %.index.ld.0 = load double, ptr %index.2, align 8
  %index.3 = getelementptr [33 x double], ptr %cast.41, i64 0, i64 %tmpv.53.011
  %.index.ld.1 = load double, ptr %index.3, align 8
  %fcmp.0 = fcmp une double %.index.ld.0, %.index.ld.1
  br i1 %fcmp.0, label %common.ret, label %label.0
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._665_7uint32..eq(ptr nest nocapture readnone %nest.17, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.10 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 260)
  ret i8 %call.10
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._64_7uintptr..eq(ptr nest nocapture readnone %nest.18, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.11 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 32)
  ret i8 %call.11
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._65_7uint..eq(ptr nest nocapture readnone %nest.19, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.12 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 40)
  ret i8 %call.12
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._6512_7uint8..eq(ptr nest nocapture readnone %nest.20, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.13 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 512)
  ret i8 %call.13
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._6249_7uint8..eq(ptr nest nocapture readnone %nest.21, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.14 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 249)
  ret i8 %call.14
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._6129_7uint8..eq(ptr nest nocapture readnone %nest.22, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.15 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 129)
  ret i8 %call.15
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._632_7uint8..eq(ptr nest nocapture readnone %nest.23, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.16 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 32)
  ret i8 %call.16
}

; Function Attrs: null_pointer_is_valid
define i8 @main._627_7string..eq(ptr nest nocapture readnone %nest.24, ptr readonly %key1, ptr readonly %key2) #0 {
entry:
  %cast.44 = bitcast ptr %key1 to ptr
  %cast.45 = bitcast ptr %key2 to ptr
  %icmp.46 = icmp eq ptr %key1, null
  br i1 %icmp.46, label %then.41.split, label %entry.split, !make.implicit !3

entry.split:                                      ; preds = %entry
  %icmp.47 = icmp eq ptr %key2, null
  br i1 %icmp.47, label %then.42.split, label %then.46, !make.implicit !3

then.41.split:                                    ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

then.42.split:                                    ; preds = %entry.split
  call void @runtime.panicmem(ptr nest undef)
  unreachable

then.43:                                          ; preds = %then.46
  %icmp.49 = icmp eq ptr %tmpv.69.sroa.0.0.copyload, %tmpv.71.sroa.0.0.copyload
  br i1 %icmp.49, label %else.45, label %fallthrough.43

fallthrough.43:                                   ; preds = %then.43
  %call.17 = call i32 @memcmp(ptr %tmpv.69.sroa.0.0.copyload, ptr %tmpv.71.sroa.0.0.copyload, i64 %tmpv.69.sroa.3.0.copyload)
  %icmp.50 = icmp eq i32 %call.17, 0
  br i1 %icmp.50, label %else.45, label %common.ret

common.ret:                                       ; preds = %then.46, %else.45, %fallthrough.43
  %common.ret.op = phi i8 [ 0, %fallthrough.43 ], [ 1, %else.45 ], [ 0, %then.46 ]
  ret i8 %common.ret.op

else.45:                                          ; preds = %fallthrough.43, %then.43
  %add.4 = add nuw nsw i64 %tmpv.67.019, 1
  %exitcond.not = icmp eq i64 %add.4, 27
  br i1 %exitcond.not, label %common.ret, label %then.46

then.46:                                          ; preds = %else.45, %entry.split
  %tmpv.67.019 = phi i64 [ %add.4, %else.45 ], [ 0, %entry.split ]
  %tmpv.69.sroa.0.0.cast.48.sroa_idx = getelementptr [27 x { ptr, i64 }], ptr %cast.44, i64 0, i64 %tmpv.67.019, i32 0
  %tmpv.69.sroa.0.0.copyload = load ptr, ptr %tmpv.69.sroa.0.0.cast.48.sroa_idx, align 8
  %tmpv.69.sroa.3.0.cast.48.sroa_idx3 = getelementptr [27 x { ptr, i64 }], ptr %cast.44, i64 0, i64 %tmpv.67.019, i32 1
  %tmpv.69.sroa.3.0.copyload = load i64, ptr %tmpv.69.sroa.3.0.cast.48.sroa_idx3, align 8
  %tmpv.71.sroa.0.0.cast.51.sroa_idx = getelementptr [27 x { ptr, i64 }], ptr %cast.45, i64 0, i64 %tmpv.67.019, i32 0
  %tmpv.71.sroa.0.0.copyload = load ptr, ptr %tmpv.71.sroa.0.0.cast.51.sroa_idx, align 8
  %tmpv.71.sroa.3.0.cast.51.sroa_idx1 = getelementptr [27 x { ptr, i64 }], ptr %cast.45, i64 0, i64 %tmpv.67.019, i32 1
  %tmpv.71.sroa.3.0.copyload = load i64, ptr %tmpv.71.sroa.3.0.cast.51.sroa_idx1, align 8
  %icmp.48 = icmp eq i64 %tmpv.69.sroa.3.0.copyload, %tmpv.71.sroa.3.0.copyload
  br i1 %icmp.48, label %then.43, label %common.ret
}

; Function Attrs: mustprogress nofree nounwind null_pointer_is_valid willreturn memory(argmem: read)
declare i32 @memcmp(ptr nocapture, ptr nocapture, i64) local_unnamed_addr #5

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._61024_7uint8..eq(ptr nest nocapture readnone %nest.25, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.18 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 1024)
  ret i8 %call.18
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._62_7int32..eq(ptr nest nocapture readnone %nest.26, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.19 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 8)
  ret i8 %call.19
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._664_7uint8..eq(ptr nest nocapture readnone %nest.27, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.20 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 64)
  ret i8 %call.20
}

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._6256_7uint8..eq(ptr nest nocapture readnone %nest.28, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.21 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 256)
  ret i8 %call.21
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(ptr, i64, ptr) local_unnamed_addr #0

; Function Attrs: null_pointer_is_valid
declare void @internal_1cpu..import(ptr) local_unnamed_addr #0

; Function Attrs: null_pointer_is_valid
declare void @runtime..import(ptr) local_unnamed_addr #0

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare void @llvm.dbg.value(metadata, metadata, metadata) #6

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind null_pointer_is_valid willreturn memory(none) "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { noreturn null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #3 = { nofree null_pointer_is_valid memory(read) "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #4 = { nofree null_pointer_is_valid memory(argmem: read) "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #5 = { mustprogress nofree nounwind null_pointer_is_valid willreturn memory(argmem: read) "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #6 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 8, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
!3 = !{}
