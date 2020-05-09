#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 256
#define HEIGHT 256 
#define WIDTH 256 

FILE *in_fp;
FILE *out_fp;
unsigned char image[HEIGHT][WIDTH]; 
unsigned char image_laplacian[HEIGHT][WIDTH]; 

/////////////// LAPLACIAN FILTER /////////////////////////////////////////////////////////
void laplacian(unsigned char img[HEIGHT][WIDTH], unsigned char img_laplacian[HEIGHT][WIDTH]){ 

    double eight_neighborhood[9] = {1,  1, 1, 
                                    1, -8, 1,
                                    1,  1, 1};

    int i, j, k, l;
    double sum;

    for( k = 1; k < HEIGHT - 1; k++ ){ 
        for( l = 1; l < WIDTH - 1; l++ ){ 
            sum = 0;
            for( i = 0; i < 3; i++ ){
                for( j = 0; j < 3; j++ ){
                    sum += eight_neighborhood[ i * 3 + j ] * img[ k - 1 + i ][ l - 1 + j ]; 
                }
            }
            if( sum < 0 ) sum = 0; 
            else if( sum > 255 ) sum = 255; 
            img_laplacian[k][l] = sum; 
        }
    }
}
/////////////// LAPLACIAN FILTER /////////////////////////////////////////////////////////

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

    laplacian(image, image_laplacian);

    fwrite(image_laplacian, sizeof(unsigned char), HEIGHT * WIDTH, out_fp);

    fclose(in_fp);
    
    fclose(out_fp);
/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
