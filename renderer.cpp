#include "renderer.hpp"

Renderer::Renderer() {

}

Renderer::Renderer(std::string id, void (*function)(Plane*)) {
	this->id = id;
	this->function = function;
}

void Renderer::render() {
	function(plane);
}

void phoenix_Julia(Plane* plane) {
        int i, j, k;
        double series[2];
	double past_series[2];
	double tmppast_serie;
        double tmpserie;
        double c[2] = {0.269, 0.01};   // 0.01 to tak naprawdę 0.01i, dlatego też konieczna była modyfikacja wzoru
        double val;                    // zeby móc wrocic do podawania na c[1] liczby nie zespolonej we wzorze, nalezy 
        double x, y;                   // zmienic - c[1]*past_series[1] na + c[1]*past_series[0] a c[1]*past_series[0] na c[1]*past_series[1]
        double dx = (plane->right - plane->left) / plane->width; /* Left -> Right */
        double dy = -(plane->up - plane->down) / plane->height; /* Up -> Down */

        for(i = 0, y = plane->up; i < plane->height; ++i, y += dy) {
                for(j = 0, x = plane->left; j < plane->width; j++, x += dx) {
                        series[0]=x;
                        series[1]=y;
			past_series[0]=0;
			past_series[1]=0;
                        for (k = 0; k < 100; ++k) {
                                tmpserie = series[0]*series[0] - series[1]*series[1] + c[0] - c[1]*past_series[1];
				tmppast_serie = series[1];
                                series[1] = 2*series[0]*series[1] + c[1]*past_series[0];
				past_series[0] = series[0];
				past_series[1] = tmppast_serie;
                                series[0] = tmpserie;
                                if ((series[0]*series[0] + series[1]*series[1]) > 4)
                                        break;
                        }

                        val = (double)k/100;

                        plane->color( val, plane->data + (i*plane->width + j)*3);
                }
        }
}

void quadratur_Mandelbar(Plane* plane) {
        int i, j, k;
        double series[2];
        double tmpserie;
        double val;
        double x, y;
        double dx = (plane->right - plane->left) / (double)(plane->width); /* Left -> Right */
        double dy = -(plane->up - plane->down) / (double)(plane->height); /* Up -> Down */

        for(i = 0, y = plane->up; i < plane->height; ++i, y += dy) {
                for(j = 0, x = plane->left; j < plane->width; j++, x += dx) {
                        series[0]=0;
                        series[1]=0;
                        for (k = 0; k < 100; ++k) {
                                tmpserie = series[0]*series[0]*series[0]*series[0] - 6*series[0]*series[0]*series[1]*series[1] + series[1]*series[1]*series[1]*series[1]+x;
                                series[1] = -(4*series[0]*series[0]*series[0]*series[1] - 4*series[0]*series[1]*series[1]*series[1]) + y;
                                series[0] = tmpserie;
                                if ((series[0]*series[0] + series[1]*series[1]) > 4)
                                        break;
                        }

                        val = (double)k/100;

                        plane->color( val, plane->data + (i*plane->width + j)*3);
                }
        }
}

void quadratur_Mandelbrot(Plane* plane) {
	int i, j, k;
        double series[2];
        double tmpserie;
        double val;
        double x, y;
        double dx = (plane->right - plane->left) / (double)(plane->width); /* Left -> Right */
        double dy = -(plane->up - plane->down) / (double)(plane->height); /* Up -> Down */

        for(i = 0, y = plane->up; i < plane->height; ++i, y += dy) {
                for(j = 0, x = plane->left; j < plane->width; j++, x += dx) {
                        series[0]=0;
                        series[1]=0;
                        for (k = 0; k < 100; ++k) {
                                tmpserie = series[0]*series[0]*series[0]*series[0] - 6*series[0]*series[0]*series[1]*series[1] + series[1]*series[1]*series[1]*series[1]+x;
                                series[1] = 4*series[0]*series[0]*series[0]*series[1] - 4*series[0]*series[1]*series[1]*series[1] + y;
                                series[0] = tmpserie;
                                if ((series[0]*series[0] + series[1]*series[1]) > 4)
                                        break;
                        }

                        val = (double)k/100;

                        plane->color( val, plane->data + (i*plane->width + j)*3);
                }
        }
}


void set_Mandelbrot(Plane* plane) {
	int i, j, k;
	double series[2];
	double tmpserie;
	double val;
	double x, y;
	double dx = (plane->right - plane->left) / (double)(plane->width); /* Left -> Right */
	double dy = -(plane->up - plane->down) / (double)(plane->height); /* Up -> Down */

	for(i = 0, y = plane->up; i < plane->height; ++i, y += dy) {
		for(j = 0, x = plane->left; j < plane->width; j++, x += dx) {
			series[0]=0;
			series[1]=0;
			for (k = 0; k < 100; ++k) {
				tmpserie = series[0]*series[0] - series[1]*series[1] + x;
				series[1] = 2*series[0]*series[1] + y;
				series[0] = tmpserie;
				if ((series[0]*series[0] + series[1]*series[1]) > 4)
					break;
			}

			val = (double)k/100;

			plane->color( val, plane->data + (i*plane->width + j)*3);
		}
	}
}

