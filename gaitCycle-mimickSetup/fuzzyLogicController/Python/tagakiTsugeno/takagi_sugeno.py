#import time
#import math

#DIMENSION_max = 20
#LINGUISTIC_max = 20 # Max swarm size
#PI =  3.141592769
#g_fcm = 1.25
#eta = 0.01

#file management to be takn care of
li = [3,3]
#lo = [5,5,5]
i_inp = [6, 2.2]
linguisticinput = [[-1,0,1],[-1,0,1]]
coefficient = [[3,4,5],[3,4,5]]
#linguisticoutput_if_else = [[0,1,-1,-1,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0],[0,1,-1,-1,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0],[0,1,-1,-1,0,0,0,2,0,0,0,0,1,0,0,0,0,0,0,0]]
#[[0],[1],[-1],[-1],[0],[0],[0],[2],[0],[0],[0],[0],[1],[0],[0],[0],[0],[0],[0],[0]]
linguistic_range_input_min = [[5,5,10],[1,1,2]]
linguistic_range_input_max = [[10,15,15],[2,3,3]]
#linguistic_range_output_min = [[-90,-90,-45,0,45],[-90,-90,-45,0,45],[-90,-90,-45,0,45]]
#linguistic_range_output_max = [[-45,0,45,90,90],[-45,0,45,90,90],[-45,0,45,90,90]]

def multiply(num1,num2) :
     
    # Multiply elements one by one

    result = num1 * num2
    return result 
#def centroid_under_curve(index_output_linguistic,i_lterni,centroid,y_upper,start,end,lo,no_output,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max):
##    i_lter = 0
##    dimension = 0
##    ii_index=0
#    for dimension in range(no_output):
#        for ii_index in range(i_lterni):
#            if  index_output_linguistic[dimension][ii_index] == 0:
#                start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]
#                end[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index])
#                centroid[dimension][ii_index]=(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])/4
#            elif index_output_linguistic[dimension][ii_index]==lo[dimension]-1:
#                 start[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]-(linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index])
#                 end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]
#                 centroid[dimension][ii_index]=0.25*(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])
#            else:
#                start[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])-0.5*(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index])
#                end[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])+0.5*(-linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])*(1-y_upper[dimension][ii_index])
#                centroid[dimension][ii_index]=0.25*(start[dimension][ii_index]+end[dimension][ii_index]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]])
#    return (centroid,index_output_linguistic)
#def area_under_curve(index_output_linguistic,i_lterni,area,y_upper,start,end,lo,no_output,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max):
#    #i_lter=0
#   # dimension=0
#   # ii_index=0;
#    for dimension in range(no_output):
#        for ii_index in range(i_lterni):
#            if index_output_linguistic[dimension][ii_index]==0:
#               start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]
#               end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]
#               area[dimension][ii_index]=abs((1.0/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][ii_index]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])))
#               area[dimension][ii_index]=(area[dimension][ii_index]-(1.0-y_upper[dimension][ii_index])*(1.0-y_upper[dimension][ii_index])*area[dimension][ii_index])
#            
#            elif index_output_linguistic[dimension][ii_index]==lo[dimension]-1:
#                 start[dimension][ii_index]=linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]              
#                 end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]
#                 area[dimension][ii_index]=abs((1.0/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][ii_index]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])))
#                 area[dimension][ii_index]=(area[dimension][ii_index]-(1.0-y_upper[dimension][ii_index])*(1-y_upper[dimension][ii_index])*area[dimension][ii_index])
#                 print("area",y_upper[dimension][ii_index])
#            else:
#                start[dimension][ii_index]=0.5*(linguistic_range_output_min[dimension][index_output_linguistic[dimension][ii_index]]+linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]])
#                end[dimension][ii_index]=linguistic_range_output_max[dimension][index_output_linguistic[dimension][ii_index]]
#                area[dimension][ii_index]=abs((1.0/(start[dimension][ii_index]-end[dimension][ii_index]))*(0.5*(end[dimension][ii_index]*end[dimension][ii_index]-start[dimension][ii_index]*start[dimension][ii_index])-end[dimension][ii_index]*(end[dimension][ii_index]-start[dimension][ii_index])))
#                area[dimension][ii_index]=2.0*(area[dimension][ii_index]-(1.0-y_upper[dimension][ii_index])*(1.0-y_upper[dimension][ii_index])*area[dimension][ii_index])
#    return (area,index_output_linguistic)
def membership_function(membership_function_value,ii,linguistic_number,li,no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max):
    for dimension in range(no_input):
        membership_function_value[dimension][0]=1-((i_inp[dimension]-linguistic_range_input_min[dimension][0])/(linguistic_range_input_max[dimension][0]-linguistic_range_input_min[dimension][0]));
        for i_lter in range(1,(li[dimension]-1)):
            membership_function_value[dimension][i_lter]=max(min(((i_inp[dimension]-linguistic_range_input_min[dimension][i_lter])/((0.5*(linguistic_range_input_max[dimension][i_lter]+linguistic_range_input_min[dimension][i_lter]))-linguistic_range_input_min[dimension][i_lter])),((linguistic_range_input_max[dimension][i_lter]-i_inp[dimension])/(linguistic_range_input_max[dimension][i_lter]-(0.5*(linguistic_range_input_max[dimension][i_lter]+linguistic_range_input_min[dimension][i_lter]))))),0);
        membership_function_value[dimension][li[dimension]-1]=1-((linguistic_range_input_max[dimension][li[dimension]-1]-i_inp[dimension])/(linguistic_range_input_max[dimension][li[dimension]-1]-linguistic_range_input_min[dimension][li[dimension]-1]))
    return (membership_function_value)


