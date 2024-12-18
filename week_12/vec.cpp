#include <iostream>

struct vec3{
	union {
		struct {
			float x, y, z;
		};
		float data[3];
	};
};

int main() {
	
	vec3 v;
	v.x = 3;
	v.y = 5;
	v.z = 6;

	std::cout << v.data[0] << " " << v.data[1] << " " << v.data[2] << std::endl;

	std::cout << sizeof(vec3) << std::endl;
};
