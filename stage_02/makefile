tst_module: tst_rast.o raster.o font.o rast_asm.o
	cc68x -g tst_rast.o raster.o font.o rast_asm.o -o tst_module
tst_rast.o: tst_rast.c
	cc68x -g -c tst_rast.c
rast_asm.o: rast_asm.s raster.h
	gen -D -L2 rast_asm.s
raster.o: raster.c raster.h types.h bitmap.h
	cc68x -g -c raster.c
font.o: font.c font.h types.h
	cc68x -g -c font.c
