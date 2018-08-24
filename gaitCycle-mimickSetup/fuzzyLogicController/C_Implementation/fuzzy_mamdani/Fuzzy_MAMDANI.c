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


double min(double num1, double num2)
{
    return (num1 > num2 ) ? num2 : num1;
}


void  file_management(double *i_inp,int *index_no_if_else,double *linguisticinput[],double *linguisticoutput[],double *linguisticoutput_if_else[],int *li,int *lo,int *no_input,int *no_output,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *linguistic_range_output_min[],double *linguistic_range_output_max[])
{
FILE *   fpinput,*fplinguisticmamdaniifelseoutput,*fplinguisticmamdaniinput,*fplinguisticmamdanioutput,*fplinguisticnoinput,*fplinguisticnooutput,*fplinguistictermmamdaniinput,*fplinguistictermmamdanioutput,*fplinguisticrangemamdaniinput_min,*fplinguisticrangemamdaniinput_max,*fplinguisticrangemamdanioutput_min,*fplinguisticrangemamdanioutput_max,*fplinguisticrangemamdanioutput;
//char linguistic_term_input[DIMENSION_max][50],linguistic_term_output[DIMENSION_max][50];
int i_lter,dimension,trainingscenario;


fplinguisticnoinput=fopen("mamdani_linguistic_no_input.txt","r");
for (dimension=0;dimension<*no_input;dimension++)
            {
 //for (i_linguistic=0;i_linguistic<linguistic[dimension];i_linguistic++)
  // {
 fscanf(fplinguisticnoinput,"%d",&li[dimension]);


  // }
  // printf("\n");
            }

             fclose(fplinguisticnoinput);

//fplinguisticnoinput=fopen("no_input_per_scenario.txt","r");
//for (dimension=0;dimension<*no_input;dimension++)
//            {
// //for (i_linguistic=0;i_linguistic<linguistic[dimension];i_linguistic++)
//  // {
// fscanf(fplinguisticnoinput,"%d",&li[dimension]);
//
//
//  // }
//  // printf("\n");
//            }

             //fclose(fplinguisticnoinput);

            fplinguisticnooutput=fopen("mamdani_linguistic_no_output.txt","r");
            for (dimension=0;dimension<*no_output;dimension++)
            {
 //for (i_linguistic=0;i_linguistic<linguistic[dimension];i_linguistic++)
  // {
 fscanf(fplinguisticnooutput,"%d",&lo[dimension]);


  // }
  // printf("\n");
            }
         //   printf("\n");
 fclose(fplinguisticnooutput);










   fpinput=fopen("input_mamdani.txt","r");


            for (dimension=0;dimension<*no_input;dimension++)
            {

                fscanf(fpinput,"%lf",&i_inp[dimension]);
//printf("%lf\t",i_inp[trainingscenario][dimension]);
            }
         // printf("\n");

    fclose(fpinput);




fplinguisticmamdaniinput=fopen("linguistic_mamdani_input.txt","r");

for (dimension=0;dimension<*no_input;dimension++)
            {
             for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticmamdaniinput,"%lf",(*linguisticinput[dimension][i_lter]));
     // printf("%s\t",linguistic_term_input[i_lter]);

            }
            // printf("\n");
            }

fclose(fplinguisticmamdaniinput);


fplinguisticmamdanioutput=fopen("linguistic_mamdani_output.txt","r");

            for (dimension=0;dimension<*no_output;dimension++)
            {
             for (i_lter=0;i_lter<lo[dimension];i_lter++)
            {
fscanf(fplinguisticmamdanioutput,"\n%lf",(*(linguisticoutput+dimension)+i_lter));
        // fscanf(fpRB,"\n%lf",linguistic_term_output[dimension][i_lter]);
      //printf("\t%s",linguistic_term_output[i_lter]);

            }
            //printf("\n");
            }

fclose(fplinguisticmamdanioutput);

*index_no_if_else=1;
for (dimension=0;dimension<*no_input;dimension++)
            {

*index_no_if_else=*index_no_if_else*li[dimension];
            }
fplinguisticmamdaniifelseoutput=fopen("linguistic_mamdani_if else_output.txt","r");

            for (dimension=0;dimension<*no_output;dimension++)
            {
             for (i_lter=0;i_lter<*index_no_if_else;i_lter++)
            {
fscanf(fplinguisticmamdaniifelseoutput,"\n%lf",(*(linguisticoutput_if_else+dimension)+i_lter));
        // fscanf(fpRB,"\n%lf",linguistic_term_output[dimension][i_lter]);
      //printf("\t%s",linguistic_term_output[i_lter]);

            }
            //printf("\n");
            }

