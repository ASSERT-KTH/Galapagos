; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/go/1_b64_byte_to_urlsafe_char_2.bc'
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
module asm "\09.ascii \22 (\22"
module asm "\09.ascii \22$ret0\22"
module asm "\09.ascii \22 \22"
module asm "\09.ascii \22<type -3>\22"
module asm "\09.ascii \22)\22"
module asm "\09.ascii \22 <inl:1289>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/libsodium/variants/go/1_b64_byte_to_urlsafe_char_2.go:3\\n { //4\\n  if (x <= $convert(<type -7>, 63 )) { //4\\n   { //5\\n    if (x < $convert(<type -7>, 26 )) { //5\\n     { //6\\n      $ret0 = $convert(<type -3>, (x + $convert(<type -7>, 65' ))) //6\\n      return //6\\n     } //0\\n    } else { //7\\n     { //7\\n      if (x < $convert(<type -7>, 52 )) { //7\\n       { //8\\n        $ret0 = $convert(<type -3>, ((x + $convert(<type -7>, 97' )) - $convert(<type -7>, 26 ))) //8\\n        return //8\\n       } //0\\n      } else { //9\\n       { //9\\n        if (x < $convert(<type -7>, 62 )) { //9\\n         { //10\\n          $ret0 = $convert(<type -3>, ((x + $convert(<type -7>, 48' )) - $convert(<type -7>, 52 ))) //10\\n          return //10\\n         } //0\\n        } else { //11\\n         { //11\\n          if (x == $convert(<type -7>, 62 )) { //11\\n           { //12\\n            $ret0 = $convert(<type -3>, 45' ) //12\\n            return //12\\n           } //0\\n          } else { //13\\n           { //14\\n            $ret0 = $convert(<type -3>, 95' ) //14\\n            return //14\\n           } //0\\n          } //11\\n         } //15\\n        } //9\\n       } //15\\n      } //7\\n     } //15\\n    } //5\\n   } //15\\n  } //4\\n } //16\\n { //17\\n  $ret0 = $convert(<type -3>, -1 ) //17\\n  return //17\\n } //0\\n\22"
module asm "\09.ascii \22checksum 278845C2F49679160E10FC335A9F124DD7219EA6\\n\22"
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
  %icmp.4 = icmp ult i32 %x, 64
  br i1 %icmp.4, label %then.0, label %common.ret

then.0:                                           ; preds = %entry
  %icmp.3 = icmp ult i32 %x, 26
  br i1 %icmp.3, label %then.1, label %else.1

common.ret:                                       ; preds = %else.3, %then.3, %then.2, %then.1, %entry
  %common.ret.op = phi i32 [ %add.0, %then.1 ], [ %sub.0, %then.2 ], [ %sub.1, %then.3 ], [ -1, %entry ], [ %., %else.3 ]
  ret i32 %common.ret.op

then.1:                                           ; preds = %then.0
  %add.0 = add nuw nsw i32 %x, 65
  br label %common.ret

else.1:                                           ; preds = %then.0
  %icmp.2 = icmp ult i32 %x, 52
  br i1 %icmp.2, label %then.2, label %else.2

then.2:                                           ; preds = %else.1
  %sub.0 = add nuw nsw i32 %x, 71
  br label %common.ret

else.2:                                           ; preds = %else.1
  %icmp.1 = icmp ult i32 %x, 62
  br i1 %icmp.1, label %then.3, label %else.3

then.3:                                           ; preds = %else.2
  %sub.1 = add nsw i32 %x, -4
  br label %common.ret

else.3:                                           ; preds = %else.2
  %icmp.0 = icmp eq i32 %x, 62
  %. = select i1 %icmp.0, i32 45, i32 95
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