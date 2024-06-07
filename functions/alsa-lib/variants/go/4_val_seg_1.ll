; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/4_val_seg_1.bc'
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
module asm "\09.ascii \22 32\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -3>) <type -11>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22valSeg\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22val\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -11>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum 6B2A8299694C9B0CE50EC04EB07F699DD19A0FAF\\n\22"
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
define i64 @main.valSeg(i8* nest nocapture readnone %nest.0, i32 %val) local_unnamed_addr #1 {
entry:
  %shr.0 = ashr i32 %val, 8
  %0 = and i32 %val, 61440
  %icmp.0.not17 = icmp eq i32 %0, 0
  br i1 %icmp.0.not17, label %label.2.preheader, label %then.0

label.2.preheader:                                ; preds = %then.0, %entry
  %val.addr.0.lcssa = phi i32 [ %shr.0, %entry ], [ %shr.1, %then.0 ]
  %r.0.lcssa = phi i64 [ 1, %entry ], [ %add.0, %then.0 ]
  %iand.111 = and i32 %val.addr.0.lcssa, 12
  %icmp.1.not12 = icmp eq i32 %iand.111, 0
  br i1 %icmp.1.not12, label %else.1, label %then.1

then.0:                                           ; preds = %then.0, %entry
  %r.019 = phi i64 [ %add.0, %then.0 ], [ 1, %entry ]
  %val.addr.018 = phi i32 [ %shr.1, %then.0 ], [ %shr.0, %entry ]
  %shr.1 = ashr i32 %val.addr.018, 4
  %add.0 = add i64 %r.019, 4
  %1 = and i32 %val.addr.018, 3840
  %icmp.0.not = icmp eq i32 %1, 0
  br i1 %icmp.0.not, label %label.2.preheader, label %then.0

then.1:                                           ; preds = %then.1, %label.2.preheader
  %r.114 = phi i64 [ %add.1, %then.1 ], [ %r.0.lcssa, %label.2.preheader ]
  %val.addr.113 = phi i32 [ %shr.2, %then.1 ], [ %val.addr.0.lcssa, %label.2.preheader ]
  %shr.2 = ashr i32 %val.addr.113, 2
  %add.1 = add i64 %r.114, 2
  %2 = and i32 %val.addr.113, 48
  %icmp.1.not = icmp eq i32 %2, 0
  br i1 %icmp.1.not, label %else.1, label %then.1

else.1:                                           ; preds = %then.1, %label.2.preheader
  %val.addr.1.lcssa = phi i32 [ %val.addr.0.lcssa, %label.2.preheader ], [ %shr.2, %then.1 ]
  %r.1.lcssa = phi i64 [ %r.0.lcssa, %label.2.preheader ], [ %add.1, %then.1 ]
  %iand.2 = lshr i32 %val.addr.1.lcssa, 1
  %iand.2.lobit = and i32 %iand.2, 1
  %3 = zext i32 %iand.2.lobit to i64
  %spec.select = add i64 %r.1.lcssa, %3
  ret i64 %spec.select
}

; Function Attrs: nofree norecurse nosync nounwind null_pointer_is_valid readnone
define void @main.main(i8* nest nocapture %nest.1) local_unnamed_addr #1 {
entry:
  %call.0 = call i64 @main.valSeg(i8* nest undef, i32 0)
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