fclose(fplinguisticmamdaniifelseoutput);



fplinguisticrangemamdaniinput_min=fopen("linguistic_range_mamdani_input_min.txt","r");

for (dimension=0;dimension<*no_input;dimension++)
            {
             for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdaniinput_min,"%lf",(*(linguistic_range_input_min+dimension)+i_lter));
     // printf("%s\t",linguistic_term_input[i_lter]);

            }

            }

fclose(fplinguisticrangemamdaniinput_min);







fplinguisticrangemamdaniinput_max=fopen("linguistic_range_mamdani_input_max.txt","r");

for (dimension=0;dimension<*no_input;dimension++)
            {

           for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdaniinput_max,"%lf",(*(linguistic_range_input_max+dimension)+i_lter));
     // printf("%s\t",linguistic_term_input[i_lter]);

            }
            }

fclose(fplinguisticrangemamdaniinput_max);









fplinguisticrangemamdanioutput_min=fopen("linguistic_range_mamdani_output_min.txt","r");

for (dimension=0;dimension<*no_output;dimension++)
            {
             for (i_lter=0;i_lter<lo[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdanioutput_min,"%lf",(*(linguistic_range_output_min+dimension)+i_lter));
     // printf("%s\t",linguistic_term_input[i_lter]);

            }

            }

fclose(fplinguisticrangemamdanioutput_min);







fplinguisticrangemamdanioutput_max=fopen("linguistic_range_mamdani_output_max.txt","r");

for (dimension=0;dimension<*no_output;dimension++)
            {

           for (i_lter=0;i_lter<lo[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdanioutput_max,"%lf",(*(linguistic_range_output_max+dimension)+i_lter));
     // printf("%s\t",linguistic_term_input[i_lter]);

            }
            }

fclose(fplinguisticrangemamdanioutput_max);

}


void  centroid_under_curve(int *index_output_linguistic[],int *i_lterni,double *centroid[],double *y_upper[],double *start[],double *end[],int *lo,int *no_output,double *i_inp,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *linguistic_range_output_min[],double *linguistic_range_output_max[])
{
     int i_lter,dimension,ii_index;
  for (dimension=0;dimension<*no_output;dimension++)
            {
                         for (ii_index=0;ii_index<*i_lterni;ii_index++)
      {
                 if(index_output_linguistic[dimension][ii_index]==0)
                {
                start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]];
                end[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index]);
 centroid[dimension][ii_index]=(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])/4;
      }



      else if(index_output_linguistic[dimension][ii_index]==lo[dimension]-1)
                {

              start[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]-(linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index]);
                end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]];
 centroid[dimension][ii_index]=0.25*(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]);
                }
                else
                {


                start[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])-0.5*(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index]);
end[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])+0.5*(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index]);

             centroid[dimension][ii_index]=0.25*(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]);

              }

      }
            }


}


