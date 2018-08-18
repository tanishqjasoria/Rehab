import time

DIMENSION_max = 200
LINGUISTIC_max = 200 # Max swarm size
PI =  3.1415927
g_fcm = 1.25
eta = 0.01

#file management to be takn care of
def  file_management(i_inp,int *index_no_if_else,double *linguisticinput[],double *linguisticoutput[],double *linguisticoutput_if_else[],int *li,int *lo,int *no_input,int *no_output,double *linguistic_range_input_min[],double *linguistic_range_input_max[],double *linguistic_range_output_min[],double *linguistic_range_output_max[])
{
FILE *   fpinput,*fplinguisticmamdaniifelseoutput,*fplinguisticmamdaniinput,*fplinguisticmamdanioutput,*fplinguisticnoinput,*fplinguisticnooutput,*fplinguistictermmamdaniinput,*fplinguistictermmamdanioutput,*fplinguisticrangemamdaniinput_min,*fplinguisticrangemamdaniinput_max,*fplinguisticrangemamdanioutput_min,*fplinguisticrangemamdanioutput_max,*fplinguisticrangemamdanioutput;
int i_lter,dimension,trainingscenario;
fplinguisticnoinput=open("mamdani_linguistic_no_input.txt","r");
for (dimension=0;dimension<*no_input;dimension++)
            {
 fscanf(fplinguisticnoinput,"%d",&li[dimension]);
            }

             fclose(fplinguisticnoinput);
# li = [4,5]
            fplinguisticnooutput=open("mamdani_linguistic_no_output.txt","r");
            for (dimension=0;dimension<*no_output;dimension++)
            {
 fscanf(fplinguisticnooutput,"%d",&lo[dimension]);
            }
 fclose(fplinguisticnooutput);
# lo = [5]
   fpinput=open("input_mamdani.txt","r");


            for (dimension=0;dimension<*no_input;dimension++)
            {

                fscanf(fpinput,"%lf",&i_inp[dimension]);
            }

    fclose(fpinput);
#i_inp = [1.04,30]
fplinguisticmamdaniinput=open("linguistic_mamdani_input.txt","r");

for (dimension=0;dimension<*no_input;dimension++)
            {
             for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticmamdaniinput,"%lf",(*(linguisticinput+dimension)+i_lter));

            }
            }

fclose(fplinguisticmamdaniinput);
fplinguisticmamdanioutput=open("linguistic_mamdani_output.txt","r");

            for (dimension=0;dimension<*no_output;dimension++)
            {
             for (i_lter=0;i_lter<lo[dimension];i_lter++)
            {
fscanf(fplinguisticmamdanioutput,"\n%lf",(*(linguisticoutput+dimension)+i_lter));

            }
            }

fclose(fplinguisticmamdanioutput);

*index_no_if_else=1;
for (dimension=0;dimension<*no_input;dimension++)
            {

*index_no_if_else=*index_no_if_else*li[dimension];
            }
fplinguisticmamdaniifelseoutput=open("linguistic_mamdani_if else_output.txt","r");

            for (dimension=0;dimension<*no_output;dimension++)
            {
             for (i_lter=0;i_lter<*index_no_if_else;i_lter++)
            {
fscanf(fplinguisticmamdaniifelseoutput,"\n%lf",(*(linguisticoutput_if_else+dimension)+i_lter));

            }
            }

fclose(fplinguisticmamdaniifelseoutput);
fplinguisticrangemamdaniinput_min=open("linguistic_range_mamdani_input_min.txt","r");
for (dimension=0;dimension<*no_input;dimension++)
            {
             for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdaniinput_min,"%lf",(*(linguistic_range_input_min+dimension)+i_lter));

            }

            }

fclose(fplinguisticrangemamdaniinput_min);
fplinguisticrangemamdaniinput_max=open("linguistic_range_mamdani_input_max.txt","r");

for (dimension=0;dimension<*no_input;dimension++)
            {

           for (i_lter=0;i_lter<li[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdaniinput_max,"%lf",(*(linguistic_range_input_max+dimension)+i_lter));

            }
            }

fclose(fplinguisticrangemamdaniinput_max);
fplinguisticrangemamdanioutput_min=open("linguistic_range_mamdani_output_min.txt","r");

for (dimension=0;dimension<*no_output;dimension++)
            {
             for (i_lter=0;i_lter<lo[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdanioutput_min,"%lf",(*(linguistic_range_output_min+dimension)+i_lter));

            }

            }

fclose(fplinguisticrangemamdanioutput_min);
fplinguisticrangemamdanioutput_max=open("linguistic_range_mamdani_output_max.txt","r");

for (dimension=0;dimension<*no_output;dimension++)
            {

           for (i_lter=0;i_lter<lo[dimension];i_lter++)
            {

         fscanf(fplinguisticrangemamdanioutput_max,"%lf",(*(linguistic_range_output_max+dimension)+i_lter));

            }
            }

fclose(fplinguisticrangemamdanioutput_max);

}
















