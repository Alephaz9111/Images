#include <stdio.h>

#define N 256
#define HEIGHT 256 
#define WIDTH 256 

int main(){
    int i, j;
    int tmp;
    char image_name[N];
    unsigned char image[HEIGHT][WIDTH]; 
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
 
    for( i = 0; i < HEIGHT/2; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            tmp = image[i][j];
            image[i][j] = image[HEIGHT-i-1][j];
            image[HEIGHT-i-1][j] = tmp;
        }
    }

    fwrite(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);
    
    fclose(fp);
/////////////// WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