//void  area_under_curve(double *area[],double *y_upper[],double *start[],double *end[],int *lo,int *no_output,double *i_inp,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *linguistic_range_output_min[],double *linguistic_range_output_max[])
//{
//      int i_lter,dimension;
//    for (dimension=0;dimension<*no_output;dimension++)
//            {
//start[dimension][0]=linguistic_range_output_min[dimension][0];
//        end[dimension][0]=linguistic_range_output_max[dimension][0];
//         // small_start[dimension][i_lter]=0.5*(linguistic_range_output_min[dimension][i_lter]+linguistic_range_output_max[dimension][i_lter]);
//         //small_end[dimension][i_lter]=small_start[dimension][i_lter]+(1-y_upper[dimension][i_lter])*(linguistic_range_output_max[dimension][i_lter]-0.5*(linguistic_range_output_max[dimension][i_lter]+linguistic_range_output_min[dimension][i_lter]));
//
//
//area[dimension][0]=fabs((1/(start[dimension][0]-end[dimension][0]))*(0.5*(end[dimension][0]*end[dimension][0]-start[dimension][0]*start[dimension][0])-end[dimension][0]*(end[dimension][0]-start[dimension][0])));
//
//area[dimension][0]=(area[dimension][0]-(1-y_upper[dimension][0])*(1-y_upper[dimension][0])*area[dimension][0]);
////y
//            for (i_lter=1;i_lter<lo[dimension]-1;i_lter++)
//            {
//  start[dimension][i_lter]=0.5*(linguistic_range_output_min[dimension][i_lter]+linguistic_range_output_max[dimension][i_lter]);
//        end[dimension][i_lter]=linguistic_range_output_max[dimension][i_lter];
//         // small_start[dimension][i_lter]=0.5*(linguistic_range_output_min[dimension][i_lter]+linguistic_range_output_max[dimension][i_lter]);
//         //small_end[dimension][i_lter]=small_start[dimension][i_lter]+(1-y_upper[dimension][i_lter])*(linguistic_range_output_max[dimension][i_lter]-0.5*(linguistic_range_output_max[dimension][i_lter]+linguistic_range_output_min[dimension][i_lter]));
//
//
//area[dimension][i_lter]=fabs((1/(start[dimension][i_lter]-end[dimension][i_lter]))*(0.5*(end[dimension][i_lter]*end[dimension][i_lter]-start[dimension][i_lter]*start[dimension][i_lter])-end[dimension][i_lter]*(end[dimension][i_lter]-start[dimension][i_lter])));
//
//area[dimension][i_lter]=2*(area[dimension][i_lter]-(1-y_upper[dimension][i_lter])*(1-y_upper[dimension][i_lter])*area[dimension][i_lter]);
////y_upper[dimension][i_lter]*(small_end[dimension][i_lter]-small_start[dimension][i_lter])+(1-y_upper[dimension][i_lter])*(1/(small_start[dimension][i_lter]-small_end[dimension][i_lter]))*(0.5*(small_end[dimension][i_lter]*small_end[dimension][i_lter]-small_start[dimension][i_lter]*small_start[dimension][i_lter])-small_end[dimension][i_lter]*(small_end[dimension][i_lter]-small_start[dimension][i_lter]));
//
//
//          }
//
//
//
//          start[dimension][lo[dimension]-1]=linguistic_range_output_min[dimension][lo[dimension]-1];
//        end[dimension][lo[dimension]-1]=linguistic_range_output_max[dimension][lo[dimension]-1];
//         // small_start[dimension][i_lter]=0.5*(linguistic_range_output_min[dimension][i_lter]+linguistic_range_output_max[dimension][i_lter]);
//         //small_end[dimension][i_lter]=small_start[dimension][i_lter]+(1-y_upper[dimension][i_lter])*(linguistic_range_output_max[dimension][i_lter]-0.5*(linguistic_range_output_max[dimension][i_lter]+linguistic_range_output_min[dimension][i_lter]));
//
//
//area[dimension][lo[dimension]-1]=fabs((1/(start[dimension][lo[dimension]-1]-end[dimension][lo[dimension]-1]))*(0.5*(end[dimension][lo[dimension]-1]*end[dimension][lo[dimension]-1]-start[dimension][lo[dimension]-1]*start[dimension][lo[dimension]-1])-end[dimension][lo[dimension]-1]*(end[dimension][lo[dimension]-1]-start[dimension][lo[dimension]-1])));
//
//area[dimension][lo[dimension]-1]=(area[dimension][lo[dimension]-1]-(1-y_upper[dimension][lo[dimension]-1])*(1-y_upper[dimension][lo[dimension]-1])*area[dimension][lo[dimension]-1]);
////y
//
//
//
//
//
//
//
//
//              }
//}
//








void  area_under_curve(int *index_output_linguistic[],int *i_lterni,double *area[],double *y_upper[],double *start[],double *end[],int *lo,int *no_output,double *i_inp,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *linguistic_range_output_min[],double *linguistic_range_output_max[])
{
      int i_lter,dimension,ii_index;
    for (dimension=0;dimension<*no_output;dimension++)
            {
          for (ii_index=0;ii_index<*i_lterni;ii_index++)
      {
                if(index_output_linguistic[dimension][ii_index]==0)
                {
                  start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]];
        end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]];
         // small_start[dimension][i_lter]=0.5*(linguistic_range_output_min[dimension][i_lter]+linguistic_range_output_max[dimension][i_lter]);
         //small_end[dimension][i_lter]=small_start[dimension][i_lter]+(1-y_upper[dimension][i_lter])*(linguistic_range_output_max[dimension][i_lter]-0.5*(linguistic_range_output_max[dimension][i_lter]+linguistic_range_output_min[dimension][i_lter]));


area[dimension][ii_index]=fabs((1/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][0]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])));

