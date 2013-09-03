/*
 * =====================================================================================
 *        Class:  PiCalc
 *  Description: Provides an implementation of the following algorithm:
 *
 *  Inscribe a circle in a square
 *  Randomly generate points in the square
 *  Determine the number of points in the square that are also in the circle
 *  Let r be the number of points in the circle divided by the number of points in the square
 *  PI ~ 4 r
 *  Note that the more points generated, the better the approximation
 *
 *  see: https://computing.llnl.gov/tutorials/parallel_comp/
 *
 * =====================================================================================
 */
namespace mpi_fun {
  namespace pi {
    class PiCalc
    {
      public:
        /* ====================  LIFECYCLE     ======================================= */
        PiCalc ();                             /* constructor      */
        PiCalc (int iterations);          /* constructor      */
        PiCalc ( const PiCalc &other );   /* copy constructor */
        ~PiCalc ();                            /* destructor       */

        /* ====================  ACCESSORS     ======================================= */

        void set_iterations ( int value );
        int get_iterations ( ) const;
        /* ====================  MUTATORS      ======================================= */
        double run();


        /* ====================  OPERATORS     ======================================= */

        PiCalc& operator = ( const PiCalc &other ); /* assignment operator */

      protected:
        int iterations;

        /* ====================  DATA MEMBERS  ======================================= */

      private:

        /* ====================  DATA MEMBERS  ======================================= */

    }; /* -----  end of class PiCalc  ----- */
  }
}
