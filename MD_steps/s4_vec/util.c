#include <math.h>

// void visc_force(int N, double *f, double *vis, double *velo) {
//   int i;
//   for (i = 0; i < N; i++) {
//     f[i] = -vis[i] * velo[i];
//   }
// }
// void wind_force(int N, double *f, double *vis, double velo) {
//   int i;
//   for (i = 0; i < N; i++) {
//     f[i] = f[i] - vis[i] * velo;
//   }
// }
void add_norm(int N, double *r, double *delta) {
  int k;
  for (k = 0; k < N; k++) {
    r[k] += (delta[k] * delta[k]);
  }
}

double force(double W, double delta, double r) {
  return W * delta / (pow(r, 3.0));
}

void new_force(int N, double *f, double *vis, double *velo, double wind) {
  int i;
#pragma ivdep
#pragma vector aligned
  for (i = 0; i < N; i++) {
    f[i] = -vis[i] * velo[i] - vis[i] * wind;
  }
}