# Results

## Alsa-lib

### No optimizations

```tex
\midrule
\cellcolor{white} & alaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{6} & \numprint{5}  \\
\cellcolor{white} & iec958\_parity & \numprint{10} & \numprint{8} & \numprint{8} & \numprint{8} & \numprint{7} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{8}  \\
\cellcolor{white} & add & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{1} & \numprint{1}  \\
\cellcolor{white} & ulaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{3}  \\
\cellcolor{white}
\multirow{-5}{*}{alsa-lib} & val\_seg & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{2} & \numprint{2} & \numprint{9} & \numprint{1} & \numprint{1} & \numprint{0} & \numprint{0}  \\
```

### -O0

```tex
\midrule
\cellcolor{white} & alaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{6} & \numprint{5}  \\
\cellcolor{white} & iec958\_parity & \numprint{10} & \numprint{8} & \numprint{8} & \numprint{8} & \numprint{7} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{9}  \\
\cellcolor{white} & add & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{1} & \numprint{1}  \\
\cellcolor{white} & ulaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{4}  \\
\cellcolor{white}
\multirow{-5}{*}{alsa-lib} & val\_seg & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{2} & \numprint{2} & \numprint{9} & \numprint{1} & \numprint{1} & \numprint{0} & \numprint{0}  \\
```

### -O1

```tex
\midrule
\cellcolor{white} & alaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{6} & \numprint{4}  \\
\cellcolor{white} & iec958\_parity & \numprint{10} & \numprint{8} & \numprint{8} & \numprint{8} & \numprint{7} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{8}  \\
\cellcolor{white} & add & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{1} & \numprint{1}  \\
\cellcolor{white} & ulaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{3}  \\
\cellcolor{white}
\multirow{-5}{*}{alsa-lib} & val\_seg & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{2} & \numprint{2} & \numprint{9} & \numprint{1} & \numprint{1} & \numprint{0} & \numprint{0}  \\
```

### -O2

```tex
\midrule
\cellcolor{white} & alaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{6} & \numprint{4}  \\
\cellcolor{white} & iec958\_parity & \numprint{10} & \numprint{8} & \numprint{8} & \numprint{8} & \numprint{7} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{8}  \\
\cellcolor{white} & add & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{1} & \numprint{1}  \\
\cellcolor{white} & ulaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{3}  \\
\cellcolor{white}
\multirow{-5}{*}{alsa-lib} & val\_seg & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{2} & \numprint{2} & \numprint{9} & \numprint{1} & \numprint{1} & \numprint{0} & \numprint{0}  \\
```

### -O3

```tex
\midrule
\cellcolor{white} & alaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{6} & \numprint{6}  \\
\cellcolor{white} & iec958\_parity & \numprint{10} & \numprint{8} & \numprint{8} & \numprint{8} & \numprint{7} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{8}  \\
\cellcolor{white} & add & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{1} & \numprint{1} & \numprint{1} & \numprint{1}  \\
\cellcolor{white} & ulaw\_to\_s16 & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{9} & \numprint{9} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{3}  \\
\cellcolor{white}
\multirow{-5}{*}{alsa-lib} & val\_seg & \numprint{10} & \numprint{10} & \numprint{10} & \numprint{2} & \numprint{2} & \numprint{9} & \numprint{1} & \numprint{1} & \numprint{0} & \numprint{0}  \\
```

## FFMPEG

### No optimizations

### -O0

### -O1

### -O2

### -O3

## libgcrypt

How to change optimization flags: change lines 2286, 2372

### No optimizations

### -O0

### -O1

### -O2

### -O3

## liboqs

### No optimizations

### -O0

### -O1

### -O2

### -O3

## libsodium

### No optimizations

### -O0

### -O1

### -O2

### -O3

## openssl

### No optimizations

### -O0

### -O1

### -O2

### -O3
