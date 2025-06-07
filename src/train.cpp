// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}
Train::~Train() {
  if (!first) return;
  Car* currentt = first -> next;
  while (currentt != first) {
    Car* NextCat = currentt -> next;
    delete currentt;
    currentt = NextCar;
  }
  delete first;
  first = nullptr;
}
void Train::addCar(bool lightON) {
  Car* NewCar = new Car {lightON, nullptr, nullptr};
  if (!first) {
    first = NewCar;
    first -> next = first;
    first -> prev = first;
  } else {
    Car* last = first -> prev;
    last -> next = NewCar;
    NewCar -> prev = last;
    NewCar -> next = first;
    first -> prev = NewCar;
  }
}
int Train::getLength() {
  if (!first) return 0;
  countOp = 0;
  Car* presentCar = first;
  if (presentCar -> light) {
    presentCar -> light = true;
  }
}
  int length = 0;
  while (true) {
    int countStep = 0;
    while (true) {
      presentCar = presentCar -> next;
      countStep++;
      countOp++;
      if (presentCar -> light || presentCar == first) break;
    }
    if (presentCar == first && !presentCar -> light) break;
    if (presentCar -> light) {
      presentCar -> light = false;
    }
    for (int i = 0; i < countStep; i++) {
      presentCar = presentCar -> prev;
      countOp++;
    }
    if (!presentCar -> light) {
      length = countStep;
      break;
    }
}
return length;
int Train::getOpCount() {
  return countOp;
}