area[dimension][ii_index]=(area[dimension][ii_index]-(1-y_upper[dimension][ii_index])*(1-y_upper[dimension][ii_index])*area[dimension][ii_index]);
//
                }


     else if(index_output_linguistic[dimension][ii_index]==lo[dimension]-1)
                {

          start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]];
        end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]];
         // small_start[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][ii_index]+linguistic_range_output_max[dimension][ii_index]);
         //small_end[dimension][ii_index]=small_start[dimension][ii_index]+(1-y_upper[dimension][ii_index])*(linguistic_range_output_max[dimension][ii_index]-0.5*(linguistic_range_output_max[dimension][ii_index]+linguistic_range_output_min[dimension][ii_index]));


area[dimension][ii_index]=fabs((1/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][ii_index]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])));

area[dimension][ii_index]=(area[dimension][ii_index]-(1-y_upper[dimension][ii_index])*(1-y_upper[dimension][ii_index])*area[dimension][ii_index]);

                }

            else
            {
  start[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]);
        end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]];
         // small_start[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][ii_index]+linguistic_range_output_max[dimension][ii_index]);
         //small_end[dimension][ii_index]=small_start[dimension][ii_index]+(1-y_upper[dimension][ii_index])*(linguistic_range_output_max[dimension][ii_index]-0.5*(linguistic_range_output_max[dimension][ii_index]+linguistic_range_output_min[dimension][ii_index]));


area[dimension][ii_index]=fabs((1/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][ii_index]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])));

area[dimension][ii_index]=2*(area[dimension][ii_index]-(1-y_upper[dimension][ii_index])*(1-y_upper[dimension][ii_index])*area[dimension][ii_index]);
//y_upper[dimension][ii_index]*(small_end[dimension][ii_index]-small_start[dimension][ii_index])+(1-y_upper[dimension][ii_index])*(1/(small_start[dimension][ii_index]-small_end[dimension][ii_index]))*(0.5*(small_end[dimension][ii_index]*small_end[dimension][ii_index]-small_start[dimension][ii_index]*small_start[dimension][ii_index])-small_end[dimension][ii_index]*(small_end[dimension][ii_index]-small_start[dimension][ii_index]));


          }



}




              }
}




















void  membership_function(double *membership_function_value[],int *ii,int *linguistic_number[],int *li,int *no_input,double *i_inp,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *linguistic_range_output_min[],double *linguistic_range_output_max[])

{
    int i_lter,dimension;

    for (dimension=0;dimension<*no_input;dimension++)
           {
               membership_function_value[dimension][0]=1-((i_inp[dimension]-linguistic_range_input_min[dimension][0])/(linguistic_range_input_max[dimension][0]-linguistic_range_input_min[dimension][0]));
        for (i_lter=1;i_lter<li[dimension]-1;i_lter++)
        {
membership_function_value[dimension][i_lter]=max(min(((i_inp[dimension]-linguistic_range_input_min[dimension][i_lter])/((0.5*(linguistic_range_input_max[dimension][i_lter]+linguistic_range_input_min[dimension][i_lter]))-linguistic_range_input_min[dimension][i_lter])),((linguistic_range_input_max[dimension][i_lter]-i_inp[dimension])/(linguistic_range_input_max[dimension][i_lter]-(0.5*(linguistic_range_input_max[dimension][i_lter]+linguistic_range_input_min[dimension][i_lter]))))),0);
        }


           }
membership_function_value[dimension][li[dimension]-1]=1-((linguistic_range_input_max[dimension][li[dimension]-1]-i_inp[dimension])/(linguistic_range_input_max[dimension][li[dimension]-1]-linguistic_range_input_min[dimension][li[dimension]-1]));


}



void  data_base(int *ii,int *linguistic_number[],int *li,int *no_input,double *i_inp,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *linguistic_range_output_min[],double *linguistic_range_output_max[])

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




