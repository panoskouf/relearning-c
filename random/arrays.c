#include <stdio.h>
#include <stdlib.h>

int main()
{
  int matrix[3][3] = {
      {1, 0, 0},
      {0, 1, 0},
      {0, 0, 1}};

  printf("matrix[2][2] --> %d\n", matrix[2][2]);

  int array2d_1[4][3];
  printf("array2d_1 [2][2] --> %d (contains trash)\n)", array2d_1[2][2]);

  // = {} -> all initialised with 0 zeroes
  int array2d[4][3] = {};
  printf("array2d [2][2] --> %d\n", array2d[2][2]);

  // we can also initialise specific indexes, all others will be initialised to 0
  int arr2d[4][3] = {[0][0] = 1, [1][1] = 5, [2][2] = 9};
  printf("arr2d [2][2] --> %d\n", arr2d[2][2]);
  printf("arr2d [3][2] --> %d\n", arr2d[3][2]);

  // example of 3 dimensional array
  int arr3d[2][3][4] = {
      {
          // 1st 3line block of 4 elements
          {10, 20, 30, 40},
          {15, 25, 35, 45},
          {47, 48, 49, 50}
          // -
      },
      {
          // 2nd 3line block of 4 elements
          {10, 20, 30, 40},
          {15, 25, 35, 45},
          {47, 48, 49, 50}
          // -
      }
      // -
  };

  int n = 5;
  int m = 8;
  // valid initializations of an array
  float a1[5];
  float a2[5 * 2 + 1];
  float a3[sizeof(int) + 1];
  // float a4[-4]; // no size must be > 0
  // float a5[0]; // no size must be > 0
  // float a6[2.5]; // no size must be an integer
  float a7[(int)2.5];
  float a8[n]; // VLA
  float a9[m]; // VLA

  return 0;
}