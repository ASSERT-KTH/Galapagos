; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/1_iec958_parity_0.bc'
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
module asm "\09.ascii \22 <inl:613>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/1_iec958_parity_0.go:3\\n data = (data >> $convert(<type -12>, 4 )) //4\\n var parity <type -7> = 0  //5\\n { //6\\n  var bit <type -11> = 4  //6\\n  { /*for*/ //6\\n   goto $l0 //6\\n   :$l1 //6\\n   { //6\\n    parity = (parity + (data & $convert(<type -7>, 1 ))) //7\\n    data = (data >> $convert(<type -12>, 1 )) //8\\n   } //9\\n   { //6\\n    bit = (bit + $convert(<type -11>, 1 )) //6\\n   } //6\\n   :$l0 //6\\n   if (bit <= $convert(<type -11>, 30 )) { //6\\n    goto $l1 //6\\n   } //6\\n  } //6\\n } //9\\n { //10\\n  $ret0 = (parity & $convert(<type -7>, 1 )) //10\\n  return //10\\n } //0\\n\22"
module asm "\09.ascii \22checksum ED2535468D11E98B1A289BEA14928AFED067DA4C\\n\22"
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
  %add.0.1 = add nuw nsw i32 %iand.0, %iand.0.1
  %shr.1.1 = lshr i32 %data, 6
  %iand.0.2 = and i32 %shr.1.1, 1
  %add.0.2 = add nuw nsw i32 %add.0.1, %iand.0.2
  %shr.1.2 = lshr i32 %data, 7
  %iand.0.3 = and i32 %shr.1.2, 1
  %add.0.3 = add nuw nsw i32 %add.0.2, %iand.0.3
  %shr.1.3 = lshr i32 %data, 8
  %iand.0.4 = and i32 %shr.1.3, 1
  %add.0.4 = add nuw nsw i32 %add.0.3, %iand.0.4
  %shr.1.4 = lshr i32 %data, 9
  %iand.0.5 = and i32 %shr.1.4, 1
  %add.0.5 = add nuw nsw i32 %add.0.4, %iand.0.5
  %shr.1.5 = lshr i32 %data, 10
  %iand.0.6 = and i32 %shr.1.5, 1
  %add.0.6 = add nuw nsw i32 %add.0.5, %iand.0.6
  %shr.1.6 = lshr i32 %data, 11
  %iand.0.7 = and i32 %shr.1.6, 1
  %add.0.7 = add nuw nsw i32 %add.0.6, %iand.0.7
  %shr.1.7 = lshr i32 %data, 12
  %iand.0.8 = and i32 %shr.1.7, 1
  %add.0.8 = add nuw nsw i32 %add.0.7, %iand.0.8
  %shr.1.8 = lshr i32 %data, 13
  %iand.0.9 = and i32 %shr.1.8, 1
  %add.0.9 = add nuw nsw i32 %add.0.8, %iand.0.9
  %shr.1.9 = lshr i32 %data, 14
  %iand.0.10 = and i32 %shr.1.9, 1
  %add.0.10 = add nuw nsw i32 %add.0.9, %iand.0.10
  %shr.1.10 = lshr i32 %data, 15
  %iand.0.11 = and i32 %shr.1.10, 1
  %add.0.11 = add nuw nsw i32 %add.0.10, %iand.0.11
  %shr.1.11 = lshr i32 %data, 16
  %iand.0.12 = and i32 %shr.1.11, 1
  %add.0.12 = add nuw nsw i32 %add.0.11, %iand.0.12
  %shr.1.12 = lshr i32 %data, 17
  %iand.0.13 = and i32 %shr.1.12, 1
  %add.0.13 = add nuw nsw i32 %add.0.12, %iand.0.13
  %shr.1.13 = lshr i32 %data, 18
  %iand.0.14 = and i32 %shr.1.13, 1
  %add.0.14 = add nuw nsw i32 %add.0.13, %iand.0.14
  %shr.1.14 = lshr i32 %data, 19
  %iand.0.15 = and i32 %shr.1.14, 1
  %add.0.15 = add nuw nsw i32 %add.0.14, %iand.0.15
  %shr.1.15 = lshr i32 %data, 20
  %iand.0.16 = and i32 %shr.1.15, 1
  %add.0.16 = add nuw nsw i32 %add.0.15, %iand.0.16
  %shr.1.16 = lshr i32 %data, 21
  %iand.0.17 = and i32 %shr.1.16, 1
  %add.0.17 = add nuw nsw i32 %add.0.16, %iand.0.17
  %shr.1.17 = lshr i32 %data, 22
  %iand.0.18 = and i32 %shr.1.17, 1
  %add.0.18 = add nuw nsw i32 %add.0.17, %iand.0.18
  %shr.1.18 = lshr i32 %data, 23
  %iand.0.19 = and i32 %shr.1.18, 1
  %add.0.19 = add nuw nsw i32 %add.0.18, %iand.0.19
  %shr.1.19 = lshr i32 %data, 24
  %iand.0.20 = and i32 %shr.1.19, 1
  %add.0.20 = add nuw nsw i32 %add.0.19, %iand.0.20
  %shr.1.20 = lshr i32 %data, 25
  %iand.0.21 = and i32 %shr.1.20, 1
  %add.0.21 = add nuw nsw i32 %add.0.20, %iand.0.21
  %shr.1.21 = lshr i32 %data, 26
  %iand.0.22 = and i32 %shr.1.21, 1
  %add.0.22 = add nuw nsw i32 %add.0.21, %iand.0.22
  %shr.1.22 = lshr i32 %data, 27
  %add.0.23 = add nuw nsw i32 %add.0.22, %shr.1.22
  %shr.1.23 = lshr i32 %data, 28
  %add.0.24 = add nuw nsw i32 %add.0.23, %shr.1.23
  %shr.1.24 = lshr i32 %data, 29
  %add.0.25 = add nuw nsw i32 %add.0.24, %shr.1.24
  %shr.1.25 = lshr i32 %data, 30
  %add.0.26 = add nuw nsw i32 %add.0.25, %shr.1.25
  %iand.1 = and i32 %add.0.26, 1
  ret i32 %iand.1
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
