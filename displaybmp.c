#include "console_graphics2.h"
#include "qdbmp.h"
#include <stdio.h>

int main(int argc, char* argv[]){
	color c;
	unsigned int width, height;
	unsigned int x, y;
	BMP* bmp;
	screen *s;

	if(argc != 2){
		fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
		return 0;
	}

	printf("reading bitmap...\n");
	bmp = BMP_ReadFile(argv[1]);
	BMP_CHECK_ERROR(stdout, -1);

	width = BMP_GetWidth(bmp);
	height = BMP_GetHeight(bmp);
	
	printf("loading...\n");
	s = create_screen(width/8 + 1, height/13 + 1);
	for(x = 0; x < width; x++){
		for(y = 0; y < height; y++){
			BMP_GetPixelRGB(bmp, x, y, &c.red, &c.green, &c.blue);
			initialize_pixel(s, x, y, c);
		}
	}
	display(s);
	BMP_Free(bmp);
	
	printf("\e[0;0m");

	return 0;
}