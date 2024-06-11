; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/go/2_modp_montymul_8.bc'
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
module asm "\09.ascii \22 70\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -7>, ? <type -7>, ? <type -7>, ? <type -7>) <type -7>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22modp_montymul\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22a\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22b\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22p\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22p0i\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:499>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/liboqs/variants/go/2_modp_montymul_8.go:3\\n var z <type -8> = ($convert(<type -8>, a) * $convert(<type -8>, b)) //4\\n var w <type -8> = (((z * $convert(<type -8>, p0i)) & 2147483647 ) * $convert(<type -8>, p)) //5\\n var d <type -7> = $convert(<type -7>, ((z + w) >> $convert(<type -12>, 31 ))) //6\\n d = (d - p) //7\\n { //8\\n  if ($convert(<type -3>, d) < $convert(<type -3>, 0 )) { //8\\n   d = (d + p) //9\\n  } //8\\n } //10\\n { //11\\n  $ret0 = d //11\\n  return //11\\n } //0\\n\22"
module asm "\09.ascii \22checksum D5178C6EEBB16325E40A88AD4D10A7482E845392\\n\22"
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
define i32 @main.modp__montymul(i8* nest nocapture readnone %nest.0, i32 %a, i32 %b, i32 %p, i32 %p0i) local_unnamed_addr #1 {
entry:
  %zext.0 = zext i32 %a to i64
  %zext.1 = zext i32 %b to i64
  %mul.0 = mul nuw i64 %zext.1, %zext.0
  %zext.2 = zext i32 %p0i to i64
  %mul.1 = mul i64 %mul.0, %zext.2
  %iand.0 = and i64 %mul.1, 2147483647
  %zext.3 = zext i32 %p to i64
  %mul.2 = mul nuw nsw i64 %iand.0, %zext.3
  %add.0 = add i64 %mul.2, %mul.0
  %shr.0 = lshr i64 %add.0, 31
  %trunc.0 = trunc i64 %shr.0 to i32
  %sub.0 = sub i32 %trunc.0, %p
  %icmp.0 = icmp slt i32 %sub.0, 0
  %spec.select = select i1 %icmp.0, i32 %trunc.0, i32 %sub.0
  ret i32 %spec.select
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
