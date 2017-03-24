#include "List.h"
#include "BinaryTree.h"
#include <iostream>
#include <algorithm>
#include <chrono>

#define Chrono std::chrono

typedef Chrono::high_resolution_clock Clock;

int main() {
	List l = List(new int[5]{ 1, 2, 3, 4, 5 }, 5);

	std::cout << "Testing simple list" << std::endl;
	for (int i = 0; i < l.Count(); i++) {
		std::cout << l.Get(i) << ", ";
	}
	std::cout << std::endl << "Testing recursion" << std::endl;
	std::cout << l.First();
	for (int i = 1; i < l.Count(); i++) {
		std::cout << ", " << l.Next();
	}
	std::cout << "Test insert" << std::endl;
	l.Insert(3, 72);
	l.Remove(1);
	l.PopTail();
	l.PopHead();
	for (int i = 0; i < l.Count(); i++) {
		std::cout << l.Get(i) << ", ";
	}
	std::cout << std::endl << l.First();
	std::cout << std::endl;

	std::cout << "Enter in the size of the array: " << std::endl;
	int size;
	std::cin >> size;
	std::cout << "Allocating..." << std::endl;
	int * arr;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = i;
	}
	std::cout << "Shuffling..." << std::endl;
	auto shuffleStart = Clock::now();
	std::random_shuffle(arr, arr + size);
	auto shuffleEnd = Clock::now();
	std::cout << Chrono::duration_cast<Chrono::nanoseconds>(shuffleEnd - shuffleStart).count()
		<< " nanoseconds" << std::endl;
	std::cout << "Sorting..." << std::endl;
	auto sortStart = Clock::now();
	BinaryTree * t = new BinaryTree(arr, size);
	auto sortEnd = Clock::now();
	std::cout << Chrono::duration_cast<Chrono::nanoseconds>(sortEnd - sortStart).count()
		<< " nanoseconds" << std::endl;
	/*std::cout << "Checking Sanity..." << std::endl;
	bool sane = true;
	for (int i = 0; i < size; i++) {
		if (!t->Find(i))
			sane = false;
	}
	if (!sane) {
		std::cout << "Uh oh, we're insane" << std::endl;
	}
	else {
		std::cout << "We're sane." << std::endl;
	}*/
	while (true) {
		std::cout << "Find an index: " << std::endl;
		int n;
		std::cin >> n;
		auto findStart = Clock::now();
		auto findEnd = Clock::now();
		if (t->🔎(n)) {
			findEnd = Clock::now();
			std::cout << "Found it!" << std::endl;
		}
		else {
			findEnd = Clock::now();
			std::cout << "Could not find it." << std::endl;
		}
		std::cout << Chrono::duration_cast<Chrono::nanoseconds>(findEnd - findStart).count()
			<< " nanoseconds" << std::endl;
	}
	system("pause");
}