def data_base(ii,linguistic_number,li,no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max):

    for dimension in range(no_input):
        ii[dimension]=0
        for i_lter in range(li[dimension]):
            if ((i_inp[dimension]>=linguistic_range_input_min[dimension][i_lter]) and (i_inp[dimension]<=linguistic_range_input_max[dimension][i_lter])):
                linguistic_number[dimension][ii[dimension]]=i_lter
                ii[dimension]=ii[dimension]+1
    return (linguistic_number)


def rule_base(i_ltern,i_inp,li,no_input,linguisticoutput,coefficient,ii,linguistic_number,no_output):
    
    for dimension2 in range(no_output):
        i_ltern=0;
        for dimension in range(no_input-1):
            for iii in range(ii[dimension]):
                for dimension1 in range(1,no_input):
                    for jjj in range(ii[dimension1]):
                        linguisticoutput[dimension2][i_ltern]=coefficient[dimension][linguistic_number[dimension][iii]]*i_inp[dimension]+coefficient[dimension1][linguistic_number[dimension1][jjj]]*i_inp[dimension1]
#                        print("check1",linguisticoutput[dimension2][i_ltern])
                        i_ltern = i_ltern+1
                        
    return (linguisticoutput,i_ltern)
                    

def main():
    no_output = 3
    no_input = 2
#    for dimension in range(no_input):
#       for i_lter in range(li[dimension]):
#            print(linguistic_range_input_min[dimension][i_lter]),
#            print(linguistic_range_input_max[dimension][i_lter])
#        print("\n")
#    print("\n")

    #Definitions
    #inti_ltern =0
    i_lterni=0
   # i_lter2=0
   # i_lternt =0 
    #i_lter3=0
   # in_indext = 0
#    min_input = [1.0]*200
#    max_input = [1.0]*200
#    min_output = [1.0]*200
#    max_output= [1.0]*200
    LCM= [0 for x in range(20)] 
    HCF= [0 for x in range(20)] 
    crisp_output= [0 for x in range(20)] 
    ii= [0 for x in range(20)] 
    #jj= [1.0]*200
