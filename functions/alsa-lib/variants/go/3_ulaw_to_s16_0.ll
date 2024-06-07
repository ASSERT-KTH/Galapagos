; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/3_ulaw_to_s16_0.bc'
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
module asm "\09.ascii \22type 1 (? <type -5>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22ulaw_to_s16\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22u_val\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -5>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:591>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/3_ulaw_to_s16_0.go:3\\n var t <type -3> //4\\n u_val = ^u_val //7\\n t = (($convert(<type -3>, (u_val & $convert(<type -5>, 15 ))) << $convert(<type -12>, 3 )) + $convert(<type -3>, 132 )) //11\\n t = (t << ((u_val & $convert(<type -5>, 112 )) >> $convert(<type -12>, 4 ))) //12\\n { //14\\n  if ((u_val & $convert(<type -5>, 128 )) != $convert(<type -5>, 0 )) { //14\\n   { //15\\n    $ret0 = ($convert(<type -3>, 132 ) - t) //15\\n    return //15\\n   } //0\\n  } //14\\n } //16\\n { //17\\n  $ret0 = (t - $convert(<type -3>, 132 )) //17\\n  return //17\\n } //0\\n\22"
module asm "\09.ascii \22checksum 33E335125260D28DE92B0881F1AC757835BC685A\\n\22"
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
define i32 @main.ulaw__to__s16(i8* nest nocapture readnone %nest.0, i8 zeroext %u_val) local_unnamed_addr #1 {
entry:
  %xor.0 = xor i8 %u_val, -1
  %iand.1 = lshr i8 %xor.0, 4
  %shr.0 = and i8 %iand.1, 7
  %iand.0 = shl i8 %xor.0, 3
  %0 = or i8 %iand.0, -124
  %add.0 = zext i8 %0 to i32
  %zext.2 = zext i8 %shr.0 to i32
  %shl.1 = shl nuw nsw i32 %add.0, %zext.2
  %icmp.1.not = icmp slt i8 %u_val, 0
  %sub.0 = sub nsw i32 132, %shl.1
  %sub.1 = add nsw i32 %shl.1, -132
  %common.ret.op = select i1 %icmp.1.not, i32 %sub.1, i32 %sub.0
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
