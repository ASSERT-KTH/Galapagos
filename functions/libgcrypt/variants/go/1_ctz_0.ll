; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/go/1_ctz_0.bc'
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
module asm "\09.ascii \22types 2 1\22"
module asm "\09.ascii \22 31\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -8>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22ctz\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22in\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum BD867D32377286D84CDB97A14A65D39675B83706\\n\22"
module asm "\09.text"

@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: null_pointer_is_valid
define i32 @main.ctz(i8* nest nocapture readnone %nest.0, i64 %in) local_unnamed_addr #0 {
entry:
  br label %then.3

else.2:                                           ; preds = %then.3
  %add.1 = or i64 %i.010, 1
  %0 = shl nuw i64 1, %add.1
  %1 = and i64 %0, %in
  %icmp.2.not.1 = icmp eq i64 %1, 0
  br i1 %icmp.2.not.1, label %else.2.1, label %label.2.split.loop.exit12

else.2.1:                                         ; preds = %else.2
  %add.1.1 = or i64 %i.010, 2
  %2 = shl nuw i64 1, %add.1.1
  %3 = and i64 %2, %in
  %icmp.2.not.2 = icmp eq i64 %3, 0
  br i1 %icmp.2.not.2, label %else.2.2, label %label.2.split.loop.exit12

else.2.2:                                         ; preds = %else.2.1
  %add.1.2 = or i64 %i.010, 3
  %4 = shl nuw i64 1, %add.1.2
  %5 = and i64 %4, %in
  %icmp.2.not.3 = icmp eq i64 %5, 0
  br i1 %icmp.2.not.3, label %else.2.3, label %label.2.split.loop.exit12

else.2.3:                                         ; preds = %else.2.2
  %add.1.3 = add nuw nsw i64 %i.010, 4
  %exitcond.not.3 = icmp eq i64 %add.1.3, 64
  br i1 %exitcond.not.3, label %label.2, label %then.3

label.2.split.loop.exit12:                        ; preds = %then.3, %else.2.2, %else.2.1, %else.2
  %i.010.lcssa = phi i64 [ %i.010, %then.3 ], [ %add.1, %else.2 ], [ %add.1.1, %else.2.1 ], [ %add.1.2, %else.2.2 ]
  %indvars11.le = trunc i64 %i.010.lcssa to i32
  br label %label.2

label.2:                                          ; preds = %label.2.split.loop.exit12, %else.2.3
  %r.0.lcssa = phi i32 [ %indvars11.le, %label.2.split.loop.exit12 ], [ 64, %else.2.3 ]
  ret i32 %r.0.lcssa

then.3:                                           ; preds = %else.2.3, %entry
  %i.010 = phi i64 [ 0, %entry ], [ %add.1.3, %else.2.3 ]
  %6 = shl nuw i64 1, %i.010
  %7 = and i64 %6, %in
  %icmp.2.not = icmp eq i64 %7, 0
  br i1 %icmp.2.not, label %else.2, label %label.2.split.loop.exit12
}

; Function Attrs: nofree norecurse nosync nounwind null_pointer_is_valid readnone
define void @main.main(i8* nest nocapture readnone %nest.1) local_unnamed_addr #1 {
entry:
  ret void
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(i8*, i64, i8*) local_unnamed_addr #0

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { nofree norecurse nosync nounwind null_pointer_is_valid readnone "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
