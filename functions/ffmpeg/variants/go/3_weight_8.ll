; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/go/3_weight_8.bc'
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
  %mul.0 = shl i32 %offset, 1
  %icmp.0.not = icmp sgt i32 %mul.0, %i
  br i1 %icmp.0.not, label %else.0, label %label.0

else.0:                                           ; preds = %entry
  %cond = icmp eq i32 %offset, 1
  br i1 %cond, label %case.0, label %default.0

label.0:                                          ; preds = %entry
  %sub.3 = add i32 %blen, -1
  %sub.4 = sub i32 %sub.3, %mul.0
  %icmp.5.not = icmp slt i32 %sub.4, %i
  br i1 %icmp.5.not, label %else.3, label %common.ret

case.0:                                           ; preds = %else.0
  %cond1 = icmp eq i32 %i, 0
  %. = select i1 %cond1, i32 3, i32 5
  br label %common.ret

default.0:                                        ; preds = %else.0
  %mul.1 = mul i32 %i, 6
  %add.0 = add i32 %mul.1, %offset
  %icmp.3 = icmp eq i32 %mul.0, 0
  br i1 %icmp.3, label %then.1, label %else.2

common.ret:                                       ; preds = %fallthrough.4, %case.2, %fallthrough.1, %case.0, %label.0
  %common.ret.op = phi i32 [ %add.1, %fallthrough.1 ], [ %add.3, %fallthrough.4 ], [ %., %case.0 ], [ 8, %label.0 ], [ %.38, %case.2 ]
  ret i32 %common.ret.op

then.1:                                           ; preds = %default.0
  %sub.2 = sub i32 1, %add.0
  br label %fallthrough.1

fallthrough.1:                                    ; preds = %else.2, %then.1
  %tmpv.4.0 = phi i32 [ %sub.2, %then.1 ], [ %div.0, %else.2 ]
  %add.1 = add i32 %tmpv.4.0, 1
  br label %common.ret

else.2:                                           ; preds = %default.0
  %sub.1 = add i32 %mul.0, -1
  %sub.0 = add i32 %add.0, -1
  %div.0 = sdiv i32 %sub.0, %sub.1
  br label %fallthrough.1

else.3:                                           ; preds = %label.0
  %cond2 = icmp eq i32 %offset, 1
  br i1 %cond2, label %case.2, label %default.2

case.2:                                           ; preds = %else.3
  %cond3 = icmp eq i32 %sub.3, %i
  %.38 = select i1 %cond3, i32 3, i32 5
  br label %common.ret

default.2:                                        ; preds = %else.3
  %sub.8 = sub i32 %sub.3, %i
  %mul.4 = mul i32 %sub.8, 6
  %add.2 = add i32 %mul.4, %offset
  %icmp.8 = icmp eq i32 %mul.0, 0
  br i1 %icmp.8, label %then.4, label %else.5

then.4:                                           ; preds = %default.2
  %sub.11 = sub i32 1, %add.2
  br label %fallthrough.4

fallthrough.4:                                    ; preds = %else.5, %then.4
  %tmpv.8.0 = phi i32 [ %sub.11, %then.4 ], [ %div.1, %else.5 ]
  %add.3 = add i32 %tmpv.8.0, 1
  br label %common.ret

else.5:                                           ; preds = %default.2
  %sub.10 = add i32 %mul.0, -1
  %sub.9 = add i32 %add.2, -1
  %div.1 = sdiv i32 %sub.9, %sub.10
  br label %fallthrough.4
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
