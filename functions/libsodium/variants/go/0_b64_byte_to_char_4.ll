; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/go/0_b64_byte_to_char_4.bc'
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
module asm "\09.ascii \22type 1 (? <type -7>) <type -3>\\n\22"
module asm "\09.ascii \22func \22"
module asm "\09.ascii \22.\22"
module asm "\09.ascii \22b64ByteToChar\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22x\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum 2418CCB33D262BA817CB19AEC77CA38B6507D36E\\n\22"
module asm "\09.text"

@const.0 = private unnamed_addr constant [27 x i8] c"ABCDEFGHIJKLMNOPQRSTUVWXYZ\00", align 1
@const.2 = private unnamed_addr constant [27 x i8] c"abcdefghijklmnopqrstuvwxyz\00", align 1
@const.4 = private unnamed_addr constant [11 x i8] c"0123456789\00", align 1
@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define i32 @main.b64ByteToChar(i8* nest nocapture readnone %nest.0, i32 %x) local_unnamed_addr #1 {
entry:
  %icmp.1 = icmp ult i32 %x, 26
  br i1 %icmp.1, label %fallthrough.1, label %else.0

else.0:                                           ; preds = %entry
  %icmp.3 = icmp ult i32 %x, 52
  br i1 %icmp.3, label %fallthrough.3, label %else.2

common.ret:                                       ; preds = %fallthrough.5, %else.4, %fallthrough.3, %fallthrough.1
  %common.ret.op.shrunk = phi i8 [ %.ptroff.ld.0, %fallthrough.1 ], [ %.ptroff.ld.1, %fallthrough.3 ], [ %.ptroff.ld.2, %fallthrough.5 ], [ %., %else.4 ]
  %common.ret.op = zext i8 %common.ret.op.shrunk to i32
  ret i32 %common.ret.op

fallthrough.1:                                    ; preds = %entry
  %zext.0 = zext i32 %x to i64
  %ptroff.0 = getelementptr [27 x i8], [27 x i8]* @const.0, i64 0, i64 %zext.0
  %.ptroff.ld.0 = load i8, i8* %ptroff.0, align 1
  br label %common.ret

else.2:                                           ; preds = %else.0
  %icmp.5 = icmp ult i32 %x, 62
  br i1 %icmp.5, label %fallthrough.5, label %else.4

fallthrough.3:                                    ; preds = %else.0
  %sub.0 = add nsw i32 %x, -26
  %zext.6 = zext i32 %sub.0 to i64
  %ptroff.1 = getelementptr [27 x i8], [27 x i8]* @const.2, i64 0, i64 %zext.6
  %.ptroff.ld.1 = load i8, i8* %ptroff.1, align 1
  br label %common.ret

else.4:                                           ; preds = %else.2
  %icmp.6 = icmp eq i32 %x, 62
  %. = select i1 %icmp.6, i8 43, i8 47
  br label %common.ret

fallthrough.5:                                    ; preds = %else.2
  %sub.1 = add nsw i32 %x, -52
  %zext.12 = zext i32 %sub.1 to i64
  %ptroff.2 = getelementptr [11 x i8], [11 x i8]* @const.4, i64 0, i64 %zext.12
  %.ptroff.ld.2 = load i8, i8* %ptroff.2, align 1
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
