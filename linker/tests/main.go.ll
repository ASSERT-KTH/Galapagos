; ModuleID = 'main.go.nod.bc'
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
module asm "\09.ascii \22types 5 1\22"
module asm "\09.ascii \22 43\22"
module asm "\09.ascii \22 17\22"
module asm "\09.ascii \22 21\22"
module asm "\09.ascii \22 22\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type 2>, ? <type -8>) <type -8>\\ntype 2 *<type 3>\\ntype 3 [5 ] <type 4>\\ntype 4 [5 ] <type -8>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22Chi\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22A\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<esc:0x1>\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type 2>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22i\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum B38E11433D2C6495FAE0859EB7A4E9ED18410564\\n\22"
module asm "\09.text"

%functionDescriptor.0 = type { i64 }

@main.Chi..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main.Chi to i64) }
@main._65_7_65_7uint64..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._65_7_65_7uint64..eq to i64) }
@main._65_7uint64..eq..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (ptr @main._65_7uint64..eq to i64) }
@main..types = constant { i64, [1 x ptr] } zeroinitializer
@go..typelists = internal constant [1 x ptr] [ptr @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(ptr nest nocapture readnone %nest.4) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(ptr nest undef, i64 1, ptr @go..typelists)
  ret void
}

; Function Attrs: null_pointer_is_valid
define i64 @main.Chi(ptr nest nocapture readnone %nest.0, ptr %A, i64 %i) #0 {
entry:
  %C = alloca [5 x i64], align 8
  %0 = bitcast ptr %C to ptr
  call void @llvm.lifetime.start.p0(i64 40, ptr nonnull %0)
  %icmp.14 = icmp eq ptr %A, null
  %index.0 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 0
  %index.7 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 1
  %index.14 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 2
  %index.21 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 3
  %index.28 = getelementptr inbounds [5 x i64], ptr %C, i64 0, i64 4
  br label %then.70

then.7:                                           ; preds = %then.70
  call void @runtime.panicmem(ptr nest undef)
  unreachable

else.7:                                           ; preds = %then.70
  %index.2 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 0
  %.index.index.ld.2 = load i64, ptr %index.2, align 8
  %index.4 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 1
  %.index.index.ld.0 = load i64, ptr %index.4, align 8
  %xor.0 = xor i64 %.index.index.ld.0, -1
  %index.6 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 2
  %.index.index.ld.1 = load i64, ptr %index.6, align 8
  %iand.7 = and i64 %.index.index.ld.1, %xor.0
  %xor.1 = xor i64 %iand.7, %.index.index.ld.2
  %xor.2 = xor i64 %.index.index.ld.1, -1
  %index.13 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 3
  %.index.index.ld.4 = load i64, ptr %index.13, align 8
  %iand.15 = and i64 %.index.index.ld.4, %xor.2
  %xor.3 = xor i64 %iand.15, %.index.index.ld.0
  %xor.4 = xor i64 %.index.index.ld.4, -1
  %index.20 = getelementptr [5 x [5 x i64]], ptr %A, i64 0, i64 %y.0103, i64 4
  %.index.index.ld.7 = load i64, ptr %index.20, align 8
  %iand.23 = and i64 %.index.index.ld.7, %xor.4
  %xor.5 = xor i64 %iand.23, %.index.index.ld.1
  %xor.6 = xor i64 %.index.index.ld.7, -1
  %iand.31 = and i64 %.index.index.ld.2, %xor.6
  %xor.7 = xor i64 %iand.31, %.index.index.ld.4
  %xor.8 = xor i64 %.index.index.ld.2, -1
  %iand.39 = and i64 %.index.index.ld.0, %xor.8
  %xor.9 = xor i64 %.index.index.ld.7, %iand.39
  store i64 %xor.1, ptr %index.2, align 8
  store i64 %xor.3, ptr %index.4, align 8
  store i64 %xor.5, ptr %index.6, align 8
  store i64 %xor.7, ptr %index.13, align 8
  store i64 %xor.9, ptr %index.20, align 8
  %add.0 = add nuw nsw i64 %y.0103, 1
  %exitcond.not = icmp eq i64 %add.0, 5
  br i1 %exitcond.not, label %else.70, label %then.70