void rule_base(int *i_ltern,int *in_indext,int *li,int *lo,double *linguisticinput1[],double *linguisticinput[],double *linguisticoutput1[],double *linguisticoutput_if_else[],int *ii,int *ln[],int *i_lternt,double *linguisticoutput[],int *index_output_linguistic[],int *no_output)
{

int i_lter,i_lter1,i_lter2,i_lter3,dimension,ii_index;


    *i_ltern=0;
          for (i_lter2=0;i_lter2<ii[0];i_lter2++)
        {

                       for (i_lter3=0;i_lter3<ii[1];i_lter3++)
        {


*i_lternt=0;
                  for (i_lter=0;i_lter<li[0];i_lter++)
        {

                       for (i_lter1=0;i_lter1<li[1];i_lter1++)
        {

*in_indext=*i_lternt;
*i_lternt=*i_lternt+1;
if((linguisticinput1[0][ln[0][i_lter2]]==linguisticinput[0][i_lter])&&(linguisticinput1[1][ln[1][i_lter3]]==linguisticinput[1][i_lter1]))
{





linguisticoutput1[0][*i_ltern]=linguisticoutput_if_else[0][*in_indext];





    *i_ltern=*i_ltern+1;
                }



        }
        }
        }
        }



        for (dimension=0;dimension<*no_output;dimension++)
        {

     for (ii_index=0;ii_index<*i_ltern;ii_index++)
      {

         for (i_lter=0;i_lter<lo[0];i_lter++)
            {



            if(linguisticoutput1[0][ii_index]==linguisticoutput[0][i_lter])
            {
                index_output_linguistic[0][ii_index]=i_lter;
            }


            }
//printf("\n%d", index_output_linguistic[dimension][ii_index]);
      }

        }













}

