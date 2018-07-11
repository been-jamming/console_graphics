#define true 1
#define false 0

typedef unsigned char bool;

typedef struct color color;

struct color{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};

typedef struct variance variance;

struct variance{
	unsigned int num_elements;
	double m;
	double mean;
};

typedef struct screen screen;

struct screen{
	unsigned int size_x;
	unsigned int size_y;
	color **data;
	char **chars;
	color **foreground_colors;
	color **background_colors;
	double **best_variance;
	variance **foreground_red[96];
	variance **foreground_green[96];
	variance **foreground_blue[96];
	variance **background_red[96];
	variance **background_green[96];
	variance **background_blue[96];
	char *print_str;
};

bool color_compare(color a, color b);

double get_variance(variance *v);

void add_value(variance *v, double value);

void subtract_value(variance *v, double value);

screen *create_screen(unsigned int size_x, unsigned int size_y);

void initialize_screen(screen *s);

void set_char(screen *s, unsigned int x, unsigned int y, char c, unsigned char foreground, unsigned char background);

unsigned char match_color(color c);

void initialize_pixel(screen *s, unsigned int x, unsigned int y, color c);

void set_pixel(screen *s, unsigned int x, unsigned int y, color c);

void rect(screen *s, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, color c);

void display(screen *s);