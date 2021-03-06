#ifndef _RAY_H_
#define _RAY_H_

#include "vec3.hpp"

class ray
{
private:
	vec3 A;
	vec3 B;
public:
	ray() {}
	
	ray(const vec3& a, const vec3&b)
	{ A = a; B = b; }

	vec3 origin() const
	{ return A; }
	
	vec3 direction() const
	{ return B; }
	
	/*vec3 point_at_parameter(float t) 
	{ return A + t*B; }*/

	vec3 point_at_parameter(float t) const
	{ vec3 v1 = A; vec3 v2 = B;
		return v1 + t*v2; }
};

#endif