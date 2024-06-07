; ModuleID = '/home/javier/Galapagos/functions/alsa-lib/variants/go/2_muldiv_down_6.bc'
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
module asm "\09.ascii \22muldivDown\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22a\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22b\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22, \22"
module asm "\09.ascii \22c\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:813>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/alsa-lib/variants/go/2_muldiv_down_6.go:3\\n var v <type -4> = (($convert(<type -4>, a) * $convert(<type -4>, b)) / $convert(<type -4>, c)) //4\\n { //5\\n  { //5\\n   var $t0 <type -15> = $true //5\\n   if !($t0 == (v > $convert(<type -4>, 2147483647 ))) { //6\\n    goto $l0 //6\\n   } //6\\n   { //7\\n    { //7\\n     $ret0 = $convert(<type -3>, 2147483647 ) //7\\n     return //7\\n    } //0\\n   } //8\\n   goto $l1 //6\\n   :$l0 //0\\n   if !($t0 == (v < $convert(<type -4>, -2147483648 ))) { //8\\n    goto $l2 //8\\n   } //8\\n   { //9\\n    { //9\\n     $ret0 = $convert(<type -3>, -2147483648 ) //9\\n     return //9\\n    } //0\\n   } //10\\n   goto $l1 //8\\n   :$l2 //0\\n   { //11\\n    { //11\\n     $ret0 = $convert(<type -3>, v) //11\\n     return //11\\n    } //0\\n   } //12\\n   goto $l1 //10\\n   :$l1 //5\\n  } //0\\n } //12\\n\22"
module asm "\09.ascii \22checksum BAD17E3814A867717BA36A9FD4F26915EA85943C\\n\22"
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
define i32 @main.muldivDown(i8* nest nocapture readnone %nest.0, i32 %a, i32 %b, i32 %c) local_unnamed_addr #0 {
entry:
  %sext.0 = sext i32 %a to i64
  %sext.1 = sext i32 %b to i64
  %mul.0 = mul nsw i64 %sext.1, %sext.0
  switch i32 %c, label %else.1 [
    i32 -1, label %then.0
    i32 0, label %then.1
  ]

then.0:                                           ; preds = %entry
  %sub.0 = sub nsw i64 0, %mul.0
  br label %fallthrough.0

fallthrough.0:                                    ; preds = %else.1, %then.0
  %tmpv.3.0 = phi i64 [ %sub.0, %then.0 ], [ %div.0, %else.1 ]
  %icmp.2 = icmp slt i64 %tmpv.3.0, 2147483648
  %icmp.5 = icmp sgt i64 %tmpv.3.0, -2147483649
  %trunc.4 = trunc i64 %tmpv.3.0 to i32
  %spec.select = select i1 %icmp.5, i32 %trunc.4, i32 -2147483648
  %common.ret.op = select i1 %icmp.2, i32 %spec.select, i32 2147483647
  ret i32 %common.ret.op

then.1:                                           ; preds = %entry
  call void @runtime.panicdivide(i8* nest undef)
  unreachable

else.1:                                           ; preds = %entry
  %sext.2 = sext i32 %c to i64
  %div.0 = sdiv i64 %mul.0, %sext.2
  br label %fallthrough.0
}

; Function Attrs: noreturn null_pointer_is_valid
declare void @runtime.panicdivide(i8*) local_unnamed_addr #1

; Function Attrs: null_pointer_is_valid
define void @main.main(i8* nest nocapture readnone %nest.1) local_unnamed_addr #0 {
entry:
  call void @runtime.panicdivide(i8* nest undef)
  unreachable
}

; Function Attrs: null_pointer_is_valid
declare void @runtime.registerTypeDescriptors(i8*, i64, i8*) local_unnamed_addr #0

; Function Attrs: nofree nosync nounwind readnone speculatable willreturn
declare void @llvm.dbg.value(metadata, metadata, metadata) #2

attributes #0 = { null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #1 = { noreturn null_pointer_is_valid "disable-tail-calls"="true" "frame-pointer"="none" "split-stack" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" }
attributes #2 = { nofree nosync nounwind readnone speculatable willreturn }

!llvm.module.flags = !{!0, !1, !2}

!0 = !{i32 7, !"PIC Level", i32 0}
!1 = !{i32 2, !"Debug Info Version", i32 3}
!2 = !{i32 2, !"Dwarf Version", i32 4}
