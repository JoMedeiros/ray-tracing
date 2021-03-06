#include <iostream>
#include "background.hpp"
#include "ray.hpp"
#include "objects.hpp"
#include "scene.hpp"

int main() {
	int nx = 400;
	int ny = 400;
  Color color1(255,255,255);
  Color color2(100,150,255);
  Color color3(100,150,255);
  Color color4(100,150,255);
  Scene sc(ny, nx, color1, color2, color3, color4);
  sc.render();
	
	std::cout << "P3\n" 
	<< nx << " " << ny 
	<< "\n255\n";

	Point3 lower_left_corner(-1.0, -1.0, -1.0);
	vec3 horizontal(2.0, 0.0, 0.0);
	vec3 vertical(0.0, 2.0, 0.0);
	Point3 origin(0.0, 0.0, 0.0);
	
	for ( int j = ny-1; j >= 0; --j ) {
		for ( int i = 0; i < nx; ++i ) {
			float u = float(i) / float(nx), v = float(j) / float(ny);

			ray r(origin, lower_left_corner + u*horizontal + v*vertical);
			vec3 col = color(r);

			int ir = int(255.99*col[0]), ig = int(255.99*col[1]);
			int ib = int(255.99*col[2]);

			std::cout << ir << " " << ig << " " << ib << "\n";
		}
	}
	return EXIT_SUCCESS;
}
