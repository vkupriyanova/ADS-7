// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include "train.h"
using namespace std;
using namespace std::chrono;
void runExperiment (const string & filename, int MaxN, const & mode){
  ofstream fout (filename);
  mt19937 rng (42);
  uniform_int_distribution <int> dist (0,1);
  for (int n = 2; n <= MaxN; n += 10) {
    Train trainn;
    for (int i = 0; i < n; ++i) {
      if (mode == "off"){
        train.addCar(false);
      } else if (mode = "on") {
        train.addCar(true);
      } else {
        train.addCar(dist(rng));
      }
    }
    auto start = high_resolution_clock::now();
    int lengthh = train.getLength();
    auto end = high_resolution_clock::now();
    long long time_us = duration_cast<microseconds>(end - start).count();
    fout << n << " " << train.getOpCount() << " " << time_us << endl;
  }
  fout.close();
}

int main() {
  Train train;
  int count = 60; // кол-во вагонов
  while (count--)
    train.addCar(false);
  std::cout << train.getLength() << std::endl;
  std::cout << train.getOpCount() << std::endl;
  runExperiment("result/data-off.txt", 1000, "off");
  runExperiment("result/data-on.txt", 1000, "on");
  runExperiment("result/data-random.txt", 1000, "random");

  return 0;
}
