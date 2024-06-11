; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/go/1_fpr_lt_3.bc'
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
module asm "\09.ascii \22 <inl:560>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/liboqs/variants/go/1_fpr_lt_3.go:3\\n { //4\\n  if (($convert(<type -4>, x) & $convert(<type -4>, y)) >= $convert(<type -4>, 0 )) { //4\\n   { //5\\n    $ret0 = $convert(<type -3>, (($convert(<type -4>, x) - $convert(<type -4>, y)) >> $convert(<type -12>, 63 ))) //5\\n    return //5\\n   } //0\\n  } //4\\n } //6\\n { //7\\n  if ($convert(<type -4>, x) < $convert(<type -4>, 0 )) { //7\\n   { //8\\n    $ret0 = $convert(<type -3>, 1 ) //8\\n    return //8\\n   } //0\\n  } //7\\n } //9\\n { //10\\n  $ret0 = $convert(<type -3>, 0 ) //10\\n  return //10\\n } //0\\n\22"
module asm "\09.ascii \22checksum 4CF0C4B912C9320D8E50ACAB4D6FDA07324A5EB4\\n\22"
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
  %iand.0 = and i64 %y, %x
  %icmp.0 = icmp sgt i64 %iand.0, -1
  %sub.0 = sub i64 %x, %y
  %shr.0 = ashr i64 %sub.0, 63
  %x.lobit = lshr i64 %x, 63
  %common.ret.op.v = select i1 %icmp.0, i64 %shr.0, i64 %x.lobit
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
