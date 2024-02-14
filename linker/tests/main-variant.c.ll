; ModuleID = 'main-variant.c.bc'
source_filename = "chi/chi-variant.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [5 x i8] c"%ld\0A\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca [5 x [5 x i64]], align 16
  store i32 0, ptr %1, align 4
  %3 = getelementptr inbounds [5 x [5 x i64]], ptr %2, i64 0, i64 0
  %4 = call i64 @Chi(ptr noundef %3, i64 noundef 0)
  %5 = call i32 (ptr, ...) @printf(ptr noundef @.str, i64 noundef %4)
  ret i32 0
}

declare i32 @printf(ptr noundef, ...) #1

; Function Attrs: noinline nounwind optnone uwtable
define internal i64 @Chi(ptr noundef %0, i64 noundef %1) #0 {
  %3 = alloca ptr, align 8
  %4 = alloca i64, align 8
  %5 = alloca [5 x i64], align 16
  %6 = alloca i64, align 8
  store ptr %0, ptr %3, align 8
  store i64 %1, ptr %4, align 8
  store i64 0, ptr %6, align 8
  br label %7

7:                                                ; preds = %136, %2
  %8 = load i64, ptr %6, align 8
  %9 = icmp ult i64 %8, 5
  br i1 %9, label %10, label %139

