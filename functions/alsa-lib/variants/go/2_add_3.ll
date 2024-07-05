; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/2_add_3.bc'
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
module asm "\09.ascii \22 44\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -7>, ? <type -7>) <type -7>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22add\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22a\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22b\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:249>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/2_add_3.go:3\\n { //4\\n  if ((a + b) < a) { //4\\n   { //5\\n    $ret0 = $convert(<type -7>, 4294967295 ) //5\\n    return //5\\n   } //0\\n  } //4\\n } //6\\n { //7\\n  $ret0 = (a + b) //7\\n  return //7\\n } //0\\n\22"
module asm "\09.ascii \22checksum DCF513DF6389A338F666E7074BF228C6A4D5CE41\\n\22"
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
define i32 @main.add(ptr nest nocapture readnone %nest.0, i32 %a, i32 %b) local_unnamed_addr #1 {
entry:
  %0 = call i32 @llvm.uadd.sat.i32(i32 %a, i32 %b)
  ret i32 %0
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
  %icmp.5 = icmp eq ptr %key1, null
  br i1 %icmp.5, label %then.6, label %else.6, !make.implicit !3

then.6:                                           ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.6:                                           ; preds = %entry
  %icmp.6 = icmp eq ptr %key2, null
  br i1 %icmp.6, label %then.7, label %else.7, !make.implicit !3

then.7:                                           ; preds = %else.6
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.7:                                           ; preds = %else.6
  %tmpv.8.sroa.0.0.cast.10.sroa_idx = bitcast ptr %key1 to ptr
  %tmpv.8.sroa.0.0.copyload = load i64, ptr %tmpv.8.sroa.0.0.cast.10.sroa_idx, align 8
  %tmpv.9.sroa.0.0.cast.15.sroa_idx = bitcast ptr %key2 to ptr
  %tmpv.9.sroa.0.0.copyload = load i64, ptr %tmpv.9.sroa.0.0.cast.15.sroa_idx, align 8
  %icmp.7.not = icmp eq i64 %tmpv.8.sroa.0.0.copyload, %tmpv.9.sroa.0.0.copyload
  br i1 %icmp.7.not, label %else.10, label %common.ret

common.ret:                                       ; preds = %else.10, %else.7
  %common.ret.op = phi i8 [ 0, %else.7 ], [ %., %else.10 ]
  ret i8 %common.ret.op

else.10:                                          ; preds = %else.7
  %field.8 = getelementptr inbounds i8, ptr %key1, i64 8
  %0 = bitcast ptr %field.8 to ptr
  %.field.ld.0 = load i32, ptr %0, align 4
  %field.9 = getelementptr inbounds i8, ptr %key2, i64 8
  %1 = bitcast ptr %field.9 to ptr
  %.field.ld.1 = load i32, ptr %1, align 4
  %icmp.11.not = icmp eq i32 %.field.ld.0, %.field.ld.1
  %. = zext i1 %icmp.11.not to i8
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
  %icmp.14 = icmp eq ptr %key1, null
  br i1 %icmp.14, label %then.14.split, label %entry.split, !make.implicit !3

entry.split:                                      ; preds = %entry
  %icmp.17 = icmp eq ptr %key2, null
  br i1 %icmp.17, label %then.16.split, label %then.20, !make.implicit !3

label.0:                                          ; preds = %then.20
  %add.2 = add nuw nsw i64 %tmpv.22.018, 1
  %exitcond.not = icmp eq i64 %add.2, 61
  br i1 %exitcond.not, label %common.ret, label %then.20

then.14.split:                                    ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

then.16.split:                                    ; preds = %entry.split
  call void @runtime.panicmem(ptr nest undef)
  unreachable

common.ret:                                       ; preds = %then.20, %label.0
  %common.ret.op = phi i8 [ 0, %then.20 ], [ 1, %label.0 ]
  ret i8 %common.ret.op

