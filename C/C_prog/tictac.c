#include <stdio.h>

int main()
{
  int x;
  int y;
  int z;
  int i1 = 2;
  int i2 = 3;
  int i3 = 4;
  
  int array[i1][i2][i3]; /* Declares an array like a chessboard */
  
  for ( x = 0; x < i1; x++ ) {
    for ( y = 0; y < i2; y++ ){
		for ( z = 0; z < i3; z++ )
		array[x][y][z] = x * y * z; /* Set each element to a value */
	}	
  }
  printf( "Array Indices:\n" );
  for ( x = 0; x < i1;x++ ) {
    for ( y = 0; y < i2; y++ ){
		for ( z = 0; z < i3; z++ ){
        printf( "[%d][%d][%d]=%d", x, y, z, array[x][y][z] );
		}
		printf( "\n" );
    }
    printf( "\n" );
  }
  getchar();
}