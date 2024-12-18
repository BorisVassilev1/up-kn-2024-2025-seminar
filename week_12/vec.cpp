#include <iostream>

//struct vec3 {
//	union {
//		struct {
//			float x, y, z;
//		};
//		float data[3];
//	};
//};


template<int N>
struct vec {
	union {
		float data[N];
		struct {
			float x, y, z, w;
		};
	};
};

using vec2 = vec<2>;
using vec3 = vec<3>;
using vec4 = vec<4>;

template<int N>
void print(const vec<N>& v) {
	std::cout << '(';
	for (int i = 0; i < N; ++i) {
		std::cout << v.data[i] << (i == N - 1 ? "" : " ");
	}
	std::cout << ')';
}

int main() {

	vec3 a = { 1, 2, 3 };
	vec3 b = { 4, 5, 6 };

	print(a);
	std::cout << std::endl;
	print(b);
	std::cout << std::endl;

	vec<2> c = { 1, 2 };
	print(c);

}
