#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include<time.h>
#include<string.h>

//#define	TRAINING_DATA_max 5000  // Max number of dimensions of the search space
#define	DIMENSION_max 200
#define LINGUISTIC_max 200 // Max swarm size
#define	PI 3.1415927
//#define	no_particle 30
#define	g_fcm 1.25
#define eta 0.01

//double    minimum(double g[], double     minimum,int NC)
//{
//int bats;
//
//    minimum=g[0];
//for(bats=1;bats<NC;bats++)
//{
//if (g[bats]<=minimum)
//{
//    minimum=g[bats];
//
//}
//}
//return     minimum;
//}

double max(double num1, double num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

double mul(double num1, double num2)
{
    return num1*num2;
}


double min(double num1, double num2)
{
    return (num1 > num2 ) ? num2 : num1;
}


void  file_management(double *i_inp,double *linguisticinput[],int *li,int *no_input,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *coefficient[])
{
FILE *   fpinput,*fplinguisticmamdaniifelseoutput,*fplinguisticmamdaniinput,*fplinguisticmamdanioutput,*fplinguisticnoinput,*fplinguisticnooutput,*fplinguistictermmamdaniinput,*fplinguistictermmamdanioutput,*fplinguisticrangemamdaniinput_min,*fplinguisticrangemamdaniinput_max,*fplinguisticrangemamdanioutput_min,*fplinguisticrangemamdanioutput_max,*fplinguisticrangemamdanioutput;
//char linguistic_term_input[DIMENSION_max][50],linguistic_term_output[DIMENSION_max][50];
int i_lter,dimension,trainingscenario;


fplinguisticnoinput=fopen("takagi_sugeno_linguistic_no_input.txt","r");
for (dimension=0;dimension<*no_input;dimension++)
            {
 //for (i_linguistic=0;i_linguistic<linguistic[dimension];i_linguistic++)
  // {
 fscanf(fplinguisticnoinput,"%d",&li[dimension]);


  // }
  // printf("\n");
            }

             fclose(fplinguisticnoinput);


//
//            fplinguisticnooutput=fopen("mamdani_linguistic_no_output.txt","r");
//            for (dimension=0;dimension<*no_output;dimension++)
//            {
// //for (i_linguistic=0;i_linguistic<linguistic[dimension];i_linguistic++)
//  // {
// fscanf(fplinguisticnooutput,"%d",&lo[dimension]);
//
//
//  // }
//  // printf("\n");
//            }
//         //   printf("\n");
// fclose(fplinguisticnooutput);
//
//








   fpinput=fopen("input_takagi_sugeno.txt","r");


            for (dimension=0;dimension<*no_input;dimension++)
            {

                fscanf(fpinput,"%lf",&i_inp[dimension]);
//printf("%lf\t",i_inp[trainingscenario][dimension]);
            }
         // printf("\n");

    fclose(fpinput);




fplinguisticmamdaniinput=fopen("linguistic_takagi_sugeno_input.txt","r");

for (dimension=0;dimension<*no_input;dimension++)
            {
             for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticmamdaniinput,"%lf",(*(linguisticinput+dimension)+i_lter));
     // printf("%s\t",linguistic_term_input[i_lter]);

            }
            // printf("\n");
            }

fclose(fplinguisticmamdaniinput);


fplinguisticmamdanioutput=fopen("takagi_sugeno_co_efficient.txt","r");

            for (dimension=0;dimension<*no_input;dimension++)
            {
             for (i_lter=0;i_lter<li[dimension];i_lter++)
            {
fscanf(fplinguisticmamdanioutput,"\n%lf",(*(coefficient+dimension)+i_lter));
        // fscanf(fpRB,"\n%lf",linguistic_term_output[dimension][i_lter]);
      //printf("\t%s",linguistic_term_output[i_lter]);

            }
            //printf("\n");
            }

fclose(fplinguisticmamdanioutput);

//*index_no_if_else=1;
//for (dimension=0;dimension<*no_input;dimension++)
//            {
//
//*index_no_if_else=*index_no_if_else*li[dimension];
//            }
//fplinguisticmamdaniifelseoutput=fopen("linguistic_mamdani_if else_output.txt","r");
//
//            for (dimension=0;dimension<*no_output;dimension++)
//            {
//             for (i_lter=0;i_lter<*index_no_if_else;i_lter++)
//            {
//fscanf(fplinguisticmamdaniifelseoutput,"\n%lf",(*(linguisticoutput_if_else+dimension)+i_lter));
//        // fscanf(fpRB,"\n%lf",linguistic_term_output[dimension][i_lter]);
//      //printf("\t%s",linguistic_term_output[i_lter]);
//
//            }
//            //printf("\n");
//            }
//
//fclose(fplinguisticmamdaniifelseoutput);