10:                                               ; preds = %7
  %11 = load ptr, ptr %3, align 8
  %12 = load i64, ptr %6, align 8
  %13 = getelementptr inbounds [5 x i64], ptr %11, i64 %12
  %14 = getelementptr inbounds [5 x i64], ptr %13, i64 0, i64 0
  %15 = load i64, ptr %14, align 8
  %16 = load ptr, ptr %3, align 8
  %17 = load i64, ptr %6, align 8
  %18 = getelementptr inbounds [5 x i64], ptr %16, i64 %17
  %19 = getelementptr inbounds [5 x i64], ptr %18, i64 0, i64 1
  %20 = load i64, ptr %19, align 8
  %21 = xor i64 %20, -1
  %22 = load ptr, ptr %3, align 8
  %23 = load i64, ptr %6, align 8
  %24 = getelementptr inbounds [5 x i64], ptr %22, i64 %23
  %25 = getelementptr inbounds [5 x i64], ptr %24, i64 0, i64 2
  %26 = load i64, ptr %25, align 8
  %27 = and i64 %21, %26
  %28 = xor i64 %15, %27
  %29 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 0
  store i64 %28, ptr %29, align 16
  %30 = load ptr, ptr %3, align 8
  %31 = load i64, ptr %6, align 8
  %32 = getelementptr inbounds [5 x i64], ptr %30, i64 %31
  %33 = getelementptr inbounds [5 x i64], ptr %32, i64 0, i64 1
  %34 = load i64, ptr %33, align 8
  %35 = load ptr, ptr %3, align 8
  %36 = load i64, ptr %6, align 8
  %37 = getelementptr inbounds [5 x i64], ptr %35, i64 %36
  %38 = getelementptr inbounds [5 x i64], ptr %37, i64 0, i64 2
  %39 = load i64, ptr %38, align 8
  %40 = xor i64 %39, -1
  %41 = load ptr, ptr %3, align 8
  %42 = load i64, ptr %6, align 8
  %43 = getelementptr inbounds [5 x i64], ptr %41, i64 %42
  %44 = getelementptr inbounds [5 x i64], ptr %43, i64 0, i64 3
  %45 = load i64, ptr %44, align 8
  %46 = and i64 %40, %45
  %47 = xor i64 %34, %46
  %48 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 1
  store i64 %47, ptr %48, align 8
  %49 = load ptr, ptr %3, align 8
  %50 = load i64, ptr %6, align 8
  %51 = getelementptr inbounds [5 x i64], ptr %49, i64 %50
  %52 = getelementptr inbounds [5 x i64], ptr %51, i64 0, i64 2
  %53 = load i64, ptr %52, align 8
  %54 = load ptr, ptr %3, align 8
  %55 = load i64, ptr %6, align 8
  %56 = getelementptr inbounds [5 x i64], ptr %54, i64 %55
  %57 = getelementptr inbounds [5 x i64], ptr %56, i64 0, i64 3
  %58 = load i64, ptr %57, align 8
  %59 = xor i64 %58, -1
  %60 = load ptr, ptr %3, align 8
  %61 = load i64, ptr %6, align 8
  %62 = getelementptr inbounds [5 x i64], ptr %60, i64 %61
  %63 = getelementptr inbounds [5 x i64], ptr %62, i64 0, i64 4
  %64 = load i64, ptr %63, align 8
  %65 = and i64 %59, %64
  %66 = xor i64 %53, %65
  %67 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 2
  store i64 %66, ptr %67, align 16
  %68 = load ptr, ptr %3, align 8
  %69 = load i64, ptr %6, align 8
  %70 = getelementptr inbounds [5 x i64], ptr %68, i64 %69
  %71 = getelementptr inbounds [5 x i64], ptr %70, i64 0, i64 3
  %72 = load i64, ptr %71, align 8
  %73 = load ptr, ptr %3, align 8
  %74 = load i64, ptr %6, align 8
  %75 = getelementptr inbounds [5 x i64], ptr %73, i64 %74
  %76 = getelementptr inbounds [5 x i64], ptr %75, i64 0, i64 4
  %77 = load i64, ptr %76, align 8
  %78 = xor i64 %77, -1
  %79 = load ptr, ptr %3, align 8
  %80 = load i64, ptr %6, align 8
  %81 = getelementptr inbounds [5 x i64], ptr %79, i64 %80
  %82 = getelementptr inbounds [5 x i64], ptr %81, i64 0, i64 0
  %83 = load i64, ptr %82, align 8
  %84 = and i64 %78, %83
  %85 = xor i64 %72, %84
  %86 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 3
  store i64 %85, ptr %86, align 8
  %87 = load ptr, ptr %3, align 8
  %88 = load i64, ptr %6, align 8
  %89 = getelementptr inbounds [5 x i64], ptr %87, i64 %88
  %90 = getelementptr inbounds [5 x i64], ptr %89, i64 0, i64 4
  %91 = load i64, ptr %90, align 8
  %92 = load ptr, ptr %3, align 8
  %93 = load i64, ptr %6, align 8
  %94 = getelementptr inbounds [5 x i64], ptr %92, i64 %93
  %95 = getelementptr inbounds [5 x i64], ptr %94, i64 0, i64 0
  %96 = load i64, ptr %95, align 8
  %97 = xor i64 %96, -1
  %98 = load ptr, ptr %3, align 8
  %99 = load i64, ptr %6, align 8
  %100 = getelementptr inbounds [5 x i64], ptr %98, i64 %99
  %101 = getelementptr inbounds [5 x i64], ptr %100, i64 0, i64 1
  %102 = load i64, ptr %101, align 8
  %103 = and i64 %97, %102
  %104 = xor i64 %91, %103
  %105 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 4
  store i64 %104, ptr %105, align 16
  %106 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 0
  %107 = load i64, ptr %106, align 16
  %108 = load ptr, ptr %3, align 8
  %109 = load i64, ptr %6, align 8
  %110 = getelementptr inbounds [5 x i64], ptr %108, i64 %109
  %111 = getelementptr inbounds [5 x i64], ptr %110, i64 0, i64 0
  store i64 %107, ptr %111, align 8
  %112 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 1
  %113 = load i64, ptr %112, align 8
  %114 = load ptr, ptr %3, align 8
  %115 = load i64, ptr %6, align 8
  %116 = getelementptr inbounds [5 x i64], ptr %114, i64 %115
  %117 = getelementptr inbounds [5 x i64], ptr %116, i64 0, i64 1
  store i64 %113, ptr %117, align 8
  %118 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 2
  %119 = load i64, ptr %118, align 16
  %120 = load ptr, ptr %3, align 8
  %121 = load i64, ptr %6, align 8
  %122 = getelementptr inbounds [5 x i64], ptr %120, i64 %121
  %123 = getelementptr inbounds [5 x i64], ptr %122, i64 0, i64 2
  store i64 %119, ptr %123, align 8
  %124 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 3
  %125 = load i64, ptr %124, align 8
  %126 = load ptr, ptr %3, align 8
  %127 = load i64, ptr %6, align 8
  %128 = getelementptr inbounds [5 x i64], ptr %126, i64 %127
  %129 = getelementptr inbounds [5 x i64], ptr %128, i64 0, i64 3
  store i64 %125, ptr %129, align 8
  %130 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 4
  %131 = load i64, ptr %130, align 16
  %132 = load ptr, ptr %3, align 8
  %133 = load i64, ptr %6, align 8
  %134 = getelementptr inbounds [5 x i64], ptr %132, i64 %133
  %135 = getelementptr inbounds [5 x i64], ptr %134, i64 0, i64 4
  store i64 %131, ptr %135, align 8
  br label %136

136:                                              ; preds = %10
  %137 = load i64, ptr %6, align 8
  %138 = add i64 %137, 1
  store i64 %138, ptr %6, align 8
  br label %7, !llvm.loop !6

139:                                              ; preds = %7
  %140 = load i64, ptr %4, align 8
  %141 = getelementptr inbounds [5 x i64], ptr %5, i64 0, i64 %140
  %142 = load i64, ptr %141, align 8
  ret i64 %142
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }

!llvm.module.flags = !{!0, !1, !2, !3, !4}
!llvm.ident = !{!5}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 8, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{i32 7, !"frame-pointer", i32 2}
!5 = !{!"clang version 17.0.6 (https://github.com/llvm/llvm-project.git 6009708b4367171ccdbf4b5905cb6a803753fe18)"}
!6 = distinct !{!6, !7}
!7 = !{!"llvm.loop.mustprogress"}
