// Copyright 2021 ETH Zurich and University of Bologna.
// Solderpad Hardware License, Version 0.51, see LICENSE for details.
// SPDX-License-Identifier: SHL-0.51
//
// Author: Matteo Perotti <mperotti@iis.ee.ethz.ch>
//         Basile Bougenot <bbougenot@student.ethz.ch>

#include "vector_macros.h"
#include "float_macros.h"

// Simple random test with similar values (vector-scalar)
void TEST_CASE1(void) {
  VSET(16, e16, m1);
  //              -0.0273, -0.8511,  0.7173,  0.9551, -0.7842, -0.6509, -0.5771,  0.6060, -0.5361,  0.6099,  0.2859,  0.6318, -0.9521,  0.3818,  0.2783, -0.7905
  VLOAD_16(v2,     0xa700,  0xbacf,  0x39bd,  0x3ba4,  0xba46,  0xb935,  0xb89e,  0x38d9,  0xb84a,  0x38e1,  0x3493,  0x390e,  0xbb9e,  0x361c,  0x3474,  0xba53);
  double dscalar_16;
  //                              0.3062
  BOX_HALF_IN_DOUBLE(dscalar_16,  0x34e6);
  asm volatile("vfrsub.vf v1, v2, %[A]" :: [A] "f" (dscalar_16));
  //               0.3335,  1.1572, -0.4111, -0.6489,  1.0898,  0.9570,  0.8833, -0.2998,  0.8423, -0.3037,  0.0203, -0.3257,  1.2578, -0.0757,  0.0278,  1.0967
  VCMP_U16(1, v1,  0x3556,  0x3ca1,  0xb694,  0xb931,  0x3c5c,  0x3ba8,  0x3b11,  0xb4cc,  0x3abd,  0xb4dc,  0x2530,  0xb536,  0x3d08,  0xacd8,  0x2720,  0x3c63);

  VSET(16, e32, m1);
  //               0.61218858,  0.50298065,  0.82400811, -0.50508654, -0.08447543, -0.66344708, -0.94741052,  0.85856712, -0.16725175, -0.36700448, -0.86911696,  0.82600677, -0.95377433,  0.06016647,  0.67027277,  0.08167093
  VLOAD_32(v2,     0x3f1cb864,  0x3f00c357,  0x3f52f232,  0xbf014d5a,  0xbdad0174,  0xbf29d7ab,  0xbf72897f,  0x3f5bcb0e,  0xbe2b440b,  0xbebbe803,  0xbf5e7e73,  0x3f53752e,  0xbf742a8e,  0x3d76711d,  0x3f2b96ff,  0x3da74316);
  double dscalar_32;
  //                              -0.78482366
  BOX_FLOAT_IN_DOUBLE(dscalar_32,  0xbf48ea34);
  asm volatile("vfrsub.vf v1, v2, %[A]" :: [A] "f" (dscalar_32));
  //              -1.39701223, -1.28780437, -1.60883176, -0.27973711, -0.70034826, -0.12137657,  0.16258687, -1.64339077, -0.61757189, -0.41781917,  0.08429331, -1.61083043,  0.16895068, -0.84499013, -1.45509648, -0.86649460
  VCMP_U32(2, v1,  0xbfb2d14c,  0xbfa4d6c6,  0xbfcdee33,  0xbe8f39b4,  0xbf334a06,  0xbdf89448,  0x3e267d2c,  0xbfd25aa1,  0xbf1e1931,  0xbed5ec65,  0x3daca1f8,  0xbfce2fb1,  0x3e2d0168,  0xbf585146,  0xbfba409a,  0xbf5dd297);

  VSET(16, e64, m1);
  //               -0.0920900511004143,  0.2386858516984947,  0.7068975504949517,  0.5997172971219242,  0.7714780386644180, -0.1053493184316212,  0.8711121216121871, -0.7388672665065719,  0.0889924652556937,  0.3266446452514173, -0.5909707717470494, -0.2733520923877579,  0.2365505631181986,  0.9616545156279142, -0.9315790291358075, -0.8056559777055108
  VLOAD_64(v2,      0xbfb79336adc36440,  0x3fce8d420b880e70,  0x3fe69ee79c9ff24a,  0x3fe330e2543f7e66,  0x3fe8aff2b634ab34,  0xbfbaf82c4551d810,  0x3febe026872f2710,  0xbfe7a4ccf737616c,  0x3fb6c835cfdd1640,  0x3fd4e7bef1312ccc,  0xbfe2e93b89317464,  0xbfd17e99c6464f50,  0x3fce4749f238b5c0,  0x3feec5dfb0d5860a,  0xbfedcf7ed2f8e31e,  0xbfe9c7ef0b824e6e);
  double dscalar_64;
  //                               -0.4500891854782252
  BOX_DOUBLE_IN_DOUBLE(dscalar_64,  0xbfdcce42defa6264);
  asm volatile("vfrsub.vf v1, v2, %[A]" :: [A] "f" (dscalar_64));
  //              -0.3579991343778108, -0.6887750371767198, -1.1569867359731769, -1.0498064826001494, -1.2215672241426432, -0.3447398670466040, -1.3212013070904123,  0.2887780810283467, -0.5390816507339189, -0.7767338307296425,  0.1408815862688242, -0.1767370930904673, -0.6866397485964237, -1.4117437011061393,  0.4814898436575823,  0.3555667922272856
  VCMP_U64(3, v1,  0xbfd6e97533898954,  0xbfe60a71f25f34ce,  0xbff28304860e91be,  0xbff0cc01e1de57cc,  0xbff38b8a12d8ee33,  0xbfd61037cda5ec60,  0xbff523a3fb562c21,  0x3fd27b570f746074,  0xbfe140282978d3fa,  0xbfe8db00e815c798,  0x3fc2086866d10cc8,  0xbfc69f5231682628,  0xbfe5f8f3ec0b5ea2,  0xbff6968090295b9e,  0x3fded0bac6f763d8,  0x3fd6c19b380a3a78);
};

