#include "renderer.h"
#include "ray.h"
#include "objects.h"
#include <iostream>

void Renderer::run() {
  int nx = buffer->width();
  int ny = buffer->height();
	Point3 lower_left_corner(-1.0, -1.0, -1.0);
	//Vec3 horizontal(3.0, 0.0, 0.0);
	//Vec3 vertical(0.0, 2.0, 0.0);
	//Point3 origin(0.0, 0.0, 0.0);
	for ( int j = ny-1; j >= 0; --j ) {
		for ( int i = 0; i < nx; ++i ) {
			float v = float(i) / float(nx), u = float(j) / float(ny);

			//Ray r(origin, lower_left_corner + u*horizontal + v*vertical);
      Ray r = camera->generate_ray(i, j);
      /*cout << "pixel (" << j << ", " << i << ") " << "ray: [o=("
        << r.origin()[0] << ", " << r.origin()[1] << ", " << r.origin()[2] 
        << "), d=(" << r.direction()[0] << ", " << r.direction()[1] << ", "
        << r.direction()[2] << ")\n";*/
			Vec3 col = color(r);
      if (col == Color(-1,-1,-1)){
        col = bg->sample(u, v);
      }
      else {
        int ir = int(255.99*col[0]), ig = int(255.99*col[1]);
        int ib = int(255.99*col[2]);
        col = Color(ir,ig,ib);
      }
      buffer->paint( i, j, col );
      //buffer->paint(i, j, bg->sample(u, v));

      //render.buffer->paint(i, j, col);
		}
	}
}

