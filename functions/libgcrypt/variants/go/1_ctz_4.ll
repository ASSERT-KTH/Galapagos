; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/go/1_ctz_4.bc'
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

; Function Attrs: nofree norecurse nosync nounwind null_pointer_is_valid readnone
define i32 @main.ctz(i8* nest nocapture readnone %nest.0, i64 %in) local_unnamed_addr #1 {
entry:
  br label %label.0

label.0:                                          ; preds = %then.2.3, %entry
  %i.0 = phi i64 [ 0, %entry ], [ %add.1.3, %then.2.3 ]
  %0 = lshr i64 -9223372036854775808, %i.0
  %1 = and i64 %0, %in
  %icmp.2 = icmp eq i64 %1, 0
  br i1 %icmp.2, label %then.2, label %label.2.split.loop.exit

label.2.split.loop.exit:                          ; preds = %then.2.2, %then.2.1, %then.2, %label.0
  %i.0.lcssa = phi i64 [ %i.0, %label.0 ], [ %add.1, %then.2 ], [ %add.1.1, %then.2.1 ], [ %add.1.2, %then.2.2 ]
  %indvars8.le = trunc i64 %i.0.lcssa to i32
  br label %label.2

label.2:                                          ; preds = %then.2.3, %label.2.split.loop.exit
  %r.1 = phi i32 [ %indvars8.le, %label.2.split.loop.exit ], [ 64, %then.2.3 ]
  ret i32 %r.1

then.2:                                           ; preds = %label.0
  %add.1 = or i64 %i.0, 1
  %2 = lshr i64 -9223372036854775808, %add.1
  %3 = and i64 %2, %in
  %icmp.2.1 = icmp eq i64 %3, 0
  br i1 %icmp.2.1, label %then.2.1, label %label.2.split.loop.exit

then.2.1:                                         ; preds = %then.2
  %add.1.1 = or i64 %i.0, 2
  %4 = lshr i64 -9223372036854775808, %add.1.1
  %5 = and i64 %4, %in
  %icmp.2.2 = icmp eq i64 %5, 0
  br i1 %icmp.2.2, label %then.2.2, label %label.2.split.loop.exit

then.2.2:                                         ; preds = %then.2.1
  %add.1.2 = or i64 %i.0, 3
  %6 = lshr i64 -9223372036854775808, %add.1.2
  %7 = and i64 %6, %in
  %icmp.2.3 = icmp eq i64 %7, 0
  br i1 %icmp.2.3, label %then.2.3, label %label.2.split.loop.exit

then.2.3:                                         ; preds = %then.2.2
  %add.1.3 = add nuw nsw i64 %i.0, 4
  %exitcond.3 = icmp eq i64 %add.1.3, 64
  br i1 %exitcond.3, label %label.2, label %label.0
}

; Function Attrs: nofree norecurse nosync nounwind null_pointer_is_valid readnone
define void @main.main(i8* nest nocapture %nest.1) local_unnamed_addr #1 {
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
