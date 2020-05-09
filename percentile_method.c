#include <stdio.h>

#define N 256
#define HEIGHT 256
#define WIDTH 256

FILE *in_fp;
FILE *out_fp;
int i, j;
int histogram[N];
char in_name[N];
char out_name[N];
unsigned char image[HEIGHT][WIDTH]; 
unsigned char image_percentile_method[HEIGHT][WIDTH];

/////////////// HISTOGRAM /////////////////////////////////////////////////////////
void image_histogram(unsigned char img[HEIGHT][WIDTH], int h[N]){

    for( i = 0; i < N; i++ ){
        h[i] = 0;
    }

    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            h[img[i][j]]++;
        }
    }
}
/////////////// HISTOGRAM /////////////////////////////////////////////////////////

/////////////// PERCENTILE METHOD /////////////////////////////////////////////////////////
int percentile_method(int h[N], unsigned char input_image[HEIGHT][WIDTH], unsigned char output_image[HEIGHT][WIDTH], double p){
    int i, j;
    int histogram_sum = 0;
    int from_zero_to_theta;

    for( i = 0; i < N; i++ ){
        histogram_sum += h[i];
    }

    from_zero_to_theta = histogram_sum * p;
    
    histogram_sum = 0;
    for( i = 0; i < N; i++ ){

        histogram_sum += h[i];

        if( histogram_sum > from_zero_to_theta ){
            return i;
        }
    }

}
/////////////// PERCENTILE METHOD /////////////////////////////////////////////////////////

int main(void) {

/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////
    printf("Input:");
    scanf("%s", &in_name);
    in_fp = fopen(in_name, "rb");
    
    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, in_fp);

    printf("Output:");
    scanf("%s", &out_name);
    out_fp = fopen(out_name, "wb");

    image_histogram(image, histogram);

    printf("%d\n", percentile_method(histogram, image, image_percentile_method, 0.23));
    int theta = percentile_method(histogram, image, image_percentile_method, 0.23);
    
    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            if( image[i][j] < theta ) image_percentile_method[i][j] = 0;
            else image_percentile_method[i][j] = 255;
        }
    } 

    fclose(in_fp);
    
    fwrite(image_percentile_method, sizeof(unsigned char), HEIGHT * WIDTH, out_fp);

    fclose(out_fp);
/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