main()
{
    FILE *fpRB,*fpnolinguistic,*fplinguistic,*fpinput,*fpFZCM,*fpsee,*fpsee1,*fpsee2,*fprange,*fpoutput;
    int i_lter,trainingscenario,no_trainingscenario,dimension,no_input,no_output,i_index,dimension1,i_index1,dimension2,iteration,i_linguistic,*linguistic_input,*linguistic_output,*ii,index_no_if_else,i_lter1,i_flag;
   int in_index,iii,itest1,itest2,output_index1,i_lternt,in_indext,ii_index,*index_output_linguistic[DIMENSION_max],jjj,iii_index,*jj;//,*linguistic_number[TRAINING_DATA_max];


   double *linguisticinput[DIMENSION_max],*linguisticoutput[DIMENSION_max],*linguisticoutput1[DIMENSION_max],*linguisticinput1[DIMENSION_max],*y_upper[DIMENSION_max],*area[DIMENSION_max],*start[DIMENSION_max],*end[DIMENSION_max],*alpha[DIMENSION_max],*centroid[DIMENSION_max];
    double *linguistic_term_input[DIMENSION_max],*linguistic_term_output[DIMENSION_max],*membership_function_value_input[DIMENSION_max],*LCM,*HCF,*crisp_output,*sum_LCM,*sum_HCF;
   double *linguistic_range_input_min[DIMENSION_max],*linguistic_range_input_max[DIMENSION_max],*linguistic_range_output_min[DIMENSION_max],*linguistic_range_output_max[DIMENSION_max],*linguisticoutput_if_else[DIMENSION_max];
    double criteria,*i_inp,*o_oup,* membership_matrix,*randnum,minfp,gbest_location,*min_input,*max_input,*min_output,*max_output,*AA[DIMENSION_max],*BB[DIMENSION_max],*EuD[DIMENSION_max],* membership_matrix_update,*diff_membership_matrix;
int inti_ltern,i_lterni;
int i_lter2,i_lter3,*linguistic_number[DIMENSION_max];

linguistic_input= (int *) malloc(	DIMENSION_max * sizeof(int));
linguistic_output= (int *) malloc(	DIMENSION_max * sizeof(int));
min_input= (double *) malloc(	DIMENSION_max * sizeof(double));
max_input= (double *) malloc(	DIMENSION_max * sizeof(double));

min_output= (double *) malloc(	DIMENSION_max * sizeof(double));
max_output= (double *) malloc(	DIMENSION_max * sizeof(double));

sum_LCM= (double *) malloc(	DIMENSION_max * sizeof(double));
sum_HCF= (double *) malloc(	DIMENSION_max * sizeof(double));

LCM= (double *) malloc(	DIMENSION_max * sizeof(double));
HCF= (double *) malloc(	DIMENSION_max * sizeof(double));

crisp_output= (double *) malloc(DIMENSION_max * sizeof(double));

 ii= (int *) malloc(	DIMENSION_max  * sizeof(int));

jj= (int *) malloc(	DIMENSION_max  * sizeof(int));
   fpFZCM=fopen("Fuzzy_MAMDANI.txt","r");

   fscanf(fpFZCM,"%d\n%d",&no_input,&no_output);
fclose(fpFZCM);




    i_inp=(double *) malloc(DIMENSION_max * sizeof(double));
    o_oup=(double *) malloc(DIMENSION_max * sizeof(double));





     for (i_index=0;i_index<(no_input+no_output);i_index++)
    {
       linguistic_number[i_index]=(int*) malloc(LINGUISTIC_max  * sizeof(int));

index_output_linguistic[i_index]=(int*) malloc(LINGUISTIC_max  * sizeof(int));

    membership_function_value_input[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
       linguisticinput[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
         linguisticinput1[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
              linguisticoutput[i_index]= (double *) malloc(	LINGUISTIC_max * sizeof(double ));
              linguisticoutput1[i_index]= (double *) malloc(	LINGUISTIC_max * sizeof(double ));
              linguisticoutput_if_else[i_index]=(double *) malloc(	LINGUISTIC_max * sizeof(double ));


              linguistic_range_input_min[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
              linguistic_range_input_max[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
                  linguistic_range_output_min[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
              linguistic_range_output_max[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));

              area[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
                  centroid[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
              y_upper[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
                   start[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
                   end[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));
                   alpha[i_index]= (double *) malloc(	LINGUISTIC_max  * sizeof(double ));


}


file_management(i_inp,&index_no_if_else,linguisticinput,linguisticoutput,linguisticoutput_if_else,linguistic_input,linguistic_output,&no_input,&no_output,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max);
//file_management(i_inp,index_no_if_else,linguisticinput,linguisticoutput,linguisticoutput_if_else,linguistic_input,linguistic_output,&no_input,&no_output,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max);
//file_management(i_inp,index_no_if_else,linguisticinput[],double *linguisticoutput[],double *linguisticoutput_if_else[],int *li,int *lo,int *no_input,int *no_output,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *linguistic_range_output_min[],double *linguistic_range_output_max[])

for (dimension=0;dimension<no_input;dimension++)
          {
         for (i_lter=0;i_lter<linguistic_input[dimension];i_lter++)
            {

          printf("%lf\t\t%lf\n",linguistic_range_input_min[dimension][i_lter],linguistic_range_input_max[dimension][i_lter]);

            }

             printf("\n");
            }
  printf("\n");
for (dimension=0;dimension<no_output;dimension++)
          {

         for (i_lter=0;i_lter<linguistic_output[dimension];i_lter++)
            {

          printf("%lf\t\t%lf\n",linguistic_range_output_min[dimension][i_lter],linguistic_range_output_max[dimension][i_lter]);

            }

             printf("\n");
            }
  printf("\n");



data_base(ii,linguistic_number,linguistic_input,&no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max);



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

                linguisticinput1[dimension][linguistic_number[dimension][iii]]=linguisticinput[dimension][linguistic_number[dimension][iii]];

            }
          }

    printf("\n");





rule_base(&i_lterni,&in_indext,linguistic_input,linguistic_output,linguisticinput1,linguisticinput,linguisticoutput1,linguisticoutput_if_else,ii,linguistic_number,&i_lternt,linguisticoutput,index_output_linguistic,&no_output);
 printf("\n%d",i_lterni);
 for (ii_index=0;ii_index<i_lterni;ii_index++)
      {
printf("\n%lf",linguisticoutput1[0][ii_index]);
        }


 printf("\n");




membership_function(membership_function_value_input,ii,linguistic_number,linguistic_input,&no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max);


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
alpha[0][iii_index]=min(membership_function_value_input[dimension][linguistic_number[dimension][iii]],membership_function_value_input[dimension1][linguistic_number[dimension1][jjj]]);
   printf("\n%lf",alpha[0][iii_index]);
iii_index=iii_index+1;

            }
            }
            }
            }

area_under_curve(index_output_linguistic,&i_lterni,area,alpha,start,end,linguistic_output,&no_output,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max);
printf("\n");

for (dimension=0;dimension<no_output;dimension++)
        {
       for (iii=0;iii<i_lterni;iii++)
      {
printf("\n%lf",area[dimension][iii]);

          }
         }

centroid_under_curve(index_output_linguistic,&i_lterni,centroid,alpha,start,end,linguistic_output,&no_output,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max);
 printf("\n");
for (dimension=0;dimension<no_output;dimension++)
        {
               for (iii=0;iii<i_lterni;iii++)
            {
printf("\n%lf",centroid[dimension][iii]);

            }
        }




        for (dimension=0;dimension<no_output;dimension++)
        {

                LCM[dimension]=0;
          HCF[dimension]=0;
              for (iii=0;iii<i_lterni;iii++)
            {
   LCM[dimension]=LCM[dimension]+area[dimension][iii]*centroid[dimension][iii];
     HCF[dimension]=HCF[dimension]+area[dimension][iii];
     crisp_output[dimension]=LCM[dimension]/HCF[dimension];
            }
         printf("\n%lf",crisp_output[dimension]);
        }

}
