#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 256
#define HEIGHT 256 
#define WIDTH 256 

FILE *in_fp;
FILE *out_fp;
unsigned char image[HEIGHT][WIDTH]; 
unsigned char image_flattening[HEIGHT][WIDTH]; 

/////////////// FLATTENING FILTER /////////////////////////////////////////////////////////
void flattening(unsigned char img[HEIGHT][WIDTH], unsigned char img_flattening[HEIGHT][WIDTH]){ 

    double flat[9] = {9, 9, 9, 
                      9, 9, 9,
                      9, 9, 9};

    int i, j, k, l;
    double sum;

    for( k = 1; k < HEIGHT - 1; k++ ){ 
        for( l = 1; l < WIDTH - 1; l++ ){ 
            sum = 0; 
            for( i = 0; i < 3; i++ ){
                for( j = 0; j < 3; j++ ){
                    sum += img[ k - 1 + i ][ l - 1 + j ] / flat[ i * 3 + j ] ; 
                }
            }
            if( sum < 0 ) sum = 0; 
            else if( sum > 255 ) sum = 255; 
            img_flattening[k][l] = sum; 
        }
    }
}
/////////////// FLATTENING FILTER /////////////////////////////////////////////////////////

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

    flattening(image, image_flattening);

    fwrite(image_flattening, sizeof(unsigned char), HEIGHT * WIDTH, out_fp);

    fclose(in_fp);
    
    fclose(out_fp);
/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
