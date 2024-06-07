; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/go/1_mix_3.bc'
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
module asm "\09.ascii \22mix\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22c0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22c1\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:562>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/ffmpeg/variants/go/1_mix_3.go:3\\n var blue <type -3> = ((2  * (c0 & 31 )) + (c1 & 31 )) //4\\n var green <type -3> = (((2  * (c0 & 992 )) >> $convert(<type -12>, 5 )) + ((c1 & 992 ) >> $convert(<type -12>, 5 ))) //5\\n var red <type -3> = ((2  * (c0 >> $convert(<type -12>, 10 ))) + (c1 >> $convert(<type -12>, 10 ))) //6\\n { //7\\n  $ret0 = ((((red / $convert(<type -3>, 3 )) * $convert(<type -3>, 1024 )) + ((green / $convert(<type -3>, 3 )) * $convert(<type -3>, 32 ))) + (blue / $convert(<type -3>, 3 ))) //7\\n  return //7\\n } //0\\n\22"
module asm "\09.ascii \22checksum 13E9EBE2CF55E766A40DD3B10FE0D5AE9F255E53\\n\22"
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
define i32 @main.mix(i8* nest nocapture readnone %nest.0, i32 %c0, i32 %c1) local_unnamed_addr #1 {
entry:
  %iand.0 = shl i32 %c0, 1
  %mul.0 = and i32 %iand.0, 62
  %iand.1 = and i32 %c1, 31
  %add.0 = add nuw nsw i32 %mul.0, %iand.1
  %0 = lshr i32 %c0, 4
  %1 = and i32 %0, 62
  %iand.3 = lshr i32 %c1, 5
  %2 = and i32 %iand.3, 31
  %add.1 = add nuw nsw i32 %2, %1
  %3 = ashr i32 %c0, 9
  %mul.2 = and i32 %3, -2
  %shr.3 = ashr i32 %c1, 10
  %add.2 = add nsw i32 %mul.2, %shr.3
  %div.0 = sdiv i32 %add.2, 3
  %mul.3 = shl i32 %div.0, 10
  %div.1.lhs.trunc = trunc i32 %add.1 to i8
  %div.19 = udiv i8 %div.1.lhs.trunc, 3
  %div.1.zext = zext i8 %div.19 to i32
  %mul.4 = shl nuw nsw i32 %div.1.zext, 5
  %div.2.lhs.trunc = trunc i32 %add.0 to i8
  %div.210 = udiv i8 %div.2.lhs.trunc, 3
  %div.2.zext = zext i8 %div.210 to i32
  %add.3 = or i32 %mul.3, %div.2.zext
  %add.4 = add i32 %add.3, %mul.4
  ret i32 %add.4
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