then.20:                                          ; preds = %label.0, %entry.split
  %tmpv.22.018 = phi i64 [ %add.2, %label.0 ], [ 0, %entry.split ]
  %tmpv.24.sroa.4.0.cast.24.sroa_idx7 = getelementptr [61 x { i32, i64, i64 }], ptr %cast.20, i64 0, i64 %tmpv.22.018, i32 2
  %tmpv.24.sroa.4.0.copyload = load i64, ptr %tmpv.24.sroa.4.0.cast.24.sroa_idx7, align 8
  %tmpv.24.sroa.3.0.cast.24.sroa_idx6 = getelementptr [61 x { i32, i64, i64 }], ptr %cast.20, i64 0, i64 %tmpv.22.018, i32 1
  %tmpv.24.sroa.3.0.copyload = load i64, ptr %tmpv.24.sroa.3.0.cast.24.sroa_idx6, align 8
  %tmpv.24.sroa.0.0.cast.24.sroa_idx = getelementptr [61 x { i32, i64, i64 }], ptr %cast.20, i64 0, i64 %tmpv.22.018, i32 0
  %tmpv.24.sroa.0.0.copyload = load i32, ptr %tmpv.24.sroa.0.0.cast.24.sroa_idx, align 8
  %tmpv.25.sroa.0.0.cast.29.sroa_idx = getelementptr [61 x { i32, i64, i64 }], ptr %cast.21, i64 0, i64 %tmpv.22.018, i32 0
  %tmpv.25.sroa.0.0.copyload = load i32, ptr %tmpv.25.sroa.0.0.cast.29.sroa_idx, align 8
  %tmpv.25.sroa.3.0.cast.29.sroa_idx4 = getelementptr [61 x { i32, i64, i64 }], ptr %cast.21, i64 0, i64 %tmpv.22.018, i32 1
  %tmpv.25.sroa.3.0.copyload = load i64, ptr %tmpv.25.sroa.3.0.cast.29.sroa_idx4, align 8
  %tmpv.25.sroa.4.0.cast.29.sroa_idx5 = getelementptr [61 x { i32, i64, i64 }], ptr %cast.21, i64 0, i64 %tmpv.22.018, i32 2
  %tmpv.25.sroa.4.0.copyload = load i64, ptr %tmpv.25.sroa.4.0.cast.29.sroa_idx5, align 8
  %icmp.18 = icmp eq i32 %tmpv.24.sroa.0.0.copyload, %tmpv.25.sroa.0.0.copyload
  %icmp.19 = icmp eq i64 %tmpv.24.sroa.3.0.copyload, %tmpv.25.sroa.3.0.copyload
  %tmpv.31.0.in = select i1 %icmp.18, i1 %icmp.19, i1 false
  %icmp.20 = icmp eq i64 %tmpv.24.sroa.4.0.copyload, %tmpv.25.sroa.4.0.copyload
  %tmpv.32.0.in = select i1 %tmpv.31.0.in, i1 %icmp.20, i1 false
  br i1 %tmpv.32.0.in, label %label.0, label %common.ret
}

; Function Attrs: null_pointer_is_valid
define i8 @main.struct_4Size_buint32_cMallocs_buint64_cFrees_buint64_5..eq(ptr nest nocapture readnone %nest.10, ptr readonly %key1, ptr readonly %key2) #0 {
entry:
  %icmp.23 = icmp eq ptr %key1, null
  br i1 %icmp.23, label %then.21, label %else.21, !make.implicit !3

then.21:                                          ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.21:                                          ; preds = %entry
  %icmp.24 = icmp eq ptr %key2, null
  br i1 %icmp.24, label %then.22, label %else.22, !make.implicit !3

then.22:                                          ; preds = %else.21
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.22:                                          ; preds = %else.21
  %field.16 = bitcast ptr %key1 to ptr
  %.field.ld.2 = load i32, ptr %field.16, align 4
  %field.17 = bitcast ptr %key2 to ptr
  %.field.ld.3 = load i32, ptr %field.17, align 4
  %icmp.25.not = icmp eq i32 %.field.ld.2, %.field.ld.3
  br i1 %icmp.25.not, label %else.25, label %common.ret

