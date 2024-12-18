#include <unistd.h>
#include <iostream>

struct Student {
	char   name[111];
	char   fn[11];
	double grades[5];
};

void readStudent(Student &s) {
	std::cin >> s.name >> s.fn;
	for (int i = 0; i < 5; ++i) {
		std::cin >> s.grades[i];
	}
}

void printStudent(const Student &s) {
	std::cout << "Student { name: " << s.name << ", fn: " << s.fn << ", grades: [";
	for (int i = 0; i < 5; ++i) {
		std::cout << s.grades[i] << ", ";
	}
	std::cout << "]}" << std::endl;
}

double averageGrade(const Student &s) {
	return (s.grades[0] + s.grades[1] + s.grades[2] + s.grades[3] + s.grades[4]) / 5.0;
}

bool hasHonors(const Student &s) { return averageGrade(s) > 5.50; }

float compareStudents(const Student &left, const Student &right) { return averageGrade(left) - averageGrade(right); }

void sortStudents(Student students[], int n) {
	for (int j = 0; j < n; ++j) {
		for (int i = 0; i < n - 1 - j; ++i) {
			if (compareStudents(students[i], students[i + 1]) > 0) { std::swap(students[i], students[i + 1]); }
		}
	}
}

/*
Gosho
7MI0800921
2 5 6 6 5


*/
int main() {

	std::cout << sizeof(Student) << std::endl;

	Student gosho{"gosho", "123213", {1,2,3,4,5}};
	readStudent(gosho);
	printStudent(gosho);

	std::cout << averageGrade(gosho) << std::endl;

	Student students[] {
		{"Petia", "123", {6,6,6,6,6}},
		{"Rumen", "122", {7,6,6,6,6}},
		{"Traicho", "121", {5,6,5,6,6}}
	};

	sortStudents(students, 3);

	for(int i = 0; i < 3; ++i) 
		printStudent(students[i]);

	return 0;
}