then.70:                                          ; preds = %else.7, %entry
  %y.0103 = phi i64 [ 0, %entry ], [ %add.0, %else.7 ]
  br i1 %icmp.14, label %then.7, label %else.7, !make.implicit !3

else.70:                                          ; preds = %else.7
  store i64 %xor.1, ptr %index.0, align 8
  store i64 %xor.3, ptr %index.7, align 8
  store i64 %xor.5, ptr %index.14, align 8
  store i64 %xor.7, ptr %index.21, align 8
  store i64 %xor.9, ptr %index.28, align 8
  %1 = icmp ult i64 %i, 5
  br i1 %1, label %fallthrough.71, label %else.71

fallthrough.71:                                   ; preds = %else.70
  %index.50 = getelementptr [5 x i64], ptr %C, i64 0, i64 %i
  %C.index.ld.5 = load i64, ptr %index.50, align 8
  call void @llvm.lifetime.end.p0(i64 40, ptr nonnull %0)
  ret i64 %C.index.ld.5

else.71:                                          ; preds = %else.70
  call void @runtime.goPanicIndexU(ptr nest undef, i64 %i, i64 5)
  unreachable
}

; Function Attrs: noreturn null_pointer_is_valid
declare void @runtime.panicmem(ptr) local_unnamed_addr #1

; Function Attrs: noreturn null_pointer_is_valid
declare void @runtime.goPanicIndexU(ptr, i64, i64) local_unnamed_addr #1

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare void @llvm.dbg.declare(metadata, metadata, metadata) #2

; Function Attrs: null_pointer_is_valid
define void @main.main(ptr nest nocapture readnone %nest.1) local_unnamed_addr #0 {
entry:
  %A = alloca [5 x [5 x i64]], align 8, !go_addrtaken !3
  %0 = bitcast ptr %A to ptr
  call void @llvm.lifetime.start.p0(i64 200, ptr nonnull %0)
  call void @llvm.memset.p0.i64(ptr noundef nonnull align 8 dereferenceable(200) %0, i8 0, i64 200, i1 false)
  %call.0 = call i64 @main.Chi(ptr nest undef, ptr nonnull %A, i64 0)
  call void @runtime.printlock(ptr nest undef)
  call void @runtime.printuint(ptr nest undef, i64 %call.0)
  call void @runtime.printnl(ptr nest undef)
  call void @runtime.printunlock(ptr nest undef)
  call void @llvm.lifetime.end.p0(i64 200, ptr nonnull %0)
  ret void
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.printlock(ptr) local_unnamed_addr #0

; Function Attrs: null_pointer_is_valid
declare void @runtime.printuint(ptr, i64) local_unnamed_addr #0

; Function Attrs: null_pointer_is_valid
declare void @runtime.printnl(ptr) local_unnamed_addr #0

; Function Attrs: null_pointer_is_valid
declare void @runtime.printunlock(ptr) local_unnamed_addr #0

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._65_7_65_7uint64..eq(ptr nest nocapture readnone %nest.2, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.1 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 200)
  ret i8 %call.1
}

; Function Attrs: nofree null_pointer_is_valid memory(argmem: read)
declare i8 @runtime.memequal(ptr, ptr, ptr, i64) local_unnamed_addr #4

; Function Attrs: nofree null_pointer_is_valid memory(read)
define i8 @main._65_7uint64..eq(ptr nest nocapture readnone %nest.3, ptr readonly %key1, ptr readonly %key2) #3 {
entry:
  %call.2 = call i8 @runtime.memequal(ptr nest undef, ptr %key1, ptr %key2, i64 40)
  ret i8 %call.2
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(ptr, i64, ptr) local_unnamed_addr #0

; Function Attrs: nocallback nofree nosync nounwind speculatable willreturn memory(none)
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #5

; Function Attrs: nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #5

; Function Attrs: nocallback nofree nounwind willreturn memory(argmem: write)
declare void @llvm.memset.p0.i64(ptr nocapture writeonly, i8, i64, i1 immarg) #6

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { noreturn null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { nocallback nofree nosync nounwind speculatable willreturn memory(none) }
attributes #3 = { nofree null_pointer_is_valid memory(read) "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #4 = { nofree null_pointer_is_valid memory(argmem: read) "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #5 = { nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #6 = { nocallback nofree nounwind willreturn memory(argmem: write) }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 8, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
!3 = !{}
