#include <iostream>
#include "Simulation.h"

using namespace std;

int main (int argc, char** argv)
{
  Simulation s(argv[1]);
  s.Simulate();
  return 0;
}
