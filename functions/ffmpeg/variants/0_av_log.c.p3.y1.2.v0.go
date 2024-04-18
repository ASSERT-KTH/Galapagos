package main 

import (
	"log"
	"fmt"
)

func av_log(avcl interface{}, level int, fmt string, v ...interface{}) {
	s := fmt.Sprintf(fmt, v...)
	log.Println(s)
}