def centroid_under_curve(index_output_linguistic,i_lterni,centroid,y_upper,start,end,lo,no_output,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max):
    i_lter = 0
    dimension = 0
    ii_index=0
    for dimension in range(no_output):
        for ii_index in range(i_lterni):
            if index_output_linguistic[dimension][ii_index] == 0:
                start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]
                end[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index])
                centroid[dimension][ii_index]=(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])/4
            elif index_output_linguistic[dimension][ii_index]==lo[dimension]-1:
                start[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]-(linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index])
                end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]
                centroid[dimension][ii_index]=0.25*(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])
            else:
                start[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])-0.5*(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index])
                end[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])+0.5*(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index])
                centroid[dimension][ii_index]=0.25*(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]])

def area_under_curve(index_output_linguistic,i_lterni,area,y_upper,start,end,lo,no_output,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max):
    i_lter=0
    dimension=0
    ii_index=0;
    for dimension in range(no_output):
        for ii_index in range(i_lterni):
            if index_output_linguistic[dimension][ii_index]==0:
                start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]
                end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]
                area[dimension][ii_index]=fabs((1/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][0]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])))
                area[dimension][ii_index]=(area[dimension][ii_index]-(1-y_upper[dimension][ii_index])*(1-y_upper[dimension][ii_index])*area[dimension][ii_index])
            elif index_output_linguistic[dimension][ii_index]==lo[dimension]-1:
                start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]
                end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]
                area[dimension][ii_index]=fabs((1/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][ii_index]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])))
                area[dimension][ii_index]=(area[dimension][ii_index]-(1-y_upper[dimension][ii_index])*(1-y_upper[dimension][ii_index])*area[dimension][ii_index])
            else:
                start[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])
                end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]
                area[dimension][ii_index]=fabs((1/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][ii_index]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])))
                area[dimension][ii_index]=2*(area[dimension][ii_index]-(1-y_upper[dimension][ii_index])*(1-y_upper[dimension][ii_index])*area[dimension][ii_index])

def membership_function(membership_function_value,ii,linguistic_number,li,no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max):
    i_lter=0
    dimension=0
    for dimension in range(no_input):
        membership_function_value[dimension][0]=1-((i_inp[dimension]-linguistic_range_input_min[dimension][0])/(linguistic_range_input_max[dimension][0]-linguistic_range_input_min[dimension][0]));
        for i_lter in range(li[dimension]-1):
            membership_function_value[dimension][i_lter]=max(min(((i_inp[dimension]-linguistic_range_input_min[dimension][i_lter])/((0.5*(linguistic_range_input_max[dimension][i_lter]+linguistic_range_input_min[dimension][i_lter]))-linguistic_range_input_min[dimension][i_lter])),((linguistic_range_input_max[dimension][i_lter]-i_inp[dimension])/(linguistic_range_input_max[dimension][i_lter]-(0.5*(linguistic_range_input_max[dimension][i_lter]+linguistic_range_input_min[dimension][i_lter]))))),0);
    membership_function_value[dimension][li[dimension]-1]=1-((linguistic_range_input_max[dimension][li[dimension]-1]-i_inp[dimension])/(linguistic_range_input_max[dimension][li[dimension]-1]-linguistic_range_input_min[dimension][li[dimension]-1]));

def data_base(ii,linguistic_number,li,no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max, linguistic_range_output_min,linguistic_range_output_max):
    i_lter = 0
    dimension = 0
    for dimension in range(no_input):
        ii[dimension]=0;
        for i_lter in range(li[dimension]):
            if ((i_inp[dimension]>=linguistic_range_input_min[dimension][i_lter]) && (i_inp[dimension]<=linguistic_range_input_max[dimension][i_lter])):
                linguistic_number[dimension][ii[dimension]]=i_lter;
                ii[dimension]=ii[dimension]+1;


def rule_base(i_ltern,in_indext,li,lo,linguisticinput1,linguisticinput,linguisticoutput1,linguisticoutput_if_else,ii,ln, i_lternt,linguisticoutput,index_output_linguistic,no_output):
    i_lter=0
    i_lter1=0
    i_lter2=0
    i_lter3=0
    dimension=0
    ii_index=0
    i_ltern=0;
    for i_lter2 in range(ii[0]):
        for i_lter3 in range(ii[1]):
            i_lternt = 0
            for i_lter in range(li[0]):
                for i_lter1 in range(li[1]):
                    in_indext=i_lternt
                    i_lternt=i_lternt+1
                    if ((linguisticinput1[0][ln[0][i_lter2]]==linguisticinput[0][i_lter])&&(linguisticinput1[1][ln[1][i_lter3]]==linguisticinput[1][i_lter1])):
                        linguisticoutput1[0][i_ltern]=linguisticoutput_if_else[0][in_indext]
                        i_ltern = i_ltern+
    for dimension in range(no_output):
        for ii_index in range(i_ltern):
            for i_lter in range(lo[0]):
                if (linguisticoutput1[0][ii_index]==linguisticoutput[0][i_lter]):
                    index_output_linguistic[0][ii_index]=i_lter

def main():
    for dimension in range(no_input):
        for i_lter in range(linguistic_input[dimension]):
            print("%lf\t\t%lf\n",linguistic_range_input_min[dimension][i_lter],linguistic_range_input_max[dimension][i_lter])
        print("\n")
    print("\n")
    for dimension in range(no_output):
        for i_lter in range(linguistic_output[dimension]):
            print("%lf\t\t%lf\n",linguistic_range_output_min[dimension][i_lter],linguistic_range_output_max[dimension][i_lter])
        print("\n")
    print("\n")