common.ret:                                       ; preds = %else.28, %else.25, %else.22
  %common.ret.op = phi i8 [ 0, %else.22 ], [ 0, %else.25 ], [ %., %else.28 ]
  ret i8 %common.ret.op

else.25:                                          ; preds = %else.22
  %field.18 = getelementptr inbounds i8, ptr %key1, i64 8
  %0 = bitcast ptr %field.18 to ptr
  %.field.ld.4 = load i64, ptr %0, align 8
  %field.19 = getelementptr inbounds i8, ptr %key2, i64 8
  %1 = bitcast ptr %field.19 to ptr
  %.field.ld.5 = load i64, ptr %1, align 8
  %icmp.28.not = icmp eq i64 %.field.ld.4, %.field.ld.5
  br i1 %icmp.28.not, label %else.28, label %common.ret

else.28:                                          ; preds = %else.25
  %field.20 = getelementptr inbounds i8, ptr %key1, i64 16
  %2 = bitcast ptr %field.20 to ptr
  %.field.ld.6 = load i64, ptr %2, align 8
  %field.21 = getelementptr inbounds i8, ptr %key2, i64 16
  %3 = bitcast ptr %field.21 to ptr
  %.field.ld.7 = load i64, ptr %3, align 8
  %icmp.31.not = icmp eq i64 %.field.ld.6, %.field.ld.7
  %. = zext i1 %icmp.31.not to i8
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
  %icmp.36 = icmp eq ptr %key1, null
  br i1 %icmp.36, label %then.32.split, label %entry.split, !make.implicit !3

entry.split:                                      ; preds = %entry
  %icmp.37 = icmp eq ptr %key2, null
  br i1 %icmp.37, label %then.33.split, label %then.35, !make.implicit !3

label.0:                                          ; preds = %then.35
  %add.3 = add nuw nsw i64 %tmpv.49.011, 1
  %index.2.1 = getelementptr [33 x double], ptr %cast.40, i64 0, i64 %add.3
  %.index.ld.0.1 = load double, ptr %index.2.1, align 8
  %index.3.1 = getelementptr [33 x double], ptr %cast.41, i64 0, i64 %add.3
  %.index.ld.1.1 = load double, ptr %index.3.1, align 8
  %fcmp.0.1 = fcmp une double %.index.ld.0.1, %.index.ld.1.1
  br i1 %fcmp.0.1, label %common.ret, label %label.0.1

label.0.1:                                        ; preds = %label.0
  %add.3.1 = add nuw nsw i64 %tmpv.49.011, 2
  %index.2.2 = getelementptr [33 x double], ptr %cast.40, i64 0, i64 %add.3.1
  %.index.ld.0.2 = load double, ptr %index.2.2, align 8
  %index.3.2 = getelementptr [33 x double], ptr %cast.41, i64 0, i64 %add.3.1
  %.index.ld.1.2 = load double, ptr %index.3.2, align 8
  %fcmp.0.2 = fcmp une double %.index.ld.0.2, %.index.ld.1.2
  br i1 %fcmp.0.2, label %common.ret, label %label.0.2

label.0.2:                                        ; preds = %label.0.1
  %add.3.2 = add nuw nsw i64 %tmpv.49.011, 3
  %exitcond.not.2 = icmp eq i64 %add.3.2, 33
  br i1 %exitcond.not.2, label %common.ret, label %then.35

then.32.split:                                    ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

then.33.split:                                    ; preds = %entry.split
  call void @runtime.panicmem(ptr nest undef)
  unreachable

common.ret:                                       ; preds = %then.35, %label.0.2, %label.0.1, %label.0
  %common.ret.op = phi i8 [ 0, %then.35 ], [ 0, %label.0 ], [ 0, %label.0.1 ], [ 1, %label.0.2 ]
  ret i8 %common.ret.op

