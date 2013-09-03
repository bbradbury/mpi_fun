Currently only tested on OS X, with OpenMPI provided via homebrew.

compile
=======
`make cmake`
`make`

run
===
`mpirun -c 4 ./build/bin/mpi_fun`
where c is the number of processors you have


inspiration
===========
https://computing.llnl.gov/tutorials/parallel_comp/
http://en.wikipedia.org/wiki/Message_Passing_Interface

