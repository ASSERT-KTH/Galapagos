; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/1_iec958_parity_3.bc'
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
module asm "\09.ascii \22type 1 (? <type -7>) <type -7>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22iec958_parity\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22data\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:740>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/1_iec958_parity_3.go:3\\n data = (data >> $convert(<type -12>, 4 )) //4\\n var parity <type -11> = 0  //5\\n { //6\\n  var bit <type -11> = 4  //6\\n  { /*for*/ //6\\n   goto $l0 //6\\n   :$l1 //6\\n   { //6\\n    { //7\\n     if ((data & $convert(<type -7>, 1 )) != $convert(<type -7>, 0 )) { //7\\n      parity = (parity + $convert(<type -11>, 1 )) //8\\n     } //7\\n    } //9\\n    data = (data >> $convert(<type -12>, 1 )) //10\\n   } //11\\n   { //6\\n    bit = (bit + $convert(<type -11>, 1 )) //6\\n   } //6\\n   :$l0 //6\\n   if (bit <= $convert(<type -11>, 30 )) { //6\\n    goto $l1 //6\\n   } //6\\n  } //6\\n } //11\\n { //12\\n  $ret0 = $convert(<type -7>, (parity % $convert(<type -11>, 2 ))) //12\\n  return //12\\n } //0\\n\22"
module asm "\09.ascii \22checksum 512BD1B6F2484B7D548026F7C74ED666B3EE4149\\n\22"
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
define i32 @main.iec958__parity(i8* nest nocapture readnone %nest.0, i32 %data) local_unnamed_addr #1 {
entry:
  %shr.0 = lshr i32 %data, 4
  %iand.0 = and i32 %shr.0, 1
  %shr.1 = lshr i32 %data, 5
  %iand.0.1 = and i32 %shr.1, 1
  %narrow = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %narrow11 = add nuw nsw i32 %narrow, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %narrow12 = add nuw nsw i32 %narrow11, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %narrow13 = add nuw nsw i32 %narrow12, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %narrow14 = add nuw nsw i32 %narrow13, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %narrow15 = add nuw nsw i32 %narrow14, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %0 = and i32 %shr.1.6, 1
  %parity.1.7 = add i32 %0, %narrow15
  %shr.1.7 = lshr i32 %data, 12
  %1 = and i32 %shr.1.7, 1
  %parity.1.8 = add i32 %parity.1.7, %1
  %shr.1.8 = lshr i32 %data, 13
  %2 = and i32 %shr.1.8, 1
  %parity.1.9 = add i32 %parity.1.8, %2
  %shr.1.9 = lshr i32 %data, 14
  %3 = and i32 %shr.1.9, 1
  %parity.1.10 = add i32 %parity.1.9, %3
  %shr.1.10 = lshr i32 %data, 15
  %4 = and i32 %shr.1.10, 1
  %parity.1.11 = add i32 %parity.1.10, %4
  %shr.1.11 = lshr i32 %data, 16
  %5 = and i32 %shr.1.11, 1
  %parity.1.12 = add i32 %parity.1.11, %5
  %shr.1.12 = lshr i32 %data, 17
  %6 = and i32 %shr.1.12, 1
  %parity.1.13 = add i32 %parity.1.12, %6
  %shr.1.13 = lshr i32 %data, 18
  %7 = and i32 %shr.1.13, 1
  %parity.1.14 = add i32 %parity.1.13, %7
  %shr.1.14 = lshr i32 %data, 19
  %8 = and i32 %shr.1.14, 1
  %parity.1.15 = add i32 %parity.1.14, %8
  %shr.1.15 = lshr i32 %data, 20
  %9 = and i32 %shr.1.15, 1
  %parity.1.16 = add i32 %parity.1.15, %9
  %shr.1.16 = lshr i32 %data, 21
  %10 = and i32 %shr.1.16, 1
  %parity.1.17 = add i32 %parity.1.16, %10
  %shr.1.17 = lshr i32 %data, 22
  %11 = and i32 %shr.1.17, 1
  %parity.1.18 = add i32 %parity.1.17, %11
  %shr.1.18 = lshr i32 %data, 23
  %12 = and i32 %shr.1.18, 1
  %parity.1.19 = add i32 %parity.1.18, %12
  %shr.1.19 = lshr i32 %data, 24
  %13 = and i32 %shr.1.19, 1
  %parity.1.20 = add i32 %parity.1.19, %13
  %shr.1.20 = lshr i32 %data, 25
  %14 = and i32 %shr.1.20, 1
  %parity.1.21 = add i32 %parity.1.20, %14
  %shr.1.21 = lshr i32 %data, 26
  %15 = and i32 %shr.1.21, 1
  %parity.1.22 = add i32 %parity.1.21, %15
  %shr.1.22 = lshr i32 %data, 27
  %parity.1.23 = add i32 %parity.1.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %parity.1.24 = add i32 %parity.1.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %parity.1.25 = add i32 %parity.1.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %parity.1.26 = add i32 %parity.1.25, %shr.1.25
  %mod.01617 = and i32 %parity.1.26, 1
  ret i32 %mod.01617
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define void @main.main(i8* nest nocapture %nest.1) local_unnamed_addr #2 {
entry:
  ret void
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(i8*, i64, i8*) local_unnamed_addr #0

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #3

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { nofree norecurse nosync nounwind null_pointer_is_valid readnone "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #3 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
