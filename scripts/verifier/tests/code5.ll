; ModuleID = '/Users/javierca/Documents/Develop/chatgtp4sw/rosetta_codes/quicksort/quicksort.p0.v35.c'
source_filename = "/Users/javierca/Documents/Develop/chatgtp4sw/rosetta_codes/quicksort/quicksort.p0.v35.c"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx12.0.0"

@__const.main.a = private unnamed_addr constant [10 x i32] [i32 4, i32 65, i32 2, i32 -31, i32 0, i32 99, i32 2, i32 83, i32 782, i32 1], align 16
@.str = private unnamed_addr constant [4 x i8] c"%d \00", align 1

; Function Attrs: nofree nounwind ssp uwtable
define i32 @main() local_unnamed_addr #0 {
  %1 = alloca [10 x i32], align 16
  call void @llvm.lifetime.start.p0(i64 40, ptr nonnull %1) #6
  call void @llvm.memcpy.p0.p0.i64(ptr noundef nonnull align 16 dereferenceable(40) %1, ptr noundef nonnull align 16 dereferenceable(40) @__const.main.a, i64 40, i1 false)
  %2 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 4)
  %3 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 1
  %4 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 65)
  %5 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 2
  %6 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 2)
  %7 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 3
  %8 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef -31)
  %9 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 4
  %10 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 0)
  %11 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 5
  %12 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 99)
  %13 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 6
  %14 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 2)
  %15 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 7
  %16 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 83)
  %17 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 8
  %18 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 782)
  %19 = getelementptr inbounds [10 x i32], ptr %1, i64 0, i64 9
  %20 = tail call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef 1)
  %21 = tail call i32 @putchar(i32 10)
  call void @quicksort(ptr noundef nonnull %1, i32 noundef 0, i32 noundef 9)
  %22 = load i32, ptr %1, align 16, !tbaa !5
  %23 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %22)
  %24 = load i32, ptr %3, align 4, !tbaa !5
  %25 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %24)
  %26 = load i32, ptr %5, align 8, !tbaa !5
  %27 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %26)
  %28 = load i32, ptr %7, align 4, !tbaa !5
  %29 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %28)
  %30 = load i32, ptr %9, align 16, !tbaa !5
  %31 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %30)
  %32 = load i32, ptr %11, align 4, !tbaa !5
  %33 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %32)
  %34 = load i32, ptr %13, align 8, !tbaa !5
  %35 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %34)
  %36 = load i32, ptr %15, align 4, !tbaa !5
  %37 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %36)
  %38 = load i32, ptr %17, align 16, !tbaa !5
  %39 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %38)
  %40 = load i32, ptr %19, align 4, !tbaa !5
  %41 = call i32 (ptr, ...) @printf(ptr noundef nonnull dereferenceable(1) @.str, i32 noundef %40)
  %42 = call i32 @putchar(i32 10)
  call void @llvm.lifetime.end.p0(i64 40, ptr nonnull %1) #6
  ret i32 0
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #1

; Function Attrs: mustprogress nocallback nofree nounwind willreturn memory(argmem: readwrite)
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #2

; Function Attrs: nofree nounwind
declare noundef i32 @printf(ptr nocapture noundef readonly, ...) local_unnamed_addr #3

; Function Attrs: nofree nosync nounwind ssp memory(argmem: readwrite) uwtable
define void @quicksort(ptr noundef %0, i32 noundef %1, i32 noundef %2) local_unnamed_addr #4 {
  %4 = icmp sgt i32 %2, %1
  br i1 %4, label %5, label %49

5:                                                ; preds = %3, %45
  %6 = phi i32 [ %47, %45 ], [ %1, %3 ]
  %7 = sub nsw i32 %2, %6
  %8 = sdiv i32 %7, 2
  %9 = add nsw i32 %8, %6
  %10 = sext i32 %9 to i64
  %11 = getelementptr inbounds i32, ptr %0, i64 %10
  %12 = load i32, ptr %11, align 4, !tbaa !5
  %13 = icmp sgt i32 %6, %2
  br i1 %13, label %45, label %14

14:                                               ; preds = %5, %41
  %15 = phi i32 [ %43, %41 ], [ %6, %5 ]
  %16 = phi i32 [ %42, %41 ], [ %2, %5 ]
  %17 = sext i32 %15 to i64
  br label %18

18:                                               ; preds = %18, %14
  %19 = phi i64 [ %23, %18 ], [ %17, %14 ]
  %20 = getelementptr inbounds i32, ptr %0, i64 %19
  %21 = load i32, ptr %20, align 4, !tbaa !5
  %22 = icmp slt i32 %21, %12
  %23 = add i64 %19, 1
  br i1 %22, label %18, label %24, !llvm.loop !9

24:                                               ; preds = %18
  %25 = getelementptr inbounds i32, ptr %0, i64 %19
  %26 = trunc i64 %19 to i32
  %27 = sext i32 %16 to i64
  br label %28

28:                                               ; preds = %28, %24
  %29 = phi i64 [ %33, %28 ], [ %27, %24 ]
  %30 = getelementptr inbounds i32, ptr %0, i64 %29
  %31 = load i32, ptr %30, align 4, !tbaa !5
  %32 = icmp sgt i32 %31, %12
  %33 = add i64 %29, -1
  br i1 %32, label %28, label %34, !llvm.loop !11

34:                                               ; preds = %28
  %35 = trunc i64 %29 to i32
  %36 = icmp sgt i32 %26, %35
  br i1 %36, label %41, label %37

37:                                               ; preds = %34
  %38 = getelementptr inbounds i32, ptr %0, i64 %29
  store i32 %31, ptr %25, align 4, !tbaa !5
  store i32 %21, ptr %38, align 4, !tbaa !5
  %39 = add nsw i32 %26, 1
  %40 = add nsw i32 %35, -1
  br label %41

41:                                               ; preds = %37, %34
  %42 = phi i32 [ %40, %37 ], [ %35, %34 ]
  %43 = phi i32 [ %39, %37 ], [ %26, %34 ]
  %44 = icmp sgt i32 %43, %42
  br i1 %44, label %45, label %14, !llvm.loop !12

45:                                               ; preds = %41, %5
  %46 = phi i32 [ %2, %5 ], [ %42, %41 ]
  %47 = phi i32 [ %6, %5 ], [ %43, %41 ]
  tail call void @quicksort(ptr noundef nonnull %0, i32 noundef %6, i32 noundef %46)
  %48 = icmp slt i32 %47, %2
  br i1 %48, label %5, label %49

49:                                               ; preds = %45, %3
  ret void
}

; Function Attrs: mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite)
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #1

; Function Attrs: nofree nounwind
declare noundef i32 @putchar(i32 noundef) local_unnamed_addr #5

attributes #0 = { nofree nounwind ssp uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #1 = { mustprogress nocallback nofree nosync nounwind willreturn memory(argmem: readwrite) }
attributes #2 = { mustprogress nocallback nofree nounwind willreturn memory(argmem: readwrite) }
attributes #3 = { nofree nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #4 = { nofree nosync nounwind ssp memory(argmem: readwrite) uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #5 = { nofree nounwind }
attributes #6 = { nounwind }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"uwtable", i32 2}
!3 = !{i32 7, !"frame-pointer", i32 2}
!4 = !{!"Homebrew clang version 16.0.1"}
!5 = !{!6, !6, i64 0}
!6 = !{!"int", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C/C++ TBAA"}
!9 = distinct !{!9, !10}
!10 = !{!"llvm.loop.mustprogress"}
!11 = distinct !{!11, !10}
!12 = distinct !{!12, !10}
