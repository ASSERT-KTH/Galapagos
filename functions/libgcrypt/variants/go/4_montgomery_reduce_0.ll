; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/go/4_montgomery_reduce_0.bc'
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
module asm "\09.ascii \22type 1 (? <type -3>) <type -2>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22montgomeryReduce\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22a\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -2>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:335>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/libgcrypt/variants/go/4_montgomery_reduce_0.go:3\\n var t <type -2> //4\\n t = ($convert(<type -2>, a) * $convert(<type -2>, -3327 )) //5\\n t = $convert(<type -2>, ((a - ($convert(<type -3>, t) * $convert(<type -3>, 3329 ))) >> $convert(<type -12>, 16 ))) //6\\n { //7\\n  $ret0 = t //7\\n  return //7\\n } //0\\n\22"
module asm "\09.ascii \22checksum 2E3E170C2D976D41AF288F809C0FC00EF9C3B836\\n\22"
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
define i16 @main.montgomeryReduce(i8* nest nocapture readnone %nest.0, i32 %a) local_unnamed_addr #1 {
entry:
  %sext = mul i32 %a, -218038272
  %sext.0 = ashr exact i32 %sext, 16
  %mul.1.neg = mul nsw i32 %sext.0, -3329
  %sub.0 = add i32 %mul.1.neg, %a
  %0 = lshr i32 %sub.0, 16
  %trunc.2 = trunc i32 %0 to i16
  ret i16 %trunc.2
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
