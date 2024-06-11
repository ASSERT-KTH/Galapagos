; ModuleID = '/home/javier/Galapagos/functions/openssl/variants/go/1_BitDeinterleave_8.bc'
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
module asm "\09.ascii \22BitDeinterleave\22"
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22Ai\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -8>\22"
module asm "\09.ascii \22\\n\22"
module asm "\09.ascii \22checksum 24C818B1E3F7C1659049307540BD119EDFAAE4C4\\n\22"
module asm "\09.text"

%functionDescriptor.0 = type { i64 }

@main.BitDeinterleave..f = local_unnamed_addr constant %functionDescriptor.0 { i64 ptrtoint (i64 (i8*, i64)* @main.BitDeinterleave to i64) }
@main..types = constant { i64, [1 x i8*] } zeroinitializer
@go..typelists = internal constant [1 x { i64, [1 x i8*] }*] [{ i64, [1 x i8*] }* @main..types]

; Function Attrs: null_pointer_is_valid
define void @__go_init_main(i8* nest nocapture readnone %nest.2) local_unnamed_addr #0 {
entry:
  call void @runtime.registerTypeDescriptors(i8* nest undef, i64 1, i8* bitcast ([1 x { i64, [1 x i8*] }*]* @go..typelists to i8*))
  ret void
}

; Function Attrs: mustprogress nofree norecurse nosync nounwind null_pointer_is_valid readnone willreturn
define i64 @main.BitDeinterleave(i8* nest nocapture readnone %nest.0, i64 %Ai) #1 {
entry:
  %mod.0 = and i64 %Ai, 1
  %icmp.3 = icmp eq i64 %mod.0, 0
  br i1 %icmp.3, label %then.3, label %fallthrough.3

then.3:                                           ; preds = %entry
  %shr.0 = lshr i64 %Ai, 32
  %trunc.0 = trunc i64 %shr.0 to i32
  %trunc.1 = trunc i64 %Ai to i32
  %iand.0 = and i32 %trunc.1, 65535
  %shl.0 = shl nuw nsw i32 %iand.0, 8
  %ior.0 = or i32 %shl.0, %iand.0
  %iand.1 = and i32 %ior.0, 16711935
  %shl.1 = shl nuw nsw i32 %iand.1, 4
  %ior.1 = or i32 %shl.1, %iand.1
  %iand.2 = and i32 %ior.1, 252645135
  %shl.2 = shl nuw nsw i32 %iand.2, 2
  %ior.2 = or i32 %shl.2, %iand.2
  %iand.3 = and i32 %ior.2, 858993459
  %shl.3 = shl nuw nsw i32 %iand.3, 1
  %ior.3 = or i32 %shl.3, %iand.3
  %iand.4 = and i32 %ior.3, 1431655765
  %shl.4 = shl i32 %trunc.0, 16
  %shr.1 = lshr exact i32 %shl.4, 8
  %ior.4 = or i32 %shr.1, %shl.4
  %iand.5 = and i32 %ior.4, -16711936
  %shr.2 = lshr exact i32 %iand.5, 4
  %ior.5 = or i32 %shr.2, %iand.5
  %iand.6 = and i32 %ior.5, -252645136
  %shr.3 = lshr exact i32 %iand.6, 2
  %ior.6 = or i32 %shr.3, %iand.6
  %iand.7 = and i32 %ior.6, -858993460
  %shr.4 = lshr exact i32 %iand.7, 1
  %ior.7 = or i32 %shr.4, %iand.7
  %iand.8 = and i32 %ior.7, -1431655766
  %shr.5 = lshr i32 %trunc.1, 16
  %shl.5 = shl nuw nsw i32 %shr.5, 8
  %ior.8 = or i32 %shl.5, %shr.5
  %iand.9 = and i32 %ior.8, 16711935
  %shl.6 = shl nuw nsw i32 %iand.9, 4
  %ior.9 = or i32 %shl.6, %iand.9
  %iand.10 = and i32 %ior.9, 252645135
  %shl.7 = shl nuw nsw i32 %iand.10, 2
  %ior.10 = or i32 %shl.7, %iand.10
  %iand.11 = and i32 %ior.10, 858993459
  %shl.8 = shl nuw nsw i32 %iand.11, 1
  %ior.11 = or i32 %shl.8, %iand.11
  %iand.12 = and i32 %ior.11, 1431655765
  %iand.13 = and i32 %trunc.0, -65536
  %shr.6 = lshr exact i32 %iand.13, 8
  %ior.12 = or i32 %shr.6, %iand.13
  %iand.14 = and i32 %ior.12, -16711936
  %shr.7 = lshr exact i32 %iand.14, 4
  %ior.13 = or i32 %shr.7, %iand.14
  %iand.15 = and i32 %ior.13, -252645136
  %shr.8 = lshr exact i32 %iand.15, 2
  %ior.14 = or i32 %shr.8, %iand.15
  %iand.16 = and i32 %ior.14, -858993460
  %shr.9 = lshr exact i32 %iand.16, 1
  %ior.15 = or i32 %shr.9, %iand.16
  %iand.17 = and i32 %ior.15, -1431655766
  %ior.16 = or i32 %iand.17, %iand.12
  %zext.0 = zext i32 %ior.16 to i64
  %shl.9 = shl nuw i64 %zext.0, 32
  %ior.17 = or i32 %iand.8, %iand.4
  %zext.1 = zext i32 %ior.17 to i64
  %ior.18 = or i64 %shl.9, %zext.1
  br label %fallthrough.3

fallthrough.3:                                    ; preds = %then.3, %entry
  %Ai.addr.0 = phi i64 [ %ior.18, %then.3 ], [ %Ai, %entry ]
  ret i64 %Ai.addr.0
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
