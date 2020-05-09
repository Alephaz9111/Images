#include <stdio.h>

#define N 256
#define HEIGHT 256 
#define WIDTH 256 

FILE *in_fp;
FILE *out_fp;
FILE *text_fp;
char in_name[N];
char out_name[N];
int i, j, theta;
int histogram[N];
unsigned char image[HEIGHT][WIDTH]; 
unsigned char image_mode[HEIGHT][WIDTH];

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

int main(void){

/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////
    printf("Input:");
    scanf("%s", &in_name);
    in_fp = fopen(in_name, "rb");
    
    image_histogram(image);

    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, in_fp);

    printf("Output:");
    scanf("%s", &out_name);
    
    out_fp = fopen(out_name, "wb");

    printf("Theta:");
    scanf("%d", &theta);

    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            if( image[i][j] < theta ) image_mode[i][j] = 0;
            else image_mode[i][j] = 255;
        }
    } 

    fclose(in_fp);
    
    fwrite(image_mode, sizeof(unsigned char), HEIGHT * WIDTH, out_fp);

    fclose(out_fp);
/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////


    return 0;
}