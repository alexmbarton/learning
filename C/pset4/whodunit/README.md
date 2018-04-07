# Questions

## What's `stdint.h`?

Defines c such as uint8_t

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To write implementation independent code. It guarentees a xbit type (8,32,16);

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

8, 32, 32, 16

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The BFType and it must be `BM` or `424D`

## What's the difference between `bfSize` and `biSize`?

`bfSize` is the size of the image plus the headers (or 54 bytes). `biSize` is the size of `BITMAPINFOHEADER`

## What does it mean if `biHeight` is negative?

If `biHeight` is negative, the bitmap is a top-down DIB with the origin at the upper left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

`biBitCount`

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

The file may not exist

## Why is the third argument to `fread` always `1` in our code?

To read 1 data element at a time which is the size passed to the function

## What value does line 63 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

`0`

## What does `fseek` do?

Change the location of the pointer

## What is `SEEK_CUR`?

Changes the location of the pointer relative to where is currently is
