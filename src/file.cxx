// beetroot
#include "beetroot/FileHandler.h"
#include "beetroot/Histogram1D.h"
#include <iostream>

int main(int argc, char **argv) {
  using namespace beetroot;

  FileHandler file( "pythia.root", FileHandler::READ );
  file.ls();

  Histogram1D gfdy( file.read<TH1D>("Truth.GapFraction.dYBins") );
  std::cout << "Found histogram at " << &gfdy << " with name " << gfdy.name() << std::endl;
}
