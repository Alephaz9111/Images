
// 256x256 gray images discriminant analysis method

#include <stdio.h>

#define N 256
#define HEIGHT 256
#define WIDTH 256

FILE *in_fp;
FILE *out_fp;
char in_name[N];
char out_name[N];
int i, j;
unsigned char image[HEIGHT][WIDTH]; 
unsigned char image_discrim[HEIGHT][WIDTH];
int t_num = 0;
int theta = 0;

int find_t_num(unsigned char image[HEIGHT][WIDTH]){

    double Sb2_max = 0;

    for( t_num = 0; t_num < N; t_num++ ){

        double Sb2 = 0;
        double w1 = 0, w2 = 0, m1 = 0, m2 = 0;
        int class1 = 0, sum1 = 0, ave1 = 0;
        int class2 = 0, sum2 = 0, ave2 = 0;

        for( i = 0; i < HEIGHT; i++ ){

            for( j = 0; j < WIDTH; j++ ){

                if( image[i][j] < t_num ){
                    sum1 = sum1 + image[i][j];
                    class1++;
                }else{
                    sum2 = sum2 + image[i][j];
                    class2++;
                }

            }
        }

        w1 = class1/(double)65536; //256x256
        w2 = class2/(double)65536; //256x256

        if( class1 == 0 ) m1 = 0;
        else m1 = sum1/class1;

        if( class2 == 0 ) m2 = 0;
        else m2 = sum2/class2;

        Sb2 = w1 * w2 * (m1 - m2) * (m1 - m2);
        
        if( Sb2 > Sb2_max ){
            Sb2_max = Sb2;
            theta = t_num;
        }

    }

    return theta;
}

int main(void) {

/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////
    printf("Input:");
    scanf("%s", &in_name);
    in_fp = fopen(in_name, "rb");
    
    fread(image, sizeof(unsigned char), HEIGHT * WIDTH, in_fp);

    printf("Output:");
    scanf("%s", &out_name);
    out_fp = fopen(out_name, "wb");

    printf("%d\n", find_t_num(image));
    int theta = find_t_num(image);
    
    for( i = 0; i < HEIGHT; i++ ){
        for( j = 0; j < WIDTH; j++ ){
            if( image[i][j] < theta ) image_discrim[i][j] = 0;
            else image_discrim[i][j] = 255;
        }
    } 


    fclose(in_fp);
    
    fwrite(image_discrim, sizeof(unsigned char), HEIGHT * WIDTH, out_fp);

    fclose(out_fp);
/////////////// READ AND WRITE AN IMAGE /////////////////////////////////////////////////////////

    return 0;
}