fplinguisticrangemamdaniinput_min=fopen("linguistic_range_takagi_sugeno_input_min.txt","r");

for (dimension=0;dimension<*no_input;dimension++)
            {
             for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdaniinput_min,"%lf",(*(linguistic_range_input_min+dimension)+i_lter));
     // printf("%s\t",linguistic_term_input[i_lter]);

            }

            }

fclose(fplinguisticrangemamdaniinput_min);







fplinguisticrangemamdaniinput_max=fopen("linguistic_range_takagi_sugeno_input_max.txt","r");

for (dimension=0;dimension<*no_input;dimension++)
            {

           for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdaniinput_max,"%lf",(*(linguistic_range_input_max+dimension)+i_lter));
     // printf("%s\t",linguistic_term_input[i_lter]);

            }
            }

fclose(fplinguisticrangemamdaniinput_max);









//fplinguisticrangemamdanioutput_min=fopen("linguistic_range_mamdani_output_min.txt","r");
//
//for (dimension=0;dimension<*no_output;dimension++)
//            {
//             for (i_lter=0;i_lter<lo[dimension];i_lter++)
//            {
//
//         fscanf(fplinguisticrangemamdanioutput_min,"%lf",(*(linguistic_range_output_min+dimension)+i_lter));
//     // printf("%s\t",linguistic_term_input[i_lter]);
//
//            }
//
//            }
//
//fclose(fplinguisticrangemamdanioutput_min);
//
//
//
//
//
//
//
//fplinguisticrangemamdanioutput_max=fopen("linguistic_range_mamdani_output_max.txt","r");
//
//for (dimension=0;dimension<*no_output;dimension++)
//            {
//
//           for (i_lter=0;i_lter<lo[dimension];i_lter++)
//            {
//
//         fscanf(fplinguisticrangemamdanioutput_max,"%lf",(*(linguistic_range_output_max+dimension)+i_lter));
//     // printf("%s\t",linguistic_term_input[i_lter]);
//
//            }
//            }
//
//fclose(fplinguisticrangemamdanioutput_max);
//
}

















void  membership_function(double *membership_function_value[],int *ii,int *linguistic_number[],int *li,int *no_input,double *i_inp,double *linguistic_range_input_min[],double *linguistic_range_input_max[])
{
    int i_lter,dimension;

    for (dimension=0;dimension<*no_input;dimension++)
           {
               membership_function_value[dimension][0]=1-((i_inp[dimension]-linguistic_range_input_min[dimension][0])/(linguistic_range_input_max[dimension][0]-linguistic_range_input_min[dimension][0]));
        for (i_lter=1;i_lter<li[dimension]-1;i_lter++)
        {
membership_function_value[dimension][i_lter]=max(min(((i_inp[dimension]-linguistic_range_input_min[dimension][i_lter])/((0.5*(linguistic_range_input_max[dimension][i_lter]+linguistic_range_input_min[dimension][i_lter]))-linguistic_range_input_min[dimension][i_lter])),((linguistic_range_input_max[dimension][i_lter]-i_inp[dimension])/(linguistic_range_input_max[dimension][i_lter]-(0.5*(linguistic_range_input_max[dimension][i_lter]+linguistic_range_input_min[dimension][i_lter]))))),0);
        }

membership_function_value[dimension][li[dimension]-1]=1-((linguistic_range_input_max[dimension][li[dimension]-1]-i_inp[dimension])/(linguistic_range_input_max[dimension][li[dimension]-1]-linguistic_range_input_min[dimension][li[dimension]-1]));

           }


}



void  data_base(int *ii,int *linguistic_number[],int *li,int *no_input,double *i_inp,double *linguistic_range_input_min[],double *linguistic_range_input_max[])

{

    int i_lter,dimension;

            for (dimension=0;dimension<*no_input;dimension++)
            {
ii[dimension]=0;
for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

             if((i_inp[dimension]>=linguistic_range_input_min[dimension][i_lter]) && (i_inp[dimension]<=linguistic_range_input_max[dimension][i_lter]))
                {

                    linguistic_number[dimension][ii[dimension]]=i_lter;

//printf("%lf\t",linguisticinput[dimension][linguistic_number[trainingscenario][dimension][ii[trainingscenario][dimension]]]);
ii[dimension]=ii[dimension]+1;
                }



            }

            }


}




