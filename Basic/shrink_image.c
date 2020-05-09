#include <stdio.h>

#define N 256
#define HEIGHT 256 
#define WIDTH 256 

int main(){

    int i, j;
    int tmp;
    int n;
    char image_name[N];
    unsigned char image[HEIGHT][WIDTH]; 
    unsigned char image_small[HEIGHT/2][WIDTH/2]; 
    FILE *fp;

//////////////////////////////////// READ AN IMAGE /////////////////////////////////////////
    printf("Input :");
    scanf("%s", image_name);

    fp = fopen(image_name, "rb");
    
    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, fp);

    fclose(fp);
//////////////////////////////////// READ AN IMAGE /////////////////////////////////////////  
//////////////////////////////////// WRITE AN IMAGE ////////////////////////////////////////  
    printf("Output :");
    scanf("%s", image_name);

    printf("Magnification：");
    scanf("%d", &n);

/****************************** SHRINK AN IMAGE *******************************************/
    for( i = 0; i < HEIGHT/n; i++ ){
        for( j = 0; j < WIDTH/n; j++ ){
            image_small[i][j] = image[n*i][n*j];
        }
    }
/****************************** SHRINK AN IMAGE *******************************************/

    fwrite(image_small, sizeof(unsigned char), HEIGHT/n * WIDTH/n, fp);
    
    fclose(fp);
//////////////////////////////////// WRITE AN IMAGE ////////////////////////////////////////  

    return 0;
}
