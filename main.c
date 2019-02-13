#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include<math.h>

void area(double vetrices_x[],int n, double vetrices_y[],int n,double vertices2_y[],int n, double vertices2_x[],int n);


void area(double vetrices_x[],int n, double vetrices_y[],int n,double vertices2_y[],int n, double vertices2_x[],int n)
{

     double pen1area=abs((vetrices_x[0]*vetrices_y[1]-vetrices_y[0]*vetrices_x[1])+(vetrices_x[1]*vetrices_y[2]-vetrices_y[1]*vetrices_x[2])+(vetrices_x[2]*vetrices_y[3]-vetrices_y[2]*vetrices_x[3])+(vetrices_x[3]*vetrices_y[0]-vetrices_y[4]*vetrices_x[0]));
    printf("\n%lf",pen1area);
    double pen2area=abs((vertices2_x[0]*vertices2_y[1]-vertices2_y[0]*vertices2_x[1])+(vertices2_x[1]*vertices2_y[2]-vertices2_y[1]*vertices2_x[2])+(vertices2_x[2]*vertices2_y[3]-vertices2_y[2]*vertices2_x[3])+(vertices2_x[3]*vertices2_y[0]-vertices2_y[4]*vertices2_x[0]));
    printf("\n%lf",pen2area);

    printf("\n pentagon 1 area is bigger");




}


int main()
{


    double x_min = 0; //x range
    double y_min = 0; //y range
    double x_max=50;
    double y_max=50;

    srand((unsigned)time(0));
    int n;
    printf("Enter a number of points more than six:");

	scanf("%d",&n);
	double *x = (double*)malloc(n* sizeof (double) );// array for determining x coordinate
	double *y = (double*)malloc(n*sizeof (double) );// array for determining y coordinate


	for (int i=0;i<n;i++)
    {
       x[i]=rand()*(x_max - x_min) / (double)RAND_MAX;   //allocating coordinates to x

       y[i]=rand()*(y_max - y_min) / (double)RAND_MAX;    //allocating coordinates to y


    }

    for (int i=0;i<n;i++)
    {
        printf("%lf  \t %lf \n ",x[i],y[i]);    //printing values of both x and y coordinates

    }


    //defining center of gravity  for the set of points

    double sumx=0;
    double sumy=0;
    double y_center;
    double x_center;

    for (int i=0;i<n;i++)
    {
        sumx+=x[i];
        x_center=sumx/n;

    }
    for (int i=0;i<n;i++)
    {
        sumy+=y[i];
        y_center=sumy/n;

    }

    printf("\n center of gravity for the set of points: %lf \t%lf",x_center,y_center);



 // choosing vertices, by finding the distance between each of these points and the centre of gravity in a new array

    double*distance=(double*)malloc(n*sizeof(double));

    for(int i=0;i<n;i++)
    {
        distance[i]=sqrt(pow(y[i]-y_center,2)+pow(x[i]-x_center,2));

    }


    //sorting the elements of the array by using bubble sort to find the index of all distances
    double temp;
    double* sorted_distance=(double*)malloc(n*sizeof(double));
    for (int i=0;i<n;i++)
    {
        sorted_distance[i]=distance[i];
    }


    for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (sorted_distance[i] < sorted_distance[j])
                {
                    temp = sorted_distance[i];
                    sorted_distance[i] = sorted_distance[j];
                    sorted_distance[j] = temp;

                }
            }
        }


         ///finding the index for all the elements and allocating them to the an index array

      int*index=(int*)malloc(n*sizeof(int));


       for(int i=0;i<n;i++)
      {

            for(int j=0;j<n;j++)


              if(sorted_distance[i]==distance[j])
              {
                  index[i]=j;

              }

      }


    //Defining the vertices for the first pentagon
    double vetrices_x[5];
    double vetrices_y[5];

    for (int i=0;i<5;i++)
    {
        vetrices_x[i]=x[index[i]];

    }

    for(int i=0;i<5;i++)
    {
        printf("\n vetrices x: %lf",vetrices_x[i]);


    }

    for (int i=0;i<5;i++)
    {
        vetrices_y[i]=y[index[i]];

    }

    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("\n vertices y : %lf",vetrices_y[i]);


    }


 //defining algorithm for the other pentagon, static pentagon, would connect the next set of points

 double vertices2_x[5];
 double vertices2_y[5];

 for (int i=0;i<5;i++)
    {
        vertices2_x[i]=x[index[i+1]];

    }

    for(int i=0;i<5;i++)
    {
        printf("\n vertices 2 x %lf",vertices2_x[i]);


    }

    for (int i=0;i<5;i++)
    {
        vertices2_y[i]=y[index[i+1]];

    }

    printf("\n");
    for(int i=0;i<5;i++)
    {
        printf("\n vertices2 y%lf",vertices2_y[i]);

    }


    //finding the area of the first rectangle
    FILE*file=fopen("data.csv","w");


    for(int i=0;i<n;i++)
    {
        fprintf(file,"%lf,%lf\n",x[i],y[i]);    //printing values of the set of points in a file
    }
    fprintf(file,"\n");


    for(int i=0;i<5;i++)
    {
        fprintf(file,"%lf,%lf\n",vetrices_x[i],vetrices_y[i]);

    }

    fprintf(file,"\n");



    for(int i=0;i<5;i++)
    {
        fprintf(file,"%lf, %lf\n",vertices2_x[i],vertices2_y[i]);

    }

    fprintf(file,"\n");


    void area(vetrices_x[5],5, vetrices_y[5],5,vertices2_y[5],5, vertices2_x[5],5);





    fclose(file);

    //



	return 0;
}
