CC = /opt/gbdk/bin/lcc

make:
	$(CC) -Wa-l -Wf-bo1 -c -o gfx1.o gfx1.s
	$(CC) -Wa-l -Wf-bo2 -c -o gfx2.o gfx2.s
	$(CC) -Wa-l -Wf-bo3 -c -o gfx3.o gfx3.s
	$(CC) -Wa-l -c -o main.o main.c
	$(CC) -Wl-m -Wl-yt1 -Wl-yo4 -Wl-ya4 -o output.gb gfx1.o gfx2.o gfx3.o main.o

clean:
	rm *.lst *.o *.map *.gb

