; ModuleID = '/home/javier/Galapagos/functions/libsodium/variants/go/1_b64_byte_to_urlsafe_char_8.bc'
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
module asm "\09.ascii \22 <inl:1249>\\n\22"
module asm "\09.ascii \22 // /home/javier/Galapagos/functions/libsodium/variants/go/1_b64_byte_to_urlsafe_char_8.go:3\\n { //4\\n  if (x < $convert(<type -7>, 26 )) { //4\\n   { //5\\n    $ret0 = $convert(<type -3>, ($convert(<type -7>, 65' ) + x)) //5\\n    return //5\\n   } //0\\n  } else { //6\\n   { //6\\n    if (x < $convert(<type -7>, 52 )) { //6\\n     { //7\\n      $ret0 = $convert(<type -3>, ($convert(<type -7>, 97' ) + (x - $convert(<type -7>, 26 )))) //7\\n      return //7\\n     } //0\\n    } else { //8\\n     { //8\\n      if (x < $convert(<type -7>, 62 )) { //8\\n       { //9\\n        $ret0 = $convert(<type -3>, ($convert(<type -7>, 48' ) + (x - $convert(<type -7>, 52 )))) //9\\n        return //9\\n       } //0\\n      } else { //10\\n       { //10\\n        if (x == $convert(<type -7>, 62 )) { //10\\n         { //11\\n          $ret0 = $convert(<type -3>, 45' ) //11\\n          return //11\\n         } //0\\n        } else { //12\\n         { //12\\n          if (x == $convert(<type -7>, 63 )) { //12\\n           { //13\\n            $ret0 = $convert(<type -3>, 95' ) //13\\n            return //13\\n           } //0\\n          } //12\\n         } //14\\n        } //10\\n       } //14\\n      } //8\\n     } //14\\n    } //6\\n   } //14\\n  } //4\\n } //14\\n { //15\\n  $ret0 = $convert(<type -3>, -1 ) //15\\n  return //15\\n } //0\\n\22"
module asm "\09.ascii \22checksum 3955432A8800C8043BF9CAE4E04433ED100026E9\\n\22"
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
  %icmp.4 = icmp ult i32 %x, 26
  br i1 %icmp.4, label %then.0, label %else.0

common.ret:                                       ; preds = %else.2, %then.2, %then.1, %then.0
  %common.ret.op = phi i32 [ %add.0, %then.0 ], [ %add.1, %then.1 ], [ %add.2, %then.2 ], [ %switch.select20, %else.2 ]
  ret i32 %common.ret.op

then.0:                                           ; preds = %entry
  %add.0 = add nuw nsw i32 %x, 65
  br label %common.ret

else.0:                                           ; preds = %entry
  %icmp.3 = icmp ult i32 %x, 52
  br i1 %icmp.3, label %then.1, label %else.1

then.1:                                           ; preds = %else.0
  %add.1 = add nuw nsw i32 %x, 71
  br label %common.ret

else.1:                                           ; preds = %else.0
  %icmp.2 = icmp ult i32 %x, 62
  br i1 %icmp.2, label %then.2, label %else.2

then.2:                                           ; preds = %else.1
  %add.2 = add nsw i32 %x, -4
  br label %common.ret

else.2:                                           ; preds = %else.1
  %switch.selectcmp = icmp eq i32 %x, 63
  %switch.select = select i1 %switch.selectcmp, i32 95, i32 -1
  %switch.selectcmp19 = icmp eq i32 %x, 62
  %switch.select20 = select i1 %switch.selectcmp19, i32 45, i32 %switch.select
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
