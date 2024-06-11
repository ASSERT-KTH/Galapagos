; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/go/1_b64_byte_to_urlsafe_char_9.bc'
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
module asm "\09.ascii \22b64ByteToURLSafeChar\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22x\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -7>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum 5DBA5913BCE093E9EDBDECA3D71ACE2F86B1BC2A\\n\22"
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
define i32 @main.b64ByteToURLSafeChar(i8* nest nocapture readnone %nest.0, i32 %x) local_unnamed_addr #1 {
entry:
  %icmp.1 = icmp ugt i32 %x, 25
  br i1 %icmp.1, label %then.2, label %else.1

common.ret:                                       ; preds = %label.3, %else.5, %else.3, %else.1
  %common.ret.op = phi i32 [ %add.0, %else.1 ], [ %add.1, %else.3 ], [ %add.2, %else.5 ], [ %switch.select30, %label.3 ]
  ret i32 %common.ret.op

else.1:                                           ; preds = %entry
  %add.0 = add nuw nsw i32 %x, 65
  br label %common.ret

then.2:                                           ; preds = %entry
  %icmp.5 = icmp ugt i32 %x, 51
  br i1 %icmp.5, label %label.2, label %else.3

else.3:                                           ; preds = %then.2
  %add.1 = add nuw nsw i32 %x, 71
  br label %common.ret

label.2:                                          ; preds = %then.2
  %icmp.9 = icmp ult i32 %x, 62
  br i1 %icmp.9, label %else.5, label %label.3

else.5:                                           ; preds = %label.2
  %add.2 = add nsw i32 %x, -4
  br label %common.ret

label.3:                                          ; preds = %label.2
  %switch.selectcmp = icmp eq i32 %x, 63
  %switch.select = select i1 %switch.selectcmp, i32 95, i32 -1
  %switch.selectcmp29 = icmp eq i32 %x, 62
  %switch.select30 = select i1 %switch.selectcmp29, i32 45, i32 %switch.select
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
