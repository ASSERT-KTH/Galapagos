; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/go/0_fpr_lt_3.bc'
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
module asm "\09.ascii \22type 1 (? <type -4>, ? <type -4>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22fpr_lt\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22x\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -4>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22y\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -4>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:496>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/liboqs/variants/go/0_fpr_lt_3.go:3\\n var sx <type -4> = x //4\\n var sy <type -4> = y //4\\n sy = (sy & ^((sx ^ sy) >> $convert(<type -12>, 63 ))) //5\\n var cc0 <type -3> = ($convert(<type -3>, ((sx - sy) >> $convert(<type -12>, 63 ))) & 1 ) //6\\n var cc1 <type -3> = ($convert(<type -3>, ((sy - sx) >> $convert(<type -12>, 63 ))) & 1 ) //7\\n { //8\\n  $ret0 = (cc0 ^ ((cc0 ^ cc1) & $convert(<type -3>, ((x & y) >> $convert(<type -12>, 63 ))))) //8\\n  return //8\\n } //0\\n\22"
module asm "\09.ascii \22checksum 6560740210B481B519B63F4FBA0511384734F613\\n\22"
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
  %xor.0 = xor i64 %y, %x
  %isneg = icmp slt i64 %xor.0, 0
  %iand.0 = select i1 %isneg, i64 0, i64 %y
  %sub.0 = sub i64 %x, %iand.0
  %shr.114 = lshr i64 %sub.0, 63
  %trunc.0 = trunc i64 %shr.114 to i32
  %sub.1 = sub i64 %iand.0, %x
  %shr.215 = lshr i64 %sub.1, 63
  %iand.3 = and i64 %y, %x
  %xor.216 = xor i64 %shr.114, %shr.215
  %isneg18 = icmp slt i64 %iand.3, 0
  %0 = trunc i64 %xor.216 to i32
  %iand.4 = select i1 %isneg18, i32 %0, i32 0
  %xor.3 = xor i32 %iand.4, %trunc.0
  ret i32 %xor.3
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
