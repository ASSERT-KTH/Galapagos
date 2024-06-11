; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/go/3__booth_recode_w5_6.bc'
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
module asm "\09.ascii \22boothRecodeW5\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22in\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:566>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/openssl/variants/go/3__booth_recode_w5_6.go:3\\n var s <type -7> = ^$convert(<type -7>, (($convert(<type -3>, in) >> $convert(<type -12>, 5 )) - $convert(<type -3>, 1 ))) //4\\n { //5\\n  if (s == $convert(<type -7>, 0 )) { //5\\n   { //6\\n    $ret0 = $convert(<type -7>, 0 ) //6\\n    return //6\\n   } //0\\n  } //5\\n } //7\\n var d <type -7> = (63  - in) //8\\n d = ((d >> $convert(<type -12>, 1 )) + (d & $convert(<type -7>, 1 ))) //9\\n { //11\\n  $ret0 = ((d << $convert(<type -12>, 1 )) + (s & $convert(<type -7>, 1 ))) //11\\n  return //11\\n } //0\\n\22"
module asm "\09.ascii \22checksum FA6F2B0F02D53F04852E9B2B41B66377A5C03F1C\\n\22"
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
define i32 @main.boothRecodeW5(i8* nest nocapture readnone %nest.0, i32 %in) local_unnamed_addr #1 {
entry:
  %icmp.0 = icmp ult i32 %in, 32
  br i1 %icmp.0, label %common.ret, label %else.0

common.ret:                                       ; preds = %else.0, %entry
  %common.ret.op = phi i32 [ %add.1, %else.0 ], [ 0, %entry ]
  ret i32 %common.ret.op

else.0:                                           ; preds = %entry
  %shr.014 = lshr i32 %in, 5
  %sub.1 = sub i32 63, %in
  %iand.0 = shl i32 %sub.1, 1
  %add.012 = and i32 %iand.0, 2
  %shr.113 = add i32 %add.012, %sub.1
  %shl.0 = and i32 %shr.113, -2
  %iand.1 = and i32 %shr.014, 1
  %add.1 = or i32 %shl.0, %iand.1
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
