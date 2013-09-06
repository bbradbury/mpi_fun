#include <iostream>
#include <map>
#include <string>
#include "mpi_fun/pi/pi_calc.h"

//There should be a sweet FWD_DECL macro that generates this stuff inside the namespace of pi_calc.h
using mpi_fun::pi::PiCalc;
typedef mpi_fun::pi::PiCalc* PiCalcPtr; //Usually I'd go shared ptr here
typedef std::map<std::string, PiCalcPtr> PiCalcMap;


int main(int argc, char *argv[])
{

  PiCalcMap mp;

  mp.insert(PiCalcMap::value_type(std::string("hello"), new PiCalc));
  mp.insert(PiCalcMap::value_type(std::string("WUT"), new PiCalc(201)));

  for(PiCalcMap::iterator it = mp.begin(); it != mp.end(); ++it)
  {
    std::cout << it->first << ": " << it->second->get_iterations() << std::endl;
  }


}