void rule_base(int *i_ltern,double *i_inp,int *li,int *no_input,double *linguisticoutput[],double *coefficient[],int *ii,int *linguistic_number[])
{

int i_lter,i_lter1,i_lter2,i_lter3,dimension,iii,jjj,dimension1;


//
//*i_ltern=0;
//
//
//   for (dimension=0;dimension<*no_input;dimension++)
//            {
//
//for (iii=0;iii<ii[dimension];iii++)
//            {
//
////linguisticoutput[0][*i_ltern]=linguisticoutput[0][*i_ltern]+coefficient[dimension][linguistic_number[dimension][iii]];
//
//*i_ltern=*i_ltern+1;
//            }
//            }
//
//
//
//
//
//
//
//            for (dimension=0;dimension<*no_input;dimension++)
//            {
//
//for (iii=0;iii<ii[dimension];iii++)
//            {
//                linguisticoutput[0][iii]=0;
//            }
//            }
//
//
//   for (dimension=0;dimension<*no_input;dimension++)
//            {
//
//for (iii=0;iii<ii[dimension];iii++)
//            {
//
//linguisticoutput[0][iii]=linguisticoutput[0][iii]+coefficient[dimension][linguistic_number[dimension][iii]];
//
//            }
//            }


*i_ltern=0;
   for (dimension=0;dimension<*no_input-1;dimension++)
            {
        for (iii=0;iii<ii[dimension];iii++)
            {

                 for (dimension1=1;dimension1<*no_input;dimension1++)
            {
        for (jjj=0;jjj<ii[dimension1];jjj++)
            {
linguisticoutput[0][*i_ltern]=coefficient[dimension][linguistic_number[dimension][iii]]*i_inp[dimension]+coefficient[dimension1][linguistic_number[dimension1][jjj]]*i_inp[dimension1];//(membership_function_value_input[dimension][linguistic_number[dimension][iii]],membership_function_value_input[dimension1][linguistic_number[dimension1][jjj]]);

*i_ltern=*i_ltern+1;

            }
            }
            }
            }

}

