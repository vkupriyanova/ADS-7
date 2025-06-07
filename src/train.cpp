// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train() : countOp(0), first(nullptr) {}
void Train::addCar(bool light) {
  Car* TheCar = new Car {light, nullptr, nullptr};
  if (!first){
    first = TheCar;
    first -> next = first;
    first -> prev = first;
  } else {
    Car* past = first -> prev;
    past -> next = TheCar;
    TheCar -> prev = past;
    TheCar -> next = first;
    first -> prev = TheCar;
  }
}
int Train::getLength() {
  Car* currentt = first;
  countOp = 0;
  currentt -> light = true;
  int countStep = 0;
  currentt = currentt -> next;
  ++countOp;
  ++countStep;
  while (!currentt -> light) {
    currentt = currentt -> next;
    ++countOp;
    ++countStep;
  }
  return countStep;
}
int Train::getOpCount() {
  return countOp;
}