void set_Julia(Plane* plane) {
	int i, j, k;
	double series[2];
	double tmpserie;
	double c[2] = {-0.123, 0.745};
	double val;
	double x, y;
	double dx = (plane->right - plane->left) / plane->width; /* Left -> Right */
	double dy = -(plane->up - plane->down) / plane->height; /* Up -> Down */

	for(i = 0, y = plane->up; i < plane->height; ++i, y += dy) {
		for(j = 0, x = plane->left; j < plane->width; j++, x += dx) {
			series[0]=x;
			series[1]=y;
			for (k = 0; k < 100; ++k) {
				tmpserie = series[0]*series[0] - series[1]*series[1] + c[0];
				series[1] = 2*series[0]*series[1] + c[1];
				series[0] = tmpserie;
				if ((series[0]*series[0] + series[1]*series[1]) > 4)
					break;
			}

			val = (double)k/100;

			plane->color( val, plane->data + (i*plane->width + j)*3);
		}
	}
}

void cubic_Julia(Plane* plane) {
	int i, j, k;
	double series[2];
	double tmpserie;
	double c[2] = {-0.123,0.745};
	double val;
	double x, y;
	double dx = (plane->right - plane->left) / plane->width; /* Left -> Right */
	double dy = -(plane->up - plane->down) / plane->height; /* Up -> Down */

	for(i = 0, y = plane->up; i < plane->height; ++i, y += dy) {
		for(j = 0, x = plane->left; j < plane->width; j++, x += dx) {
			series[0]=x;
			series[1]=y;
			for (k = 0; k < 100; ++k) {
				tmpserie = series[0]*series[0]*series[0] - 3*series[0]*series[1]*series[1] + c[0];
				series[1] = 3*series[0]*series[0]*series[1] - series[1]*series[1]*series[1] + c[1];
				series[0] = tmpserie;
				if ((series[0]*series[0] + series[1]*series[1]) > 4)
					break;
			}

			val = (double)k/100;

			plane->color( val, plane->data + (i*plane->width + j)*3);
		}
	}
}

static r_keys r_map[] = {
	{"Mandelbrot", set_Mandelbrot},
	{"Julia", set_Julia},
	{"Cubic Julia", cubic_Julia},
	{"Quadratur Mandelbrot", quadratur_Mandelbrot},
	{"Quadratur Mandelbar", quadratur_Mandelbar},
	{"Phoenix Julia", phoenix_Julia}
};

#define NUM_RENDERERS (sizeof(r_map)/sizeof(r_keys))


static void color_yellow(double x, unsigned char* pixel) {
	unsigned char pal[][3] = {{0,0,0}, {0, 16, 128}, {255, 0, 0}, {255, 255, 48}};
	for(int i = 0; i < 3; ++i) {
		pixel[i] = (pal[0][i] * (1.0- x) + pal[1][i] * x ) * (1.0 - x)  + x * (pal[2][i] * (1-x) + pal[3][i] * x);
	}
}

static void color_grayscale(double x, unsigned char* pixel) {
	for	(int i = 0; i < 3; ++i) {
		pixel[i] = 255 * x;
	}
}

static inline void color_blue(double x, unsigned char* pixel) {
	unsigned char pal[][3] = {{0, 0, 0}, {13, 25, 255}, {36, 39, 208}, {57, 229, 235}};
	for(int i = 0; i < 3; ++i) {
		pixel[i] = (pal[0][i] * (1.0- x) + pal[1][i] * x ) * (1.0 - x)  + x * (pal[2][i] * (1-x) + pal[3][i] * x);
	}
}

static inline void color_green(double x, unsigned char* pixel) {
	unsigned char pal[][3] = {{19, 65, 0}, {255, 255, 255}, {252, 255, 23}, {225, 208, 36}};
	for(int i = 0; i < 3; ++i) {
		pixel[i] = (pal[0][i] * (1.0- x) + pal[1][i] * x ) * (1.0 - x)  + x * (pal[2][i] * (1-x) + pal[3][i] * x);
	}
}

static inline void color_red(double x, unsigned char* pixel) {
	unsigned char pal[][3] = {{95, 5, 0}, {255, 255, 255}, {252, 255, 23}, {255, 255, 255}};
	for(int i = 0; i < 3; ++i) {
		pixel[i] = (pal[0][i] * (1.0- x) + pal[1][i] * x ) * (1.0 - x)  + x * (pal[2][i] * (1-x) + pal[3][i] * x);
	}
}

static c_keys c_map[] = {
	{"Baroque", color_yellow},
	{"Grayscale", color_grayscale},
	{"Green&Yellow", color_green},
	{"Red&White", color_red},
	{"Blue&Black", color_blue}
};

#define NUM_COLORS (sizeof(c_map)/sizeof(c_keys))

Renderer* package_renderers(Plane* plane, int* count) {
	Renderer* rs = new Renderer[NUM_RENDERERS];
	for(unsigned int i = 0; i < NUM_RENDERERS; ++i) {
		rs[i].set_plane(plane);
		rs[i].set_id(r_map[i].id);
		rs[i].set_function(r_map[i].function);
	}

	*count = NUM_RENDERERS;
	return rs;
}

c_keys* package_colors(int* count) {
	*count = NUM_COLORS;
	return c_map;
}
