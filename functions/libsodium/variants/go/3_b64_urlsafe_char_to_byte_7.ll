; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/go/3_b64_urlsafe_char_to_byte_7.bc'
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
module asm "\09.ascii \22type 1 (? <type -3>) <type -12>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22b64_urlsafe_char_to_byte\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22c\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -12>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum 0ACDDE2D0D00C466C57BF915C4A785845770BD0C\\n\22"
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
define i64 @main.b64__urlsafe__char__to__byte(i8* nest nocapture readnone %nest.0, i32 %c) local_unnamed_addr #1 {
entry:
  %0 = add i32 %c, -65
  %1 = icmp ult i32 %0, 26
  br i1 %1, label %else.1, label %label.0

common.ret:                                       ; preds = %label.3, %else.5, %else.3, %else.1
  %common.ret.op = phi i64 [ %sext.033, %else.1 ], [ %sext.134, %else.3 ], [ %sext.235, %else.5 ], [ %switch.select32, %label.3 ]
  ret i64 %common.ret.op

else.1:                                           ; preds = %entry
  %sext.033 = zext i32 %0 to i64
  br label %common.ret

label.0:                                          ; preds = %entry
  %2 = add i32 %c, -97
  %3 = icmp ult i32 %2, 26
  br i1 %3, label %else.3, label %label.2

else.3:                                           ; preds = %label.0
  %add.0 = add nsw i32 %c, -71
  %sext.134 = zext i32 %add.0 to i64
  br label %common.ret

label.2:                                          ; preds = %label.0
  %4 = add i32 %c, -48
  %5 = icmp ult i32 %4, 10
  br i1 %5, label %else.5, label %label.3

else.5:                                           ; preds = %label.2
  %add.1 = add nuw nsw i32 %c, 4
  %sext.235 = zext i32 %add.1 to i64
  br label %common.ret

label.3:                                          ; preds = %label.2
  %switch.selectcmp = icmp eq i32 %c, 95
  %switch.select = select i1 %switch.selectcmp, i64 63, i64 0
  %switch.selectcmp31 = icmp eq i32 %c, 45
  %switch.select32 = select i1 %switch.selectcmp31, i64 62, i64 %switch.select
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
