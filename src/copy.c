/*
 * RICM3 - Méthodes Numériques - 2018
 * ANCRENAZ Ariane - SAUTON Tanguy
 * C Implementation of BLAS routines
 */

#include "mnblas.h"

/*
 * cblas_?copy
 * Copies vector to another vector
 * Y := X
 * 
 * Types : s / d / c / z 
 */

void mncblas_scopy(const int N, const float *X, const int incX,
                   float *Y, const int incY)
{
    register unsigned int i = 0;
    register unsigned int j = 0;

    for (; ((i < N) && (j < N)); i += incX * 4, j += incY * 4)
    {
        Y[j] = X[i];
        Y[j + incY] = X[i + incX];
        Y[j + 2 * incY] = X[i + 2 * incX];
        Y[j + 3 * incY] = X[i + 3 * incX];
    }
}

void mncblas_dcopy(const int N, const double *X, const int incX,
                   double *Y, const int incY)
{
    register unsigned int i = 0;
    register unsigned int j = 0;

    for (; ((i < N) && (j < N)); i += incX * 4, j += incY * 4)
    {
        Y[j] = X[i];
        Y[j + incY] = X[i + incX];
        Y[j + 2 * incY] = X[i + 2 * incX];
        Y[j + 3 * incY] = X[i + 3 * incX];
    }

    return;
}

void mncblas_ccopy(const int N, const void *X, const int incX,
                   void *Y, const int incY)
{
    cplx_t *array_x = (cplx_t *)X;
    cplx_t *array_y = (cplx_t *)Y;

    register unsigned int i = 0;
    register unsigned int j = 0;
    for (; ((i < N) && (j < N)); i += incX * 4, j += incY * 4)
    {
        array_y[j].re = array_x[i].re;
        array_y[j].im = array_x[i].im;
        array_y[j + incY].re = array_x[i + incX].re;
        array_y[j + incY].im = array_x[i + incX].im;
        array_y[j + 2 * incY].re = array_x[i + 2 * incX].re;
        array_y[j + 2 * incY].im = array_x[i + 2 * incX].im;
        array_y[j + 3 * incY].re = array_x[i + 3 * incX].re;
        array_y[j + 3 * incY].im = array_x[i + 3 * incX].im;
    }

    return;
}

void mncblas_zcopy(const int N, const void *X, const int incX,
                   void *Y, const int incY)
{
    cplxd_t *array_x = (cplxd_t *)X;
    cplxd_t *array_y = (cplxd_t *)Y;

    register unsigned int i = 0;
    register unsigned int j = 0;
    for (; ((i < N) && (j < N)); i += incX * 4, j += incY * 4)
    {
        array_y[j].re = array_x[i].re;
        array_y[j].im = array_x[i].im;
        array_y[j + incY].re = array_x[i + 1 * incX].re;
        array_y[j + incY].im = array_x[i + 1 * incX].im;
        array_y[j + 2 * incY].re = array_x[i + 2 * incX].re;
        array_y[j + 2 * incY].im = array_x[i + 2 * incX].im;
        array_y[j + 3 * incY].re = array_x[i + 3 * incX].re;
        array_y[j + 3 * incY].im = array_x[i + 3 * incX].im;
    }

    return;
}
