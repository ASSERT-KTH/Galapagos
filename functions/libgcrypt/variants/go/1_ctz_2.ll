; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/go/1_ctz_2.bc'
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
module asm "\09.ascii \22 <inl:477>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/libgcrypt/variants/go/1_ctz_2.go:3\\n var r <type -3> = 0  //4\\n { //5\\n  { /*for*/ //5\\n   goto $l0 //5\\n   :$l1 //5\\n   { //5\\n    in = (in >> $convert(<type -12>, 1 )) //6\\n   } //7\\n   { //5\\n    r = (r + $convert(<type -3>, 1 )) //5\\n   } //5\\n   :$l0 //5\\n   if (((in & $convert(<type -8>, 1 )) == $convert(<type -8>, 0 )) && (r < $convert(<type -3>, 64 ))) { //5\\n    goto $l1 //5\\n   } //5\\n  } //5\\n } //7\\n { //8\\n  $ret0 = r //8\\n  return //8\\n } //0\\n\22"
module asm "\09.ascii \22checksum FFD42C4422543AD55218D136954F50F2702E1909\\n\22"
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
  %iand.07 = and i64 %in, 1
  %icmp.08 = icmp eq i64 %iand.07, 0
  br i1 %icmp.08, label %then.1, label %else.1

then.1:                                           ; preds = %then.1, %entry
  %r.010 = phi i32 [ %add.0, %then.1 ], [ 0, %entry ]
  %in.addr.09 = phi i64 [ %shr.0, %then.1 ], [ %in, %entry ]
  %shr.0 = lshr i64 %in.addr.09, 1
  %add.0 = add nuw nsw i32 %r.010, 1
  %0 = and i64 %in.addr.09, 2
  %icmp.0 = icmp eq i64 %0, 0
  %icmp.1 = icmp ult i32 %r.010, 63
  %spec.select = select i1 %icmp.0, i1 %icmp.1, i1 false
  br i1 %spec.select, label %then.1, label %else.1

else.1:                                           ; preds = %then.1, %entry
  %r.0.lcssa = phi i32 [ 0, %entry ], [ %add.0, %then.1 ]
  ret i32 %r.0.lcssa
}

; Function Attrs: nofree norecurse nosync nounwind null_pointer_is_valid readnone
define void @main.main(i8* nest nocapture %nest.1) local_unnamed_addr #1 {
entry:
  ret void
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(i8*, i64, i8*) local_unnamed_addr #0

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { nofree norecurse nosync nounwind null_pointer_is_valid readnone "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
