; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/4_val_seg_7.bc'
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
module asm "\09.ascii \22 32\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22type 1 (? <type -3>) <type -11>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22valSeg\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22val\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -11>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:672>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/4_val_seg_7.go:3\\n var r <type -11> = 1  //4\\n val = (val >> $convert(<type -12>, 8 )) //5\\n { //6\\n  var shift <type -11> = 4  //6\\n  { /*for*/ //6\\n   goto $l0 //6\\n   :$l1 //6\\n   { //6\\n    { //7\\n     if ((val & ($convert(<type -3>, 255 ) >> ($convert(<type -11>, 4 ) - shift))) != $convert(<type -3>, 0 )) { //7\\n      val = (val >> shift) //8\\n      r = (r + shift) //9\\n     } //7\\n    } //10\\n   } //11\\n   { //6\\n    shift = (shift / $convert(<type -11>, 2 )) //6\\n   } //6\\n   :$l0 //6\\n   if (shift >= $convert(<type -11>, 1 )) { //6\\n    goto $l1 //6\\n   } //6\\n  } //6\\n } //11\\n { //12\\n  $ret0 = r //12\\n  return //12\\n } //0\\n\22"
module asm "\09.ascii \22checksum 46E3E29872485F9267CBE764015EB6830C064EC6\\n\22"
module asm "\09.text"

@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: null_pointer_is_valid
define i64 @main.valSeg(i8* nest nocapture readnone %nest.0, i32 %val) local_unnamed_addr #0 {
fallthrough.1.2:
  %shr.0 = ashr i32 %val, 8
  %0 = and i32 %val, 65280
  %icmp.6.not = icmp eq i32 %0, 0
  %shr.1 = select i1 %icmp.6.not, i32 0, i32 4
  %val.addr.1 = ashr i32 %shr.0, %shr.1
  %iand.0.1 = and i32 %val.addr.1, 63
  %icmp.6.not.1 = icmp eq i32 %iand.0.1, 0
  %shr.1.1 = select i1 %icmp.6.not.1, i32 0, i32 2
  %val.addr.1.1 = ashr i32 %val.addr.1, %shr.1.1
  %r.1 = select i1 %icmp.6.not, i64 1, i64 5
  %add.0.1 = select i1 %icmp.6.not.1, i64 0, i64 2
  %r.1.1 = or i64 %r.1, %add.0.1
  %iand.0.2 = and i32 %val.addr.1.1, 31
  %icmp.6.not.2 = icmp ne i32 %iand.0.2, 0
  %add.0.2 = zext i1 %icmp.6.not.2 to i64
  %r.1.2 = add nuw nsw i64 %r.1.1, %add.0.2
  ret i64 %r.1.2
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define void @main.main(i8* nest nocapture readnone %nest.1) local_unnamed_addr #1 {
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