#    i_inp= [1.0]*200
    #o_oup= [1.0]*200

    linguistic_number = [[0 for x in range(20)] for y in range(20)]
   # index_output_linguistic =  [[0 for x in range(20)] for y in range(20)]
    membership_function_value_input= [[1.000 for x in range(20)] for y in range(20)]
#  linguistic_input= [[1.000 for x in range(20)] for y in range(20)]
    linguisticoutput= [[1.000 for x in range(20)] for y in range(20)]
    #area= [[1.000 for x in range(20)] for y in range(20)]
    #centroid= [[1.000 for x in range(20)] for y in range(20)]
   # y_upper= [[1.000 for x in range(20)] for y in range(20)]
 #   start=[[1.000 for x in range(20)] for y in range(20)]
 #   end= [[1.000 for x in range(20)] for y in range(20)]
    weight= [[1.000 for x in range(20)] for y in range(20)]






#    for dimension in range(no_output):
#        for i_lter in range(lo[dimension]):
#            print(linguistic_range_output_min[i_lter])
#            print(linguistic_range_output_max[i_lter])
    linguistic_number=data_base(ii,linguistic_number,li,no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max)
#    print("ii",ii)
#    for dimension in range(no_input):
#        for iii in range(ii[dimension]):
#            print("linguisticinput   ",linguisticinput[dimension][linguistic_number[dimension][iii]],dimension,linguistic_number[dimension][iii])
#    for dimension in range(no_input):
#        for iii in range(ii[dimension]):
#            linguisticinput1[dimension][linguistic_number[dimension][iii]]=linguisticinput[dimension][linguistic_number[dimension][iii]]
##            print("linguisticinput  : ",linguisticinput1[dimension][linguistic_number[dimension][iii]])
    linguisticoutput,i_lterni=rule_base(i_lterni,i_inp,li,no_input,linguisticoutput,coefficient,ii,linguistic_number,no_output)
    #for dimension in range(no_output):
        #for i in range(i_lterni):
    #print("check",i_lterni)

    membership_function_value_input=membership_function(membership_function_value_input,ii,linguistic_number,li,no_input,i_inp,linguistic_range_input_min,linguistic_range_input_max)
#    for dimension in range(no_input):
#        for iii in range(ii[dimension]):
#            print(" memeber ",membership_function_value_input[dimension][linguistic_number[dimension][iii]])
#            

    
    for dimension2 in range(no_output):
        iii_index = 0
        for dimension in range(no_input-1):
            for iii in range(ii[dimension]):
                for dimension1 in range(1,no_input):
                     for jjj in range(ii[dimension1]):
                         weight[dimension2][iii_index]=multiply(membership_function_value_input[dimension][linguistic_number[dimension][iii]],membership_function_value_input[dimension1][linguistic_number[dimension1][jjj]])
#                        print("weight", weight[dimension2][iii_index])
                         iii_index=iii_index+1
#    area,index_output_linguistic=area_under_curve(index_output_linguistic,i_lterni,area,alpha,start,end,lo,no_output,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max)
    #for dimension in range(no_output):
      # for iii in range(i_lterni):
#            print("area",area[dimension][iii])
#    centroid,index_output_linguistic=centroid_under_curve(index_output_linguistic,i_lterni,centroid,alpha,start,end,lo,no_output,i_inp,linguistic_range_input_min,linguistic_range_input_max,linguistic_range_output_min,linguistic_range_output_max)
  #  for dimension in range(no_output):
     #   for iii in range(i_lterni):
#            print("centroid",centroid[dimension][iii])
    for dimension in range(no_output):
        LCM[dimension]=0
        HCF[dimension]=0
        for iii in range(i_lterni):
            LCM[dimension]=LCM[dimension]+weight[dimension][iii]*linguisticoutput[dimension][iii]
            HCF[dimension]=HCF[dimension]+weight[dimension][iii]
            crisp_output[dimension]=LCM[dimension]/HCF[dimension]
        print("crisp output ",crisp_output[dimension])

if __name__=="__main__":
    main()
