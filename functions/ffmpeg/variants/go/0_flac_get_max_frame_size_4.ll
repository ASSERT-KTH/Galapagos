; ModuleID = '/home/javier/Galapagos/functions/ffmpeg/variants/go/0_flac_get_max_frame_size_4.bc'
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
module asm "\09.ascii \22 57\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -3>, ? <type -3>, ? <type -3>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22flacGetMaxFrameSize\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22blocksize\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22ch\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22bps\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:613>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/ffmpeg/variants/go/0_flac_get_max_frame_size_4.go:3\\n var count <type -3> = 16  //4\\n count = (count + (ch * ((bps + $convert(<type -3>, 14 )) / $convert(<type -3>, 8 )))) //5\\n { //6\\n  if (ch == $convert(<type -3>, 2 )) { //6\\n   var frameSize <type -3> = (((((2  * bps) + 1 ) * blocksize) + 7 ) / 8 ) //7\\n   count = (count + frameSize) //8\\n  } else { //9\\n   var frameSize <type -3> = ((((ch * bps) * blocksize) + 7 ) / 8 ) //10\\n   count = (count + frameSize) //11\\n  } //6\\n } //12\\n count = (count + $convert(<type -3>, 2 )) //13\\n { //14\\n  $ret0 = count //14\\n  return //14\\n } //0\\n\22"
module asm "\09.ascii \22checksum 8058FE3C87887D0B28DAEAB17032C8514478B78E\\n\22"
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
define i32 @main.flacGetMaxFrameSize(i8* nest nocapture readnone %nest.0, i32 %blocksize, i32 %ch, i32 %bps) local_unnamed_addr #1 {
entry:
  %icmp.6 = icmp eq i32 %ch, 2
  %mul.1 = shl i32 %bps, 1
  %add.2 = or i32 %mul.1, 1
  %mul.3 = mul i32 %bps, %ch
  %add.2.pn = select i1 %icmp.6, i32 %add.2, i32 %mul.3
  %add.0 = add i32 %bps, 14
  %div.0 = sdiv i32 %add.0, 8
  %mul.0 = mul i32 %div.0, %ch
  %div.1.pn.in.in = mul i32 %add.2.pn, %blocksize
  %div.1.pn.in = add i32 %div.1.pn.in.in, 7
  %div.1.pn = sdiv i32 %div.1.pn.in, 8
  %count.0 = add i32 %mul.0, 18
  %add.7 = add i32 %count.0, %div.1.pn
  ret i32 %add.7
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
