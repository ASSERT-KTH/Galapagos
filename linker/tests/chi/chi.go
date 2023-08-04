package main

func Chi(A *[5][5]uint64, i uint64) uint64 {
    var C [5]uint64

    for y := 0; y < 5; y++ {
        C[0] = A[y][0] ^ (^A[y][1] & A[y][2])
        C[1] = A[y][1] ^ (^A[y][2] & A[y][3])
        C[2] = A[y][2] ^ (^A[y][3] & A[y][4])
        C[3] = A[y][3] ^ (^A[y][4] & A[y][0])
        C[4] = A[y][4] ^ (^A[y][0] & A[y][1])

        A[y][0] = C[0]
        A[y][1] = C[1]
        A[y][2] = C[2]
        A[y][3] = C[3]
        A[y][4] = C[4]
    }

	return C[i]
}

func main() {
	var A [5][5]uint64
	Chi(&A, 4)
}