// Simple random test with similar values (vector-scalar) (masked)
void TEST_CASE2(void) {
  VSET(16, e16, m1);
  //               -0.0273, -0.8511,  0.7173,  0.9551, -0.7842, -0.6509, -0.5771,  0.6060, -0.5361,  0.6099,  0.2859,  0.6318, -0.9521,  0.3818,  0.2783, -0.7905
  VLOAD_16(v2,      0xa700,  0xbacf,  0x39bd,  0x3ba4,  0xba46,  0xb935,  0xb89e,  0x38d9,  0xb84a,  0x38e1,  0x3493,  0x390e,  0xbb9e,  0x361c,  0x3474,  0xba53);
  double dscalar_16;
  //                              0.3062
  BOX_HALF_IN_DOUBLE(dscalar_16,  0x34e6);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfrsub.vf v1, v2, %[A], v0.t" :: [A] "f" (dscalar_16));
  //                0.0000,  1.1572,  0.0000, -0.6489,  0.0000,  0.9570,  0.0000, -0.2998,  0.0000, -0.3037,  0.0000, -0.3257,  0.0000, -0.0757,  0.0000,  1.0967
  VCMP_U16(4, v1,  0x0,  0x3ca1,  0x0,  0xb931,  0x0,  0x3ba8,  0x0,  0xb4cc,  0x0,  0xb4dc,  0x0,  0xb536,  0x0,  0xacd8,  0x0,  0x3c63);

  VSET(16, e32, m1);
  //                0.61218858,  0.50298065,  0.82400811, -0.50508654, -0.08447543, -0.66344708, -0.94741052,  0.85856712, -0.16725175, -0.36700448, -0.86911696,  0.82600677, -0.95377433,  0.06016647,  0.67027277,  0.08167093
  VLOAD_32(v2,      0x3f1cb864,  0x3f00c357,  0x3f52f232,  0xbf014d5a,  0xbdad0174,  0xbf29d7ab,  0xbf72897f,  0x3f5bcb0e,  0xbe2b440b,  0xbebbe803,  0xbf5e7e73,  0x3f53752e,  0xbf742a8e,  0x3d76711d,  0x3f2b96ff,  0x3da74316);
  double dscalar_32;
  //                              -0.78482366
  BOX_FLOAT_IN_DOUBLE(dscalar_32,  0xbf48ea34);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfrsub.vf v1, v2, %[A], v0.t" :: [A] "f" (dscalar_32));
  //                0.00000000, -1.28780437,  0.00000000, -0.27973711,  0.00000000, -0.12137657,  0.00000000, -1.64339077,  0.00000000, -0.41781917,  0.00000000, -1.61083043,  0.00000000, -0.84499013,  0.00000000, -0.86649460
  VCMP_U32(5, v1,  0x0,  0xbfa4d6c6,  0x0,  0xbe8f39b4,  0x0,  0xbdf89448,  0x0,  0xbfd25aa1,  0x0,  0xbed5ec65,  0x0,  0xbfce2fb1,  0x0,  0xbf585146,  0x0,  0xbf5dd297);

  VSET(16, e64, m1);
  //                -0.0920900511004143,  0.2386858516984947,  0.7068975504949517,  0.5997172971219242,  0.7714780386644180, -0.1053493184316212,  0.8711121216121871, -0.7388672665065719,  0.0889924652556937,  0.3266446452514173, -0.5909707717470494, -0.2733520923877579,  0.2365505631181986,  0.9616545156279142, -0.9315790291358075, -0.8056559777055108
  VLOAD_64(v2,       0xbfb79336adc36440,  0x3fce8d420b880e70,  0x3fe69ee79c9ff24a,  0x3fe330e2543f7e66,  0x3fe8aff2b634ab34,  0xbfbaf82c4551d810,  0x3febe026872f2710,  0xbfe7a4ccf737616c,  0x3fb6c835cfdd1640,  0x3fd4e7bef1312ccc,  0xbfe2e93b89317464,  0xbfd17e99c6464f50,  0x3fce4749f238b5c0,  0x3feec5dfb0d5860a,  0xbfedcf7ed2f8e31e,  0xbfe9c7ef0b824e6e);
  double dscalar_64;
  //                               -0.4500891854782252
  BOX_DOUBLE_IN_DOUBLE(dscalar_64,  0xbfdcce42defa6264);
  VLOAD_8(v0, 0xAA, 0xAA);
  VCLEAR(v1);
  asm volatile("vfrsub.vf v1, v2, %[A], v0.t" :: [A] "f" (dscalar_64));
  //                0.0000000000000000, -0.6887750371767198,  0.0000000000000000, -1.0498064826001494,  0.0000000000000000, -0.3447398670466040,  0.0000000000000000,  0.2887780810283467,  0.0000000000000000, -0.7767338307296425,  0.0000000000000000, -0.1767370930904673,  0.0000000000000000, -1.4117437011061393,  0.0000000000000000,  0.3555667922272856
  VCMP_U64(6, v1,  0x0,  0xbfe60a71f25f34ce,  0x0,  0xbff0cc01e1de57cc,  0x0,  0xbfd61037cda5ec60,  0x0,  0x3fd27b570f746074,  0x0,  0xbfe8db00e815c798,  0x0,  0xbfc69f5231682628,  0x0,  0xbff6968090295b9e,  0x0,  0x3fd6c19b380a3a78);
};

int main(void) {
  enable_vec();
  enable_fp();

  TEST_CASE1();
  TEST_CASE2();

  EXIT_CHECK();
}
