#include <stdio.h>

#define N 256
#define HEIGHT 256 
#define WIDTH 256 
#define MIN 0
#define MAX 255

int main(){
    int i, j;
    int min, max;
    char image_name[N];
    unsigned char image[HEIGHT][WIDTH]; 
    unsigned char image_exp[HEIGHT][WIDTH]; 
    FILE *fp;
    float d;

/////////////// READ AN IMAGE /////////////////////////////////////////////////////////
    scanf("%s", image_name);

    fp = fopen(image_name, "rb");

    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);

    fclose(fp);
/////////////// READ AN IMAGE /////////////////////////////////////////////////////////

/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////
    printf("Image's Name:");   
    scanf("%s", image_name);

    printf("min:");   
    scanf("%d", &min);

    printf("max:");   
    scanf("%d", &max);

    fp = fopen(image_name, "wb");
   
    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            d = (float)MAX / (float)(max - min) * ((int)image[i][j] - MIN);
            if (d > 255) image_exp[i][j] = MAX;
            else if (d < 0) image_exp[i][j] = MIN;
            else image_exp[i][j] = (unsigned char)d;
        }
    }

    fwrite(image_exp, sizeof(unsigned char), HEIGHT * WIDTH, fp);
    
    fclose(fp);
/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
