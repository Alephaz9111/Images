#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 256
#define HEIGHT 256 
#define WIDTH 256 

FILE *in_fp;
FILE *out_fp;
unsigned char image[HEIGHT][WIDTH]; 
unsigned char image_sobel[HEIGHT][WIDTH]; 

/////////////// SOBEL FILTER /////////////////////////////////////////////////////////
void sobel(unsigned char img[HEIGHT][WIDTH], unsigned char img_sobel[HEIGHT][WIDTH]){ 

    char horizontal[9] = {-1, 0, 1, 
                          -2, 0, 2,
                          -1, 0, 1};
    char vertical[9] = {-1,-2,-1, 
                         0, 0, 0,
                         1, 2, 1};

    int i, j, k, l;
    double sum, sumH, sumV;

    for( k = 1; k < HEIGHT - 1; k++ ){ 
        for( l = 1; l < WIDTH - 1; l++ ){ 
            sumH = 0; 
            sumV = 0; 
            for( i = 0; i < 3; i++ ){
                for( j = 0; j < 3; j++ ){
                    sumH += horizontal[ i * 3 + j ] * img[ k - 1 + i ][ l - 1 + j ]; 
                    sumV += vertical[ i * 3 + j ] * img[ k - 1 + i ][ l - 1 + j ]; 
                }
            }
            sum = sqrt( pow( sumH, 2 ) + pow( sumV, 2 ) );
            if( sum < 0 ) sum = abs(sum); 
            else if( sum > 255 ) sum = 255; 
            img_sobel[k][l] = sum; 
        }
    }
}
/////////////// SOBEL FILTER /////////////////////////////////////////////////////////

int main(){
    char in_image_name[N];
    char out_image_name[N];

/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////
    printf("Input:");
    scanf("%s", in_image_name);
    printf("Output:");
    scanf("%s", out_image_name);

    in_fp = fopen(in_image_name, "rb");
    out_fp = fopen(out_image_name, "wb");
    
    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, in_fp);

    sobel(image, image_sobel);

    fwrite(image_sobel, sizeof(unsigned char), HEIGHT * WIDTH, out_fp);

    fclose(in_fp);
    
    fclose(out_fp);
/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
