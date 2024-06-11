; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/go/2_b64_char_to_byte_3.bc'
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
module asm "\09.ascii \22type 1 (? <type -3>) <type -7>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22b64CharToByte\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22c\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum 3D25CCBF99A7B20FFBF7167BEED70E3A941985BF\\n\22"
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
define i32 @main.b64CharToByte(i8* nest nocapture readnone %nest.0, i32 %c) local_unnamed_addr #1 {
entry:
  %0 = add i32 %c, -65
  %1 = icmp ult i32 %0, 26
  br i1 %1, label %common.ret, label %else.1

common.ret:                                       ; preds = %else.5, %then.5, %then.3, %entry
  %common.ret.op = phi i32 [ %add.0, %then.3 ], [ %add.1, %then.5 ], [ %switch.select28, %else.5 ], [ %0, %entry ]
  ret i32 %common.ret.op

else.1:                                           ; preds = %entry
  %2 = add i32 %c, -97
  %3 = icmp ult i32 %2, 26
  br i1 %3, label %then.3, label %else.3

then.3:                                           ; preds = %else.1
  %add.0 = add nsw i32 %c, -71
  br label %common.ret

else.3:                                           ; preds = %else.1
  %4 = add i32 %c, -48
  %5 = icmp ult i32 %4, 10
  br i1 %5, label %then.5, label %else.5

then.5:                                           ; preds = %else.3
  %add.1 = add nuw nsw i32 %c, 4
  br label %common.ret

else.5:                                           ; preds = %else.3
  %switch.selectcmp = icmp eq i32 %c, 47
  %switch.select = select i1 %switch.selectcmp, i32 63, i32 0
  %switch.selectcmp27 = icmp eq i32 %c, 43
  %switch.select28 = select i1 %switch.selectcmp27, i32 62, i32 %switch.select
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
