#include <stdio.h>

#define WIDTH 256
#define HEIGHT 256
#define N 256

int main() {
    int i, j;
    unsigned char image[HEIGHT][WIDTH];
    unsigned char imng[HEIGHT][WIDTH];
    char image_name[N];
    FILE *fp;

/////////////// READ AN IMAGE /////////////////////////////////////////////////////////
    scanf("%s", image_name);

    fp = fopen(image_name, "rb");

    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);

    fclose(fp);
/////////////// READ AN IMAGE /////////////////////////////////////////////////////////

/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////
    scanf("%s", image_name);
    
    fp = fopen(image_name, "wb");

    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            imng[i][j] = 255 - image[i][j];
        }
    }

    fwrite(imng, sizeof(unsigned char), HEIGHT * WIDTH, fp);

    fclose(fp);
/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
