; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/go/3__booth_recode_w5_9.bc'
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
module asm "\09.ascii \22boothRecodeW5\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22in\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:395>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/openssl/variants/go/3__booth_recode_w5_9.go:3\\n var s <type -7> = ^((in >> $convert(<type -12>, 5 )) - 1 ) //4\\n var d <type -7> = ((64  - in) - 1 ) //5\\n d = (d | (in & ^s)) //6\\n d = ((d >> $convert(<type -12>, 1 )) + (d & $convert(<type -7>, 1 ))) //7\\n { //9\\n  $ret0 = ((d << $convert(<type -12>, 1 )) + (s & $convert(<type -7>, 1 ))) //9\\n  return //9\\n } //0\\n\22"
module asm "\09.ascii \22checksum AE8D76D1ACA254F0151A0060841EE26C1EBA5EE7\\n\22"
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
define i32 @main.boothRecodeW5(i8* nest nocapture readnone %nest.0, i32 %in) local_unnamed_addr #1 {
entry:
  %shr.0 = lshr i32 %in, 5
  %sub.0 = add nsw i32 %shr.0, -1
  %sub.2 = sub i32 63, %in
  %iand.0 = and i32 %sub.0, %in
  %ior.0 = or i32 %iand.0, %sub.2
  %iand.1 = shl i32 %ior.0, 1
  %add.010 = and i32 %iand.1, 2
  %shr.111 = add i32 %add.010, %ior.0
  %shl.0 = and i32 %shr.111, -2
  %iand.2 = and i32 %shr.0, 1
  %add.1 = or i32 %shl.0, %iand.2
  ret i32 %add.1
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
