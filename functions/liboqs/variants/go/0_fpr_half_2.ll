; ModuleID = '/home/javier/Galapagos/functions/liboqs/variants/go/0_fpr_half_2.bc'
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
module asm "\09.ascii \22type 1 (? <type -8>) <type -8>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22fpr_half\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22x\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:500>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/liboqs/variants/go/0_fpr_half_2.go:3\\n var exponent <type -8> = ((x >> $convert(<type -12>, 52 )) & 2047 ) //4\\n { //5\\n  if (exponent == $convert(<type -8>, 0 )) { //5\\n   { //6\\n    $ret0 = (x >> $convert(<type -12>, 1 )) //6\\n    return //6\\n   } //0\\n  } //5\\n } //7\\n exponent = (exponent - $convert(<type -8>, 1 )) //8\\n x = ((x &^ $convert(<type -8>, 9218868437227405312 )) | (exponent << $convert(<type -12>, 52 ))) //9\\n { //10\\n  $ret0 = x //10\\n  return //10\\n } //0\\n\22"
module asm "\09.ascii \22checksum 9561322C36B120DB6AC40393709D5358E2176B46\\n\22"
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
define i64 @main.fpr__half(i8* nest nocapture readnone %nest.0, i64 %x) local_unnamed_addr #1 {
entry:
  %shr.0 = lshr i64 %x, 52
  %iand.0 = and i64 %shr.0, 2047
  %icmp.0 = icmp eq i64 %iand.0, 0
  br i1 %icmp.0, label %then.0, label %else.0

common.ret:                                       ; preds = %else.0, %then.0
  %common.ret.op = phi i64 [ %shr.1, %then.0 ], [ %ior.0, %else.0 ]
  ret i64 %common.ret.op

then.0:                                           ; preds = %entry
  %shr.1 = lshr i64 %x, 1
  br label %common.ret

else.0:                                           ; preds = %entry
  %iand.1 = and i64 %x, -9218868437227405313
  %sub.0 = shl nuw nsw i64 %iand.0, 52
  %shl.0 = add nsw i64 %sub.0, -4503599627370496
  %ior.0 = or i64 %shl.0, %iand.1
  br label %common.ret
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
