#pragma once
// THIS FILE IS USED PURELY FOR DEMONSTRATION PURPOSES
// IT IS NOT PART OF THE COUSE MATERIAL
// DO NOT ASK ME HOW IT WORKS

#include <chrono>

#define BENCH(x, n, unit)                                        \
	{                                                            \
		auto t1 = std::chrono::high_resolution_clock::now();     \
		for (int i = 0; i < n; ++i)                              \
			x;                                                   \
		auto t2	  = std::chrono::high_resolution_clock::now();   \
		auto diff = t2 - t1;                                     \
		std::cout << std::chrono::duration_cast<unit>(diff / n); \
	}

