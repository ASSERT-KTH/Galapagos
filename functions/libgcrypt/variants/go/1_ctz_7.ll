; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/go/1_ctz_7.bc'
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
module asm "\09.ascii \22type 1 (? <type -8>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22ctz\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22in\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:671>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/libgcrypt/variants/go/1_ctz_7.go:3\\n { //4\\n  if (in == $convert(<type -8>, 0 )) { //4\\n   { //5\\n    $ret0 = $convert(<type -3>, 64 ) //5\\n    return //5\\n   } //0\\n  } //4\\n } //6\\n var count <type -3> = 0  //8\\n { //9\\n  var i <type -12> = 0  //9\\n  { /*for*/ //9\\n   goto $l0 //9\\n   :$l1 //9\\n   { //9\\n    count = (count + $convert(<type -3>, 1 )) //10\\n   } //11\\n   { //9\\n    i = (i + $convert(<type -12>, 1 )) //9\\n   } //9\\n   :$l0 //9\\n   if ((i < $convert(<type -12>, 64 )) && ((in & ($convert(<type -8>, 1 ) << i)) == $convert(<type -8>, 0 ))) { //9\\n    goto $l1 //9\\n   } //9\\n  } //9\\n } //11\\n { //12\\n  $ret0 = count //12\\n  return //12\\n } //0\\n\22"
module asm "\09.ascii \22checksum 13C216CD0D5ED683574B7DD2D118EAB0269D3BD3\\n\22"
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
define i32 @main.ctz(i8* nest nocapture readnone %nest.0, i64 %in) local_unnamed_addr #1 {
entry:
  %icmp.0 = icmp eq i64 %in, 0
  br i1 %icmp.0, label %common.ret, label %label.0.preheader

label.0.preheader:                                ; preds = %entry
  %iand.013 = and i64 %in, 1
  %icmp.314 = icmp eq i64 %iand.013, 0
  br i1 %icmp.314, label %then.3, label %common.ret

common.ret.loopexit:                              ; preds = %then.3
  %indvars = trunc i64 %add.1 to i32
  br label %common.ret

common.ret:                                       ; preds = %common.ret.loopexit, %label.0.preheader, %entry
  %common.ret.op = phi i32 [ 64, %entry ], [ 0, %label.0.preheader ], [ %indvars, %common.ret.loopexit ]
  ret i32 %common.ret.op

then.3:                                           ; preds = %then.3, %label.0.preheader
  %i.016 = phi i64 [ %add.1, %then.3 ], [ 0, %label.0.preheader ]
  %add.1 = add nuw nsw i64 %i.016, 1
  %icmp.1 = icmp ult i64 %i.016, 63
  %shl.0 = shl i64 2, %i.016
  %iand.0 = and i64 %shl.0, %in
  %icmp.3 = icmp eq i64 %iand.0, 0
  %tmpv.0.0.in = select i1 %icmp.1, i1 %icmp.3, i1 false
  br i1 %tmpv.0.0.in, label %then.3, label %common.ret.loopexit
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
