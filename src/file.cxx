// beetroot
#include "beetroot/FileHandler.h"
#include "beetroot/Histogram1D.h"
#include "beetroot/Figure.h"
#include "beetroot/Plot.h"
#include <iostream>

int main(int /*argc*/, char** /*argv*/) {
  using namespace beetroot;

  FileHandler pythia( "pythia.root", FileHandler::READ );
  pythia.ls();
  FileHandler herwig( "pythia.root", FileHandler::READ );

  Histogram1D pythia_gf( pythia.read("Truth.GapFraction.dYBins") );
  std::cout << "Found histogram at " << &pythia_gf << " with name " << pythia_gf.name() << std::endl;
  pythia_gf.printAll();
 
  Histogram1D herwig_gf( herwig.read("Reco.GapFraction.dYBins") );
 
  Figure figure1("beetroot-example");
  //figure1.add_subplot(0.1,0.5,0.5,0.7);

  // figure1.add_subplot(0.1,0.9,0.05,0.3);
  // figure1.draw("x");
  // figure1.add_subplot(0.1,0.9,0.3,0.9);
  // figure1.draw("x^3");

  Plot *ratioPlot = figure1.add_subplot(0.1,0.9,0.05,0.3);
  //std::cout << "Received reference at " << &ratioPlot << std::endl;
  //ratioPlot.print();
  //std::cout << "Subplot is at " << &figure1.m_subplots.back() << " : " << &( figure1.m_subplots[figure1.m_subplots.size()-1] )<< std::endl;

  Plot *mainPlot = figure1.add_subplot(0.1,0.9,0.3,0.9);
  // std::cout << "Received reference at " << &mainPlot << std::endl;
  // std::cout << "Subplot is at " << &figure1.m_subplots.back() << std::endl;

  //mainPlot->add_function("x^3");
  mainPlot->add_data( pythia_gf );
  mainPlot->add_data( herwig_gf );
  ratioPlot->add_function("x");

  mainPlot->get_axis(Axis::X).set_range(0.0,8.0);
  ratioPlot->get_axis(Axis::X).set_range(0.0,8.0);

  mainPlot->get_axis(Axis::Y).set_range(0.0,1.0);
  ratioPlot->get_axis(Axis::Y).set_range(0.0,1.0);

  ratioPlot->get_axis(Axis::X).set_label("x");
  
  //figure1.draw();
  figure1.save();

  return 0;
}
