; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/go/1_fpr_lt_0.bc'
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
module asm "\09.ascii \22 44\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -8>, ? <type -8>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22fpr_lt\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22x\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22y\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:804>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/liboqs/variants/go/1_fpr_lt_0.go:3\\n var sx <type -4> = $convert(<type -4>, x) //4\\n var sy <type -4> = $convert(<type -4>, y) //5\\n { //6\\n  if ((sx < $convert(<type -4>, 0 )) && (sy < $convert(<type -4>, 0 ))) { //6\\n   { //7\\n    $ret0 = $convert(<type -3>, (((sy - sx) >> $convert(<type -12>, 63 )) & $convert(<type -4>, 1 ))) //7\\n    return //7\\n   } //0\\n  } else { //8\\n   { //8\\n    if ((sx < $convert(<type -4>, 0 )) || (sy < $convert(<type -4>, 0 ))) { //8\\n     { //9\\n      $ret0 = $convert(<type -3>, ((sx >> $convert(<type -12>, 63 )) & $convert(<type -4>, 1 ))) //9\\n      return //9\\n     } //0\\n    } //8\\n   } //10\\n  } //6\\n } //10\\n { //11\\n  $ret0 = $convert(<type -3>, (((sx - sy) >> $convert(<type -12>, 63 )) & $convert(<type -4>, 1 ))) //11\\n  return //11\\n } //0\\n\22"
module asm "\09.ascii \22checksum D79CA0B0ABFF8F26E4F47EBB3DE919423114EC83\\n\22"
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
define i32 @main.fpr__lt(i8* nest nocapture readnone %nest.0, i64 %x, i64 %y) local_unnamed_addr #1 {
entry:
  %icmp.0 = icmp slt i64 %x, 0
  %x.lobit = lshr i64 %x, 63
  %0 = trunc i64 %x.lobit to i8
  %y.lobit24 = lshr i64 %y, 63
  %1 = trunc i64 %y.lobit24 to i8
  %tmpv.0.0 = select i1 %icmp.0, i8 %1, i8 %0
  %trunc.5.not = icmp eq i8 %tmpv.0.0, 0
  br i1 %trunc.5.not, label %else.1, label %then.1

common.ret:                                       ; preds = %else.1, %then.1
  %common.ret.op.in.in = phi i64 [ %sub.0, %then.1 ], [ %spec.select, %else.1 ]
  %common.ret.op.in = lshr i64 %common.ret.op.in.in, 63
  %common.ret.op = trunc i64 %common.ret.op.in to i32
  ret i32 %common.ret.op

then.1:                                           ; preds = %entry
  %sub.0 = sub i64 %y, %x
  br label %common.ret

else.1:                                           ; preds = %entry
  %tmpv.2.0 = select i1 %icmp.0, i8 %0, i8 %1
  %trunc.4.not = icmp eq i8 %tmpv.2.0, 0
  %sub.1 = select i1 %trunc.4.not, i64 %y, i64 0
  %spec.select = sub i64 %x, %sub.1
  br label %common.ret
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
