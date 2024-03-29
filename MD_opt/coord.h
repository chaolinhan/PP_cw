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
#define Nbody 4 * 1024
#define OFFSET 8
#define Npair ((Nbody * (Nbody - 1)) / 2)

enum { Xcoord = 0, Ycoord, Zcoord, Ndim };

// DEF double *pos[Ndim], *velo[Ndim];
// DEF double *f[Ndim], *vis, *mass, *radius;
// DEF double *delta_pos[3];
// DEF double *r;
// DEF double *delta_r;
double mass[Nbody + OFFSET];
double radius[Nbody + OFFSET];
double vis[Nbody + OFFSET];
double f[Ndim][Nbody + OFFSET];
double pos[Ndim][Nbody + OFFSET];
double velo[Ndim][Nbody + OFFSET];
// DEF double *delta_pos[3];
double delta_pos[Ndim][Npair + OFFSET];
double r[Nbody + OFFSET];        //  double *r;
double delta_r[Npair + OFFSET];  //  double *delta_r;
double wind[Ndim];
int collisions;
double wind[Ndim];

#define G 2.0
#define M_central 1000.0

void evolve(int Nstep, double dt);
