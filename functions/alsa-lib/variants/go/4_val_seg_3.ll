; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/4_val_seg_3.bc'
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
module asm "\09.ascii \22 <inl:706>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/4_val_seg_3.go:3\\n var r <type -11> = 1  //4\\n val = (val >> $convert(<type -12>, 8 )) //5\\n { //6\\n  if ((val & $convert(<type -3>, 240 )) > $convert(<type -3>, 0 )) { //6\\n   val = (val >> $convert(<type -12>, 4 )) //7\\n   r = (r + $convert(<type -11>, 4 )) //8\\n  } //6\\n } //9\\n { //10\\n  if ((val & $convert(<type -3>, 12 )) > $convert(<type -3>, 0 )) { //10\\n   val = (val >> $convert(<type -12>, 2 )) //11\\n   r = (r + $convert(<type -11>, 2 )) //12\\n  } //10\\n } //13\\n { //14\\n  if ((val & $convert(<type -3>, 2 )) > $convert(<type -3>, 0 )) { //14\\n   r = (r + $convert(<type -11>, 1 )) //15\\n  } //14\\n } //16\\n { //17\\n  $ret0 = r //17\\n  return //17\\n } //0\\n\22"
module asm "\09.ascii \22checksum C29C945690A4ABAE063437B299C621439848C7F4\\n\22"
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
define i64 @main.valSeg(i8* nest nocapture readnone %nest.0, i32 %val) local_unnamed_addr #1 {
entry:
  %0 = and i32 %val, 61440
  %icmp.0.not = icmp eq i32 %0, 0
  %spec.select.v = select i1 %icmp.0.not, i32 8, i32 12
  %spec.select = ashr i32 %val, %spec.select.v
  %spec.select11 = select i1 %icmp.0.not, i64 1, i64 5
  %iand.1 = and i32 %spec.select, 12
  %icmp.1.not = icmp eq i32 %iand.1, 0
  %1 = lshr i32 %spec.select, 2
  %add.1 = or i64 %spec.select11, 2
  %val.addr.1 = select i1 %icmp.1.not, i32 %spec.select, i32 %1
  %r.1 = select i1 %icmp.1.not, i64 %spec.select11, i64 %add.1
  %iand.2 = lshr i32 %val.addr.1, 1
  %iand.2.lobit = and i32 %iand.2, 1
  %2 = zext i32 %iand.2.lobit to i64
  %r.2 = add nuw nsw i64 %r.1, %2
  ret i64 %r.2
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
