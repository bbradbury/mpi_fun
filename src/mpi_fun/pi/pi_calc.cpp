#include "mpi_fun/pi/pi_calc.h"
#include <cstdlib>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <iostream>
#include <random>

using namespace mpi_fun::pi;
/*
 *--------------------------------------------------------------------------------------
 *       Class:  PiCalc
 *      Method:  PiCalc
 * Description:  constructor
 *--------------------------------------------------------------------------------------
 */
PiCalc::PiCalc ()
{
  this->iterations = 0;
}  /* -----  end of method PiCalc::PiCalc  (constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  PiCalc
 *      Method:  PiCalc
 * Description:  constructor
 *--------------------------------------------------------------------------------------
$ */
PiCalc::PiCalc (int iterations)
{
  this->iterations = iterations;
}  /* -----  end of method PiCalc::PiCalc  (constructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  PiCalc
 *      Method:  PiCalc
 * Description:  copy constructor
 *--------------------------------------------------------------------------------------
 */
PiCalc::PiCalc ( const PiCalc &other )
{
  this->iterations = other.iterations;
}  /* -----  end of method PiCalc::PiCalc  (copy constructor)  ----- */


/*
 *--------------------------------------------------------------------------------------
 *       Class:  PiCalc
 *      Method:  get_iterations
 *--------------------------------------------------------------------------------------
 */
 int
PiCalc::get_iterations (  ) const
{
  return iterations;
}		/* -----  end of method PiCalc::get_iterations  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  PiCalc
 *      Method:  set_iterations
 *--------------------------------------------------------------------------------------
 */
  void
PiCalc::set_iterations ( int value )
{
  iterations	= value;
  return ;
}		/* -----  end of method PiCalc::set_iterations  ----- */

  /*
   * Inspired by: https://computing.llnl.gov/tutorials/mpi/samples/C/mpi_pi_reduce.c
   *
   */
  double 
PiCalc::run ()
{

  //ugh:
#define sqr(x)  ((x)*(x))
  double x_coord, y_coord, pi, r; 
  int score, n;
  score = 0;
  unsigned seed;
  read(open("/dev/random", O_RDONLY), &seed, sizeof seed);
  std::mt19937 generator;
  generator.seed(seed);
  std::uniform_real_distribution<double> distribution(0,1);

  /*  "throw darts at board" */
  for (n = 1; n <= iterations; n++)  {
    /*  generate random numbers for x and y coordinates */
    r = distribution(generator);
    x_coord = (2.0 * r) - 1.0;
    r = distribution(generator);
    y_coord = (2.0 * r) - 1.0;

    /*  if dart lands in circle, increment score */
    if ((sqr(x_coord) + sqr(y_coord)) <= 1.0)
      score++;
  }

  /*  calculate pi */
  pi = 4.0 * (double)score/(double)iterations;
  return(pi); 
}		/* -----  end of method PiCalc::run  ----- */


/*
 *--------------------------------------------------------------------------------------
 *       Class:  PiCalc
 *      Method:  ~PiCalc
 * Description:  destructor
 *--------------------------------------------------------------------------------------
 */
PiCalc::~PiCalc ()
{
}  /* -----  end of method PiCalc::~PiCalc  (destructor)  ----- */

/*
 *--------------------------------------------------------------------------------------
 *       Class:  PiCalc
 *      Method:  operator =
 * Description:  assignment operator
 *--------------------------------------------------------------------------------------
 */
  PiCalc&
PiCalc::operator = ( const PiCalc &other )
{
  if ( this != &other ) {
  }
  return *this;
}  /* -----  end of method PiCalc::operator =  (assignment operator)  ----- */