main()
{
    FILE *fpRB,*fpnolinguistic,*fplinguistic,*fpinput,*fpFZCM,*fpsee,*fpsee1,*fpsee2,*fprange,*fpoutput;
    int i_lter,trainingscenario,no_trainingscenario,dimension,no_input,no_output,i_index,dimension1,i_index1,dimension2,iteration,i_linguistic,*linguistic_input,*linguistic_output,*ii,index_no_if_else,i_lter1,i_flag;
   int in_index,iii,itest1,itest2,output_index1,i_lternt,in_indext,ii_index,*index_output_linguistic[DIMENSION_max],jjj,iii_index,*jj;//,*linguistic_number[TRAINING_DATA_max];


   double *linguisticinput[DIMENSION_max],*linguisticoutput[DIMENSION_max],*coefficient[DIMENSION_max],*weight[DIMENSION_max],*LCM,*HCF,*crisp_output;
    double *membership_function_value_input[DIMENSION_max];
   double *linguistic_range_input_min[DIMENSION_max],*linguistic_range_input_max[DIMENSION_max];
    double criteria,*i_inp,*o_oup,* membership_matrix,*randnum,minfp,gbest_location,*min_input,*max_input,*min_output,*max_output,*AA[DIMENSION_max],*BB[DIMENSION_max],*EuD[DIMENSION_max],* membership_matrix_update,*diff_membership_matrix;
//srand ( time(NULL) );
int inti_ltern,i_lterni;
 //double *test1[maxs];
int i_lter2,i_lter3,*linguistic_number[DIMENSION_max];
//linguistic[dimension]

//sumrandnum= (double *) malloc(TRAINING_DATA_max * sizeof(double));
linguistic_input= (int *) malloc(	DIMENSION_max * sizeof(int));

//linguistic_number= (int *) malloc(	LINGUISTIC_max * sizeof(int));
min_input= (double *) malloc(	DIMENSION_max * sizeof(double));
max_input= (double *) malloc(	DIMENSION_max * sizeof(double));


LCM= (double *) malloc(	DIMENSION_max * sizeof(double));
HCF= (double *) malloc(	DIMENSION_max * sizeof(double));

crisp_output= (double *) malloc(DIMENSION_max * sizeof(double));


//membership_value= (double *) malloc(	DIMENSION_max * sizeof(double));
//y_co_input= (double *) malloc(	DIMENSION_max * sizeof(double));
//x_ab_input= (double *) malloc(	DIMENSION_max * sizeof(double));
//linguistic_term= (char *) malloc(	DIMENSION_max * sizeof(char));
//linguistic_term= (double *) malloc(	DIMENSION_max * sizeof(double));


//     abs1= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
 ii= (int *) malloc(	DIMENSION_max  * sizeof(int));

   fpFZCM=fopen("Fuzzy_takagi_sugeno.txt","r");

   fscanf(fpFZCM,"%d\n%d",&no_input,&no_output);
fclose(fpFZCM);


//printf("%d",no_trainingscenario);
//printf("\n%d",no_input_dimension);
//printf("\n%d",no_cluster);



    i_inp=(double *) malloc(DIMENSION_max * sizeof(double));
    o_oup=(double *) malloc(DIMENSION_max * sizeof(double));

     //i_lterni= (int *) malloc(	LINGUISTIC_max  * sizeof(int));




     for (i_index=0;i_index<(no_input+no_output);i_index++)
    {
   //test1[i_index]=(double *) malloc(DIMENSION_max * sizeof(double));
       linguistic_number[i_index]=(int*) malloc(LINGUISTIC_max  * sizeof(int));


    membership_function_value_input[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
            //linguistic_term_output[i_index]= (double *) malloc(	LINGUISTIC_max * sizeof(double ));
       linguisticinput[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
         linguisticoutput[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));


              linguistic_range_input_min[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
              linguistic_range_input_max[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
coefficient[i_index]=(double *) malloc(	LINGUISTIC_max  * sizeof(double ));
weight[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
                   //small_end[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
                  //membership_value[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
//                 aoutput_index1[i_index]= (int *) malloc(	LINGUISTIC_max  * sizeof(int));
   }
//    for (i_index1=0;i_index1<no_trainingscenario;i_index1++)
//    {
// membership_matrix[i_index1]=(double *) malloc(DIMENSION_max * sizeof(double));
//randnum[i_index1]=(double *) malloc(DIMENSION_max * sizeof(double));
//EuD[i_index1]=(double *) malloc(DIMENSION_max * sizeof(double));
//membership_matrix_update[i_index1]=(double *) malloc(DIMENSION_max * sizeof(double));
//diff_membership_matrix[i_index1]=(double *) malloc(DIMENSION_max * sizeof(double));
//
//    }
//
//no_trainingscenario
//int ***linguistic_number;
//linguistic_number=(int ***) malloc(no_trainingscenario*sizeof(int**));
//
// for (i_index=0;i_index<no_trainingscenario;i_index++)
//    {
//       linguistic_number[i_index]=(int **) malloc(DIMENSION_max*sizeof(int *));
//       for (i_index1=0;i_index1<DIMENSION_max;++i_index1)
//       {
//
//
//
//linguistic_number[i_index][i_index1]=(int *)malloc(LINGUISTIC_max*sizeof(int));
//}
//    }

//  printf("\n");


//    fpoutput=fopen("output_mamdani.txt","r");
//    for (trainingscenario=0;trainingscenario<no_trainingscenario;trainingscenario++)
//    {
//            for (dimension=0;dimension<no_output;dimension++)
//            {
//
//                fscanf(fpoutput,"%lf",&o_oup[trainingscenario][dimension]);
////printf("%lf\t",i_inp[trainingscenario][dimension]);
//            }
//         // printf("\n");
//    }
//   //printf("\n");
//    fclose(fpoutput);


//    fplinguistic=fopen("mamdani_linguistic.txt","r");
//
//
//            for (dimension=0;dimension<no_input;dimension++)
//            {
// for (i_linguistic=0;i_linguistic<no_linguistic;i_linguistic++)
//    {
//                fscanf(fplinguistic,"%lf",&i_inp[trainingscenario][dimension]);
////printf("%lf\t",i_inp[trainingscenario][dimension]);
//            }
//         // printf("\n");
//    }
//   //printf("\n");
//    fclose(fplinguistic);
//fprange=fopen("range_mamdani.txt","r");
//for (dimension=0;dimension<no_input;dimension++)
//            {

//fscanf(fprange,"%lf\t%lf",&min_input[dimension],&max_input[dimension]);
//printf("\n%lf\t%lf",min_input[dimension],max_input[dimension]);
//            }
//
//            for (dimension=0;dimension<no_output;dimension++)
//            {
//
//fscanf(fprange,"%lf\t%lf",&min_output[dimension],&max_output[dimension]);
//printf("\n%lf\t%lf",min_output[dimension],max_output[dimension]);
//            }
//fclose(fprange);
// printf("\n");
//  printf("\n");




file_management(i_inp,linguisticinput,linguistic_input,&no_input,linguistic_range_input_min,linguistic_range_input_max,coefficient);

for (dimension=0;dimension<no_input;dimension++)
          {
         for (i_lter=0;i_lter<linguistic_input[dimension];i_lter++)
            {
//printf("%lf\t",linguisticinput[dimension][i_lter]);
   printf("%lf\t\t%lf\n",linguistic_range_input_min[dimension][i_lter],linguistic_range_input_max[dimension][i_lter]);

            }

             printf("\n");
            }
//
  printf("\n");




//for (trainingscenario=0;trainingscenario<no_trainingscenario;trainingscenario++)
//    {
//            for (dimension=0;dimension<no_input;dimension++)
//            {
//ii[trainingscenario][dimension]=0;
//for (i_lter=0;i_lter<linguistic_input[dimension];i_lter++)
//            {
//
//             if((i_inp[trainingscenario][dimension]>=linguistic_range_input_min[dimension][i_lter]) && (i_inp[trainingscenario][dimension]<=linguistic_range_input_max[dimension][i_lter]))
//                {
//
//                    linguistic_number[trainingscenario][dimension][ii[trainingscenario][dimension]]=i_lter;
//
//printf("%lf\t",linguisticinput[dimension][linguistic_number[trainingscenario][dimension][ii[trainingscenario][dimension]]]);
//ii[trainingscenario][dimension]=ii[trainingscenario][dimension]+1;
//                }
//
//
//
//            }
//
//            }
//   }
//      printf("\n");
//      printf("\n");

//
data_base(ii,linguistic_number,linguistic_input,&no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max);



for (dimension=0;dimension<no_input;dimension++)
            {
for (iii=0;iii<ii[dimension];iii++)
            {
printf("%lf\t",linguisticinput[dimension][linguistic_number[dimension][iii]]);
            }
            }


     printf("\n");
      printf("\n");


      for (dimension=0;dimension<no_input;dimension++)
          {

    for (iii=0;iii<ii[dimension];iii++)
            {

          printf("%lf\t",coefficient[dimension][linguistic_number[dimension][iii]]);

            }

             printf("\n");
            }
//
  printf("\n");
//   for (dimension=0;dimension<no_input;dimension++)
//            {
//
//        for (iii=0;iii<ii[dimension];iii++)
//            {
//
//                linguisticinput1[dimension][linguistic_number[dimension][iii]]=linguisticinput[dimension][linguistic_number[dimension][iii]];
////printf("%lf\t",linguisticinput1[dimension][linguistic_number[trainingscenario][dimension][iii]]);
//
//            }
//          }
//
//    printf("\n");
//linguistic_input[2]=8;
//in_index=1;
//
//  for (dimension=0;dimension<3;dimension++)
//            {
//          for (i_lter2=0;i_lter2<linguistic_input[dimension];i_lter2++)
//        {
//
//
//
//in_index=i_lter2*in_index;
//
//
//printf("\n%d",in_index);
//
//
//        }
//        }





rule_base(&i_lterni,i_inp,linguistic_input,&no_input,linguisticoutput,coefficient,ii,linguistic_number);
////
////
printf("\n%d",i_lterni);
//////




    for (iii=0;iii<i_lterni;iii++)
            {


printf("\n%lf",linguisticoutput[0][iii]);
            }

 printf("\n");






membership_function(membership_function_value_input,ii,linguistic_number,linguistic_input,&no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max);


   for (dimension=0;dimension<no_input;dimension++)
            {
        for (iii=0;iii<ii[dimension];iii++)
            {
printf("\n%lf\t",membership_function_value_input[dimension][linguistic_number[dimension][iii]]);
            }
            }

printf("\n");


iii_index=0;
   for (dimension=0;dimension<no_input-1;dimension++)
            {
        for (iii=0;iii<ii[dimension];iii++)
            {

                 for (dimension1=1;dimension1<no_input;dimension1++)
            {
        for (jjj=0;jjj<ii[dimension1];jjj++)
            {
weight[0][iii_index]=mul(membership_function_value_input[dimension][linguistic_number[dimension][iii]],membership_function_value_input[dimension1][linguistic_number[dimension1][jjj]]);
   printf("\n%lf",weight[0][iii_index]);
iii_index=iii_index+1;

            }
            }
            }
            }






            for (dimension=0;dimension<no_output;dimension++)
        {

                LCM[dimension]=0;
          HCF[dimension]=0;
              for (iii=0;iii<i_lterni;iii++)
            {
   LCM[dimension]=LCM[dimension]+weight[dimension][iii]*linguisticoutput[dimension][iii];
     HCF[dimension]=HCF[dimension]+weight[dimension][iii];
     crisp_output[dimension]=LCM[dimension]/HCF[dimension];
            }
         printf("\n%lf",crisp_output[dimension]);
        }











}
