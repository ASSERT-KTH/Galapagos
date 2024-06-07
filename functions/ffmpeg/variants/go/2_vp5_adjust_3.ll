; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/go/2_vp5_adjust_3.bc'
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
module asm "\09.ascii \22type 1 (? <type -3>, ? <type -3>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22vp5_adjust\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22v\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22t\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:505>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/ffmpeg/variants/go/2_vp5_adjust_3.go:3\\n var s1 <type -3> = (v >> $convert(<type -12>, 31 )) //4\\n var absV <type -3> = ((v ^ s1) - s1) //5\\n { //6\\n  if (absV >= ($convert(<type -3>, 2 ) * t)) { //6\\n   absV = $convert(<type -3>, 0 ) //7\\n  } //6\\n } //8\\n var adjusted <type -3> = (absV - t) //9\\n var s2 <type -3> = (adjusted >> $convert(<type -12>, 31 )) //10\\n adjusted = ((adjusted ^ s2) - s2) //11\\n { //12\\n  $ret0 = (((t - adjusted) + s1) ^ s1) //12\\n  return //12\\n } //0\\n\22"
module asm "\09.ascii \22checksum EFEEB6DA7B1D00152109A8027319AB5484D20F83\\n\22"
module asm "\09.text"

@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: mustprogress nofree nosync nounwind null_pointer_is_valid readnone willreturn
define i32 @main.vp5__adjust(i8* nest nocapture readnone %nest.0, i32 %v, i32 %t) local_unnamed_addr #1 {
entry:
  %shr.0 = ashr i32 %v, 31
  %xor.0 = xor i32 %shr.0, %v
  %sub.0 = sub i32 %xor.0, %shr.0
  %mul.0 = shl i32 %t, 1
  %icmp.0.not = icmp slt i32 %sub.0, %mul.0
  %spec.store.select = select i1 %icmp.0.not, i32 %sub.0, i32 0
  %sub.1 = sub i32 %spec.store.select, %t
  %0 = call i32 @llvm.abs.i32(i32 %sub.1, i1 false)
  %sub.3 = add i32 %shr.0, %t
  %add.0 = sub i32 %sub.3, %0
  %xor.2 = xor i32 %add.0, %shr.0
  ret i32 %xor.2
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

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare i32 @llvm.abs.i32(i32, i1 immarg) #3

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { mustprogress nofree nosync nounwind null_pointer_is_valid readnone willreturn "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #3 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
