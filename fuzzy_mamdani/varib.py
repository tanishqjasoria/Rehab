def printMat(A):
    print('\n'.join([''.join(['{:4}'.format(item) for item in row]) for row in A]))

li = [4,5]
lo = [5]
i_inp = [1.04 ,30]
linguisticinput = [[-2,-1,1,2],[-2,-1,0,1,2]]
linguisticoutput = [-2,-1,0,1,2]
linguisticoutput_if_else = [[0],[1],[-1],[-1],[0],[0],[0],[2],[0],[0],[0],[0],[1],[0],[0],[0],[0],[0],[0],[0]]
linguistic_range_input_min = [[0.1,0.1,0.8,1.5],[-90,-90,-45,0,45]]
linguistic_range_input_max = [[0.8,1.5,2.2,2.2],[-45,0,45,90,90]]
linguistic_range_output_min = [-90,-90,-45,0,-45]
linguistic_range_output_max = [-45,0,45,90,90]

printMat(linguisticinput)
#printMat(linguisticoutput])
printMat(linguisticoutput_if_else)
printMat(linguistic_range_input_min)
printMat(linguistic_range_input_max)
printMat(linguistic_range_output_min)
printMat(linguistic_range_output_max)
