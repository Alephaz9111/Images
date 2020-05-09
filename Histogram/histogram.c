//TEST
#include <stdio.h>

#define N 256
#define HEIGHT 256 
#define WIDTH 256 

int main(){
    int i, j;
    int histogram[N];
    char image_name[N];
    char text_name[N];
    unsigned char image[HEIGHT][WIDTH]; 
    FILE *fp;

/////////////// INITIALIZE HISTOGRAM /////////////////////////////////////////////////////////
    for( i = 0; i < N; i++ ){
        histogram[i] = 0;
    }
/////////////// INITIALIZE HISTOGRAM /////////////////////////////////////////////////////////

/////////////// READ AN IMAGE /////////////////////////////////////////////////////////
    scanf("%s", image_name);

    fp = fopen(image_name, "rb");
    
    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);

    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            histogram[image[i][j]]++;
        }
    }

    fclose(fp);
/////////////// READ AN IMAGE /////////////////////////////////////////////////////////

/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////
    scanf("%s", text_name);

    fp = fopen(text_name, "wb");
   
    for( i = 0; i < HEIGHT; i++ ){
        fprintf(fp, "%d %d\n", i, histogram[i]);
    }

    fclose(fp);
/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
