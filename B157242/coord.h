/*
 * This file defines static arrays that contains the primary coordinates
 * of the particles,
 *
 *  Nbody	  Number of particles
 *  Npair	  Number of particle pairs
 *  pos		  Position of the particles
 *  r         distance of partice from central mass
 *  vel		  velocity of the particles
 *  f		  Forces acting on each particle
 *  vis       viscosity coefficient for each particle
 *  mass	  mass of each particle
 *  delta_pos separation vector for each particle pair
 *  delta_r	  separation for each particle pair
 */

#ifdef DECL
#define DEF
#else
#define DEF extern
#endif

#define Nbody 4096
#define OFFSET 64
#define Npair 8386560
#define G 2.0
#define M_central 1000.0
#define GM 2000.0

enum { Xcoord = 0, Ycoord, Zcoord, Ndim };

DEF double mass[Nbody + OFFSET] __attribute__((aligned(64)));
DEF double radius[Nbody + OFFSET] __attribute__((aligned(64)));
DEF double vis[Nbody + OFFSET] __attribute__((aligned(64)));
DEF double f[Nbody][Ndim] __attribute__((aligned(64)));
DEF double pos[Nbody][Ndim] __attribute__((aligned(64)));
DEF double velo[Nbody][Ndim] __attribute__((aligned(64)));
DEF int collisions;
DEF double wind[Ndim];
