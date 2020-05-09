#include <stdio.h>

#define N 256
#define ZMAX 255
#define HEIGHT 256 
#define WIDTH 256 

int histogram[N];
unsigned char image[HEIGHT][WIDTH]; 
unsigned char image_flat[HEIGHT][WIDTH];

/////////////// THE HISTOGRAM OF AN IMAGE /////////////////////////////////////////////////////////
void image_histogram(unsigned char imageIn[HEIGHT][WIDTH]){
    int i, j;

    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            histogram[imageIn[i][j]]++;
        }
    }

}
/////////////// THE HISTOGRAM OF AN IMAGE /////////////////////////////////////////////////////////

/////////////// HISTOGRAM FLATTENING /////////////////////////////////////////////////////////
void histogram_flattening(int input_histogram[N], unsigned char output_image[HEIGHT][WIDTH]){
    int i, j, z;
    int histogram_sum;

    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            histogram_sum = 0;
            for( z = 0; z < image[i][j]; z++ ){
                histogram_sum += input_histogram[z];
            }
            output_image[i][j] = (float)(histogram_sum * ZMAX) / (float)(HEIGHT * WIDTH);
        } 
    }
    
}
/////////////// HISTOGRAM FLATTENING /////////////////////////////////////////////////////////

int main(){
    FILE *fp;
    char image_name[N];

/////////////// READ AN IMAGE /////////////////////////////////////////////////////////
    printf("Input Name:");   
    scanf("%s", image_name);

    fp = fopen(image_name, "rb");

    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);

    image_histogram(image);

    fclose(fp);
/////////////// READ AN IMAGE /////////////////////////////////////////////////////////

/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////
    printf("Output Name:");   
    scanf("%s", image_name);

    fp = fopen(image_name, "wb");

    histogram_flattening(histogram, image_flat);

    fwrite(image_flat, sizeof(unsigned char), HEIGHT * WIDTH, fp);
    
    fclose(fp);
/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
