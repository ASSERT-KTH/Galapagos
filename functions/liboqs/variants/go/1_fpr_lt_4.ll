; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/go/1_fpr_lt_4.bc'
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
module asm "\09.ascii \22 <inl:730>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/liboqs/variants/go/1_fpr_lt_4.go:3\\n { //4\\n  if ((($convert(<type -4>, x) >= $convert(<type -4>, 0 )) && ($convert(<type -4>, y) >= $convert(<type -4>, 0 ))) || (($convert(<type -4>, x) < $convert(<type -4>, 0 )) && ($convert(<type -4>, y) < $convert(<type -4>, 0 )))) { //4\\n   { //5\\n    $ret0 = $convert(<type -3>, ((($convert(<type -4>, x) - $convert(<type -4>, y)) >> $convert(<type -12>, 63 )) & $convert(<type -4>, 1 ))) //5\\n    return //5\\n   } //0\\n  } //4\\n } //6\\n { //7\\n  if ($convert(<type -4>, x) < $convert(<type -4>, 0 )) { //7\\n   { //8\\n    $ret0 = $convert(<type -3>, 1 ) //8\\n    return //8\\n   } //0\\n  } //7\\n } //9\\n { //10\\n  $ret0 = $convert(<type -3>, 0 ) //10\\n  return //10\\n } //0\\n\22"
module asm "\09.ascii \22checksum 349E95E1D4E43D28615D1DA93104807B5CC62B4D\\n\22"
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
  %icmp.0 = icmp sgt i64 %x, -1
  %spec.select = select i1 %icmp.0, i64 %y, i64 %x
  %tmpv.0.0.in.in = lshr i64 %spec.select, 63
  %tmpv.0.0.in = trunc i64 %tmpv.0.0.in.in to i8
  %tmpv.0.0 = xor i8 %tmpv.0.0.in, 1
  %icmp.4.not = icmp eq i8 %tmpv.0.0, 0
  %icmp.2 = icmp slt i64 %x, 0
  %spec.select17 = select i1 %icmp.2, i64 %y, i64 %x
  %tmpv.2.0.in = lshr i64 %spec.select17, 63
  %tmpv.2.0 = trunc i64 %tmpv.2.0.in to i8
  %tmpv.1.0 = select i1 %icmp.4.not, i8 %tmpv.2.0, i8 %tmpv.0.0
  %trunc.4.not = icmp eq i8 %tmpv.1.0, 0
  %sub.0 = select i1 %trunc.4.not, i64 0, i64 %y
  %common.ret.op.v.v = sub i64 %x, %sub.0
  %common.ret.op.v = lshr i64 %common.ret.op.v.v, 63
  %common.ret.op = trunc i64 %common.ret.op.v to i32
  ret i32 %common.ret.op
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
