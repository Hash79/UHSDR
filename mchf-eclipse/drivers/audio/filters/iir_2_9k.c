/*  -*-  mode: c; tab-width: 4; indent-tabs-mode: t; c-basic-offset: 4; coding: utf-8  -*-  */
/************************************************************************************
**                                                                                 **
**                               mcHF QRP Transceiver                              **
**                             K Atanassov - M0NKA 2014                            **
**                                                                                 **
**---------------------------------------------------------------------------------**
**                                                                                 **
**  File name:                                                                     **
**  Description:                                                                   **
**  Last Modified:                                                                 **
**  Licence:		CC BY-NC-SA 3.0                                                **
************************************************************************************/

#include "filters.h"

// alternative filter designed with MATLAB fdatools by DD4WH 2016-02-03
// 12k sampling rate, Lattice ARMA structure
// 10th order IIR Elliptic lowpass
// Fpass 2900Hz
// Astop 60dB
// coefficients in reverse order than that spit out by MATLAB

#define IIR_2k9_numStages 10

const arm_iir_lattice_instance_f32 IIR_2k9_LPF =
{
    .numStages = IIR_2k9_numStages,
    .pkCoeffs  = (float*) (const float[])
    {

        0.251607461238023,
        -0.482252659454225,
        0.649010601492657,
        -0.587098281132217,
        0.884933496818835,
        -0.297598183921305,
        0.990030999070584,
        -0.113255360948473,
        0.999450459548208,
        -0.0609467228813790
    },

    .pvCoeffs = (float*) (const float[])
    {

        0.0200465239002972,
        0.0961515965852007,
        0.222315717811456,
        0.266325692682369,
        0.137175400914474,
        -0.0104425480557769,
        -0.0563674296455557,
        -0.00456438174446905,
        0.00418951198974554,
        0.000124467441153527,
        5.62783747425286e-05
    }
};

const arm_iir_lattice_instance_f32 IIR_2k9_BPF =
{
    .numStages = IIR_2k9_numStages,
    .pkCoeffs  = (float*) (const float[])
    {
        0.263419613809752,
        -0.487748680969863,
        0.579151989014181,
        -0.766691138931688,
        0.644526948603595,
        -0.455099813849530,
        0.966822380971438,
        -0.994647491908158,
        0.999641053036454,
        -0.996851003050428
    },

    .pvCoeffs = (float*) (const float[])
    {
        -0.0324231770435912,
        -0.140665197185480,
        -0.244988773730778,
        -0.127152356090031,
        0.127397853986530,
        0.136542957067850,
        0.00600155113876917,
        0.00834595632603165,
        -0.000738848558080582,
        -2.00888540803704e-05,
        6.96894635783540e-07
    }
};


