; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/go/2_BitInterleave_0.bc'
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
module asm "\09.ascii \22BitInterleave\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22Ai\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum 4D9E72743718C28E295D74F99573D8CBC365E99D\\n\22"
module asm "\09.text"

%functionDescriptor.0 = type { i64 }

@main.BitInterleave..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (i64 (i8*, i64)* @main.BitInterleave to i64) }
@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define i64 @main.BitInterleave(i8* nest nocapture readnone %nest.0, i64 %Ai) #1 {
entry:
  %trunc.0 = trunc i64 %Ai to i32
  %shr.0 = lshr i64 %Ai, 32
  %trunc.1 = trunc i64 %shr.0 to i32
  %shl.0 = shl i32 %trunc.0, 8
  %ior.0 = or i32 %shl.0, %trunc.0
  %iand.0 = and i32 %ior.0, 16711935
  %shl.1 = shl nuw nsw i32 %iand.0, 4
  %ior.1 = or i32 %shl.1, %iand.0
  %iand.1 = and i32 %ior.1, 252645135
  %shl.2 = shl nuw nsw i32 %iand.1, 2
  %ior.2 = or i32 %shl.2, %iand.1
  %iand.2 = and i32 %ior.2, 858993459
  %shl.3 = shl nuw nsw i32 %iand.2, 1
  %ior.3 = or i32 %shl.3, %iand.2
  %iand.3 = and i32 %ior.3, 1431655765
  %shl.4 = shl i32 %trunc.1, 8
  %ior.4 = or i32 %shl.4, %trunc.1
  %iand.4 = and i32 %ior.4, 16711935
  %shl.5 = shl nuw nsw i32 %iand.4, 4
  %ior.5 = or i32 %shl.5, %iand.4
  %iand.5 = and i32 %ior.5, 252645135
  %shl.6 = shl nuw nsw i32 %iand.5, 2
  %ior.6 = or i32 %shl.6, %iand.5
  %iand.6 = and i32 %ior.6, 858993459
  %shl.7 = shl nuw nsw i32 %iand.6, 1
  %ior.7 = or i32 %shl.7, %iand.6
  %iand.7 = and i32 %ior.7, 1431655765
  %zext.0 = zext i32 %iand.7 to i64
  %zext.1 = zext i32 %iand.3 to i64
  %shl.8 = shl nuw nsw i64 %zext.0, 32
  %ior.8 = or i64 %shl.8, %zext.1
  ret i64 %ior.8
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
