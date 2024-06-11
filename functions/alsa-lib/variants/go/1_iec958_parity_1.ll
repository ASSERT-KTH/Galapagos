; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/1_iec958_parity_1.bc'
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
module asm "\09.ascii \22 <inl:562>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/1_iec958_parity_1.go:3\\n data = (data >> $convert(<type -12>, 4 )) //4\\n var parity <type -11> = 0  //5\\n { //6\\n  { /*for*/ //6\\n   goto $l0 //6\\n   :$l1 //6\\n   { //6\\n    parity = (parity + $convert(<type -11>, (data & $convert(<type -7>, 1 )))) //7\\n    data = (data >> $convert(<type -12>, 1 )) //8\\n   } //9\\n   :$l0 //6\\n   if (data != $convert(<type -7>, 0 )) { //6\\n    goto $l1 //6\\n   } //6\\n  } //9\\n } //9\\n { //10\\n  $ret0 = $convert(<type -7>, (parity & $convert(<type -11>, 1 ))) //10\\n  return //10\\n } //0\\n\22"
module asm "\09.ascii \22checksum 9C28CC2ECA66188165A4379A979D46C48727BF74\\n\22"
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
  %icmp.0.not7 = icmp ult i32 %data, 16
  br i1 %icmp.0.not7, label %else.0, label %then.0.preheader

then.0.preheader:                                 ; preds = %entry
  %shr.0 = lshr i32 %data, 4
  br label %then.0

then.0:                                           ; preds = %then.0, %then.0.preheader
  %parity.09 = phi i64 [ %add.0, %then.0 ], [ 0, %then.0.preheader ]
  %data.addr.08 = phi i32 [ %shr.1, %then.0 ], [ %shr.0, %then.0.preheader ]
  %iand.0 = and i32 %data.addr.08, 1
  %zext.0 = zext i32 %iand.0 to i64
  %add.0 = add i64 %parity.09, %zext.0
  %shr.1 = lshr i32 %data.addr.08, 1
  %icmp.0.not = icmp ult i32 %data.addr.08, 2
  br i1 %icmp.0.not, label %else.0.loopexit, label %then.0

else.0.loopexit:                                  ; preds = %then.0
  %phi.cast = trunc i64 %add.0 to i32
  %phi.bo = and i32 %phi.cast, 1
  br label %else.0

else.0:                                           ; preds = %else.0.loopexit, %entry
  %parity.0.lcssa = phi i32 [ 0, %entry ], [ %phi.bo, %else.0.loopexit ]
  ret i32 %parity.0.lcssa
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
