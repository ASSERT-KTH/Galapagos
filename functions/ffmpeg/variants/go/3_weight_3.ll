; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/go/3_weight_3.bc'
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
module asm "\09.ascii \22 57\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -3>, ? <type -3>, ? <type -3>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22weight\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22i\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22blen\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22offset\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum B2A44A0C29B007A95BB571C4C30973552F839477\\n\22"
module asm "\09.text"

@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define i32 @main.weight(i8* nest nocapture readnone %nest.0, i32 %i, i32 %blen, i32 %offset) local_unnamed_addr #1 {
entry:
  %mul.2 = shl i32 %offset, 1
  %icmp.4 = icmp sgt i32 %mul.2, %i
  br i1 %icmp.4, label %then.0, label %else.0

then.0:                                           ; preds = %entry
  %icmp.1 = icmp eq i32 %offset, 1
  br i1 %icmp.1, label %then.1, label %else.1

else.0:                                           ; preds = %entry
  %sub.10 = add i32 %blen, -1
  %sub.11 = sub i32 %sub.10, %mul.2
  %icmp.9 = icmp slt i32 %sub.11, %i
  br i1 %icmp.9, label %then.5, label %common.ret

then.1:                                           ; preds = %then.0
  %icmp.0 = icmp sgt i32 %i, 0
  %. = select i1 %icmp.0, i32 5, i32 3
  br label %common.ret

else.1:                                           ; preds = %then.0
  %mul.0 = mul i32 %i, 6
  %add.0 = add i32 %mul.0, %offset
  %icmp.2 = icmp eq i32 %mul.2, 0
  br i1 %icmp.2, label %then.3, label %else.4

common.ret:                                       ; preds = %fallthrough.8, %then.6, %fallthrough.3, %then.1, %else.0
  %common.ret.op = phi i32 [ %add.1, %fallthrough.3 ], [ %add.3, %fallthrough.8 ], [ %., %then.1 ], [ 8, %else.0 ], [ %.34, %then.6 ]
  ret i32 %common.ret.op

then.3:                                           ; preds = %else.1
  %sub.2 = sub i32 1, %add.0
  br label %fallthrough.3

fallthrough.3:                                    ; preds = %else.4, %then.3
  %tmpv.3.0 = phi i32 [ %sub.2, %then.3 ], [ %div.0, %else.4 ]
  %add.1 = add i32 %tmpv.3.0, 1
  br label %common.ret

else.4:                                           ; preds = %else.1
  %sub.1 = add i32 %mul.2, -1
  %sub.0 = add i32 %add.0, -1
  %div.0 = sdiv i32 %sub.0, %sub.1
  br label %fallthrough.3

then.5:                                           ; preds = %else.0
  %icmp.6 = icmp eq i32 %offset, 1
  %sub.4 = sub i32 %sub.10, %i
  br i1 %icmp.6, label %then.6, label %else.6

then.6:                                           ; preds = %then.5
  %icmp.5 = icmp sgt i32 %sub.4, 0
  %.34 = select i1 %icmp.5, i32 5, i32 3
  br label %common.ret

else.6:                                           ; preds = %then.5
  %mul.3 = mul i32 %sub.4, 6
  %add.2 = add i32 %mul.3, %offset
  %icmp.7 = icmp eq i32 %mul.2, 0
  br i1 %icmp.7, label %then.8, label %else.9

then.8:                                           ; preds = %else.6
  %sub.9 = sub i32 1, %add.2
  br label %fallthrough.8

fallthrough.8:                                    ; preds = %else.9, %then.8
  %tmpv.7.0 = phi i32 [ %sub.9, %then.8 ], [ %div.1, %else.9 ]
  %add.3 = add i32 %tmpv.7.0, 1
  br label %common.ret

else.9:                                           ; preds = %else.6
  %sub.8 = add i32 %mul.2, -1
  %sub.7 = add i32 %add.2, -1
  %div.1 = sdiv i32 %sub.7, %sub.8
  br label %fallthrough.8
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define void @main.main(i8* nest nocapture %nest.1) local_unnamed_addr #1 {
entry:
  ret void
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(i8*, i64, i8*) local_unnamed_addr #0

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
