; ModuleID = '/home/javier/Galapagos/functions/libgcrypt/variants/go/1_ctz_5.bc'
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
module asm "\09.ascii \22 <inl:587>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/libgcrypt/variants/go/1_ctz_5.go:3\\n { //4\\n  var i <type -3> = 0  //4\\n  { /*for*/ //4\\n   goto $l0 //4\\n   :$l1 //4\\n   { //4\\n    { //5\\n     if (((in >> $convert(<type -12>, i)) & $convert(<type -8>, 1 )) == $convert(<type -8>, 1 )) { //5\\n      { //6\\n       $ret0 = i //6\\n       return //6\\n      } //0\\n     } //5\\n    } //7\\n   } //8\\n   { //4\\n    i = (i + $convert(<type -3>, 1 )) //4\\n   } //4\\n   :$l0 //4\\n   if (i < $convert(<type -3>, 64 )) { //4\\n    goto $l1 //4\\n   } //4\\n  } //4\\n } //8\\n { //9\\n  $ret0 = $convert(<type -3>, 64 ) //9\\n  return //9\\n } //0\\n\22"
module asm "\09.ascii \22checksum E6D83573B4FFE77A58F44C067227B13E82FD0C88\\n\22"
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
  br label %then.2

common.ret.split.loop.exit13:                     ; preds = %then.2, %else.1.2, %else.1.1, %else.1
  %indvars.iv.lcssa = phi i64 [ %indvars.iv, %then.2 ], [ %indvars.iv.next, %else.1 ], [ %indvars.iv.next.1, %else.1.1 ], [ %indvars.iv.next.2, %else.1.2 ]
  %0 = trunc i64 %indvars.iv.lcssa to i32
  br label %common.ret

common.ret:                                       ; preds = %else.1.3, %common.ret.split.loop.exit13
  %common.ret.op = phi i32 [ %0, %common.ret.split.loop.exit13 ], [ 64, %else.1.3 ]
  ret i32 %common.ret.op

else.1:                                           ; preds = %then.2
  %indvars.iv.next = or i64 %indvars.iv, 1
  %1 = shl nuw i64 1, %indvars.iv.next
  %2 = and i64 %1, %in
  %icmp.1.not.1 = icmp eq i64 %2, 0
  br i1 %icmp.1.not.1, label %else.1.1, label %common.ret.split.loop.exit13

else.1.1:                                         ; preds = %else.1
  %indvars.iv.next.1 = or i64 %indvars.iv, 2
  %3 = shl nuw i64 1, %indvars.iv.next.1
  %4 = and i64 %3, %in
  %icmp.1.not.2 = icmp eq i64 %4, 0
  br i1 %icmp.1.not.2, label %else.1.2, label %common.ret.split.loop.exit13

else.1.2:                                         ; preds = %else.1.1
  %indvars.iv.next.2 = or i64 %indvars.iv, 3
  %5 = shl nuw i64 1, %indvars.iv.next.2
  %6 = and i64 %5, %in
  %icmp.1.not.3 = icmp eq i64 %6, 0
  br i1 %icmp.1.not.3, label %else.1.3, label %common.ret.split.loop.exit13

else.1.3:                                         ; preds = %else.1.2
  %indvars.iv.next.3 = add nuw nsw i64 %indvars.iv, 4
  %exitcond.not.3 = icmp eq i64 %indvars.iv.next.3, 64
  br i1 %exitcond.not.3, label %common.ret, label %then.2

then.2:                                           ; preds = %else.1.3, %entry
  %indvars.iv = phi i64 [ 0, %entry ], [ %indvars.iv.next.3, %else.1.3 ]
  %7 = shl nuw i64 1, %indvars.iv
  %8 = and i64 %7, %in
  %icmp.1.not = icmp eq i64 %8, 0
  br i1 %icmp.1.not, label %else.1, label %common.ret.split.loop.exit13
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