then.35:                                          ; preds = %label.0.2, %entry.split
  %tmpv.49.011 = phi i64 [ %add.3.2, %label.0.2 ], [ 0, %entry.split ]
  %index.2 = getelementptr [33 x double], ptr %cast.40, i64 0, i64 %tmpv.49.011
  %.index.ld.0 = load double, ptr %index.2, align 8
  %index.3 = getelementptr [33 x double], ptr %cast.41, i64 0, i64 %tmpv.49.011
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
  %icmp.43 = icmp eq ptr %key1, null
  br i1 %icmp.43, label %then.38.split, label %entry.split, !make.implicit !3

entry.split:                                      ; preds = %entry
  %icmp.44 = icmp eq ptr %key2, null
  br i1 %icmp.44, label %then.39.split, label %then.43, !make.implicit !3

then.38.split:                                    ; preds = %entry
  call void @runtime.panicmem(ptr nest undef)
  unreachable

then.39.split:                                    ; preds = %entry.split
  call void @runtime.panicmem(ptr nest undef)
  unreachable

then.40:                                          ; preds = %then.43
  %icmp.46 = icmp eq ptr %tmpv.65.sroa.0.0.copyload, %tmpv.67.sroa.0.0.copyload
  br i1 %icmp.46, label %else.42, label %fallthrough.40

fallthrough.40:                                   ; preds = %then.40
  %call.17 = call i32 @memcmp(ptr %tmpv.65.sroa.0.0.copyload, ptr %tmpv.67.sroa.0.0.copyload, i64 %tmpv.65.sroa.3.0.copyload)
  %icmp.47 = icmp eq i32 %call.17, 0
  br i1 %icmp.47, label %else.42, label %common.ret

common.ret:                                       ; preds = %then.43, %else.42, %fallthrough.40
  %common.ret.op = phi i8 [ 0, %fallthrough.40 ], [ 1, %else.42 ], [ 0, %then.43 ]
  ret i8 %common.ret.op

else.42:                                          ; preds = %fallthrough.40, %then.40
  %add.4 = add nuw nsw i64 %tmpv.63.019, 1
  %exitcond.not = icmp eq i64 %add.4, 27
  br i1 %exitcond.not, label %common.ret, label %then.43

then.43:                                          ; preds = %else.42, %entry.split
  %tmpv.63.019 = phi i64 [ %add.4, %else.42 ], [ 0, %entry.split ]
  %tmpv.65.sroa.0.0.cast.48.sroa_idx = getelementptr [27 x { ptr, i64 }], ptr %cast.44, i64 0, i64 %tmpv.63.019, i32 0
  %tmpv.65.sroa.0.0.copyload = load ptr, ptr %tmpv.65.sroa.0.0.cast.48.sroa_idx, align 8
  %tmpv.65.sroa.3.0.cast.48.sroa_idx3 = getelementptr [27 x { ptr, i64 }], ptr %cast.44, i64 0, i64 %tmpv.63.019, i32 1
  %tmpv.65.sroa.3.0.copyload = load i64, ptr %tmpv.65.sroa.3.0.cast.48.sroa_idx3, align 8
  %tmpv.67.sroa.0.0.cast.51.sroa_idx = getelementptr [27 x { ptr, i64 }], ptr %cast.45, i64 0, i64 %tmpv.63.019, i32 0
  %tmpv.67.sroa.0.0.copyload = load ptr, ptr %tmpv.67.sroa.0.0.cast.51.sroa_idx, align 8
  %tmpv.67.sroa.3.0.cast.51.sroa_idx1 = getelementptr [27 x { ptr, i64 }], ptr %cast.45, i64 0, i64 %tmpv.63.019, i32 1
  %tmpv.67.sroa.3.0.copyload = load i64, ptr %tmpv.67.sroa.3.0.cast.51.sroa_idx1, align 8
  %icmp.45 = icmp eq i64 %tmpv.65.sroa.3.0.copyload, %tmpv.67.sroa.3.0.copyload
  br i1 %icmp.45, label %then.40, label %common.ret
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

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare i32 @llvm.uadd.sat.i32(i32, i32) #6

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
