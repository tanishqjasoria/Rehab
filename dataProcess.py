import numpy as np
import math
def process34(person):
    file = "C:/Users/tanishqjasoria/Documents/Github/Rehab/gaitCycle-data/"+person+"/test_data34.txt"
    f = open(file)
    lines = []
    time = []
    pitch = []
    roll = []
    gyro = []
    force = []
    load = []
    force_temp =[]
    gyro_temp = []
    load_temp = []
    beta = 0.9
    for line in f:
        lines.append(line) 
    for elem in lines:
        if elem == '\n':
            lines.remove('\n')
    for i in range(5):
        lines.pop(0)
        lines.pop()
    for line in lines:
        a = line.split("=")
        load_temp  = []
        gyro_temp  = []
        force_temp = []
        time.append((a[1].split(" "))[0].strip())
        pitch.append((a[2].split(" "))[0].strip())
        roll.append((a[3].split(" "))[0].strip())
        gyro_temp.append((a[4].split(" "))[0].strip())
        gyro_temp.append((a[5].split(" "))[0].strip())
        gyro_temp.append((a[6].split(" "))[0].strip())
        gyro.append(gyro_temp)
        force_temp.append((a[7].split(" "))[0].strip())
        force_temp.append((a[8].split(" "))[0].strip())
        force_temp.append((a[9].split(" "))[0].strip())
        force_temp.append((a[10].split(" "))[0].strip())
        force_temp.append((a[11].split(" "))[0].strip())
        force_temp.append((a[12].split(" "))[0].strip())
        force_temp.append((a[13].split(" "))[0].strip())
        force.append(force_temp)
        load_temp.append((a[14].split(" "))[0].strip())
        load_temp.append((a[15].split(" "))[0].strip())
        load_temp.append((a[16].split(" "))[0].strip())
        load.append(load_temp)
    time = list(map(float, time))
    pitch = list(map(float, pitch))
    roll = list(map(float, roll))
    for i in range(len(time)):
        load[i] = list(map(float, load[i]))
        force[i] = list(map(float, force[i]))
        gyro[i] = list(map(float, gyro[i]))
    time = np.array(time)
    pitch = np.array(pitch)
    roll = np.array(roll)
    force = np.array(force)
    gyro = np.array(gyro)
    load = np.array(load)
    len(time)==len(pitch)==len(roll)==len(force)==len(gyro)==len(load)
    for i in range(len(time)-1):
        pitch[i+1]=(beta)*pitch[i+1]+(1-beta)*pitch[i]
        roll[i+1]=beta*roll[i+1]+(1-beta)*roll[i]
        gyro[i+1]=beta*gyro[i+1]+(1-beta)*gyro[i]
        load[i+1]=beta*load[i+1]+(1-beta)*load[i]
    a = "C:/Users/tanishqjasoria/Documents/Github/Rehab/gaitCycle-data/"+person+"/data34.txt"
    d = open(a,"a+")
    for i in range(len(time)):
        d.write(str(time[i]) + "  ")
        d.write(str(pitch[i]) + "  ")
        d.write(str(roll[i]) + "  ")
        for x in gyro[i]:
            d.write(str(x) + "  ")
        for x in force[i]:
            d.write(str(x) + "  ")
        for x in load[i]:
            d.write(str(x) + "  ")
        d.write("\n")
    d.close()
def process129(person):
    file = "C:/Users/tanishqjasoria/Documents/Github/Rehab/gaitCycle-data/"+person+"/test_data129.txt"

    f = open(file)
    lines = []
    time = []
    pitch = []
    roll = []
    gyro = []
    force = []
    load = []
    force_temp =[]
    gyro_temp = []
    load_temp = []
    beta = 0.9
    for line in f:
        lines.append(line) 
    for elem in lines:
        if elem == '\n':
            lines.remove('\n')
    for i in range(5):
        lines.pop(0)
        lines.pop()
    for line in lines:
        a = line.split("=")
        load_temp  = []
        gyro_temp  = []
        force_temp = []
        time.append((a[1].split(" "))[0].strip())
        pitch.append((a[2].split(" "))[0].strip())
        roll.append((a[3].split(" "))[0].strip())
        gyro_temp.append((a[4].split(" "))[0].strip())
        gyro_temp.append((a[5].split(" "))[0].strip())
        gyro_temp.append((a[6].split(" "))[0].strip())
        gyro.append(gyro_temp)
        force_temp.append((a[7].split(" "))[0].strip())
        force_temp.append((a[8].split(" "))[0].strip())
        force_temp.append((a[9].split(" "))[0].strip())
        force_temp.append((a[10].split(" "))[0].strip())
        force_temp.append((a[11].split(" "))[0].strip())
        force_temp.append((a[12].split(" "))[0].strip())
        force_temp.append((a[13].split(" "))[0].strip())
        force.append(force_temp)
        load_temp.append((a[14].split(" "))[0].strip())
        load_temp.append((a[15].split(" "))[0].strip())
        load_temp.append((a[16].split(" "))[0].strip())
        load.append(load_temp)
    time = list(map(float, time))
    pitch = list(map(float, pitch))
    roll = list(map(float, roll))
    for i in range(len(time)):
        load[i] = list(map(float, load[i]))
        force[i] = list(map(float, force[i]))
        gyro[i] = list(map(float, gyro[i]))
    time = np.array(time)
    pitch = np.array(pitch)
    roll = np.array(roll)
    force = np.array(force)
    gyro = np.array(gyro)
    load = np.array(load)
    len(time)==len(pitch)==len(roll)==len(force)==len(gyro)==len(load)
    for i in range(len(time)-1):
        pitch[i+1]=(beta)*pitch[i+1]+(1-beta)*pitch[i]
        roll[i+1]=beta*roll[i+1]+(1-beta)*roll[i]
        gyro[i+1]=beta*gyro[i+1]+(1-beta)*gyro[i]
        load[i+1]=beta*load[i+1]+(1-beta)*load[i]
    a = "C:/Users/tanishqjasoria/Documents/Github/Rehab/gaitCycle-data/"+person+"/data129.txt"
    d = open(a,"a+")
    for i in range(len(time)):
        d.write(str(time[i]) + "  ")
        d.write(str(pitch[i]) + "  ")
        d.write(str(roll[i]) + "  ")
        for x in gyro[i]:
            d.write(str(x) + "  ")
        for x in force[i]:
            d.write(str(x) + "  ")
        for x in load[i]:
            d.write(str(x) + "  ")
        d.write("\n")
    d.close()
def processBack(person):
    file = "C:/Users/tanishqjasoria/Documents/Github/Rehab/gaitCycle-data/"+person+"/test_databack.txt"
    f = open(file)
    lines = []
    time = []
    t1_temp=[]
    t2_temp=[]
    k1_temp=[]
    k2_temp=[]
    w_temp=[]
    back_temp=[]
    t1=[]
    t2=[]
    k1=[]
    k2=[]
    w=[]
    back=[]
    t1_old_theta=[0,0]
    t2_old_theta=[0,0]
    k1_old_theta=[0,0]
    k2_old_theta=[0,0]
    pitch_roll=[]
    PI = 3.14159265
    for line in f:
        lines.append(line) 
    for i in range(5):
        lines.pop(0)
        lines.pop()
    for elem in lines:
        if elem == '\n':
            lines.remove('\n')
    for x in lines:
        a = x.split("=")
        t1_temp=[]
        t2_temp=[]
        k1_temp=[]
        k2_temp=[]
        w_temp=[]
        back_temp=[]
        t1_temp.append(float(a[1].strip().split(" ")[0]))
        t1_temp.append(float(a[2].strip().split(" ")[0]))
        t1_temp.append(float(a[3].strip().split(" ")[0]))
        t1_temp.append((float(a[4].strip().split(" ")[0]))/131)
        t1_temp.append(-(float(a[5].strip().split(" ")[0]))/131)
        t1_temp.append((float(a[6].strip().split(" ")[0]))/131)
        t1_temp.append(float(a[7].strip().split(" ")[0]))
        t1_temp.append(float(a[8].strip().split(" ")[0]))
        t1_temp.append(float(a[9].strip().split(" ")[0]))
        t2_temp.append(float(a[10].strip().split(" ")[0]))
        t2_temp.append(float(a[11].strip().split(" ")[0]))
        t2_temp.append(float(a[12].strip().split(" ")[0]))
        t2_temp.append((float(a[13].strip().split(" ")[0]))/131)
        t2_temp.append(-(float(a[14].strip().split(" ")[0]))/131)
        t2_temp.append((float(a[15].strip().split(" ")[0]))/131)
        t2_temp.append(float(a[16].strip().split(" ")[0]))
        t2_temp.append(float(a[17].strip().split(" ")[0]))
        t2_temp.append(float(a[18].strip().split(" ")[0]))
        k1_temp.append(float(a[19].strip().split(" ")[0]))
        k1_temp.append(float(a[20].strip().split(" ")[0]))
        k1_temp.append(float(a[21].strip().split(" ")[0]))
        k1_temp.append((float(a[22].strip().split(" ")[0]))/131)
        k1_temp.append(-(float(a[23].strip().split(" ")[0]))/131)
        k1_temp.append((float(a[24].strip().split(" ")[0]))/131)
        k1_temp.append(float(a[25].strip().split(" ")[0]))
        k1_temp.append(float(a[26].strip().split(" ")[0]))
        k1_temp.append(float(a[27].strip().split(" ")[0]))
        k2_temp.append(float(a[28].strip().split(" ")[0]))
        k2_temp.append(float(a[29].strip().split(" ")[0]))
        k2_temp.append(float(a[39].strip().split(" ")[0]))
        k2_temp.append((float(a[31].strip().split(" ")[0]))/131)
        k2_temp.append(-(float(a[32].strip().split(" ")[0]))/131)
        k2_temp.append((float(a[33].strip().split(" ")[0]))/131)
        k2_temp.append(float(a[34].strip().split(" ")[0]))
        k2_temp.append(float(a[35].strip().split(" ")[0]))
        k2_temp.append(float(a[36].strip().split(" ")[0]))
        w_temp.append(float(a[37].strip().split(" ")[0]))
        w_temp.append(float(a[38].strip().split(" ")[0]))
        w_temp.append(float(a[39].strip().split(" ")[0]))
        w_temp.append(float(a[40].strip().split(" ")[0]))
        w_temp.append(float(a[41].strip().split(" ")[0]))
        back_temp.append(float(a[42].strip().split(" ")[0]))
        back_temp.append(float(a[43].strip().split(" ")[0]))
        back_temp.append(float(a[44].strip().split(" ")[0]))
        back_temp.append(float(a[45].strip().split(" ")[0]))
        back_temp.append(float(a[46].strip().split(" ")[0]))
        time.append(float((a[46].strip().split(" "))[2][4:]))
        t1.append(t1_temp)
        t2.append(t2_temp)
        k1.append(k1_temp)
        k2.append(k2_temp)
        w.append(w_temp)
        back.append(back_temp)
    time[0] = int(time[0])
    for i in range(len(time)-1):
        time[i+1] = int(time[i+1]) + int(time[i])
    time = np.array(time)
    t1 = np.array(t1)
    t2 = np.array(t2)
    k1 = np.array(k1)
    k2 = np.array(k2)
    w = np.array(w)
    back = np.array(back)
    time = time/1000
    time = time + 0.25
    for i in range(len(time)):
        temp=[]
        accy = math.atan2(t1[i][0], t1[i][2])*180/PI + 90
        accx = math.atan2(t1[i][1],t1[i][2])*80/PI + 90
        dt=0.01
        t1_theta = 0.85*(t1_old_theta+np.array([t1[i][4],t1[i][3]])*dt)+0.15*np.array([accy,accx])
        t1_old_theta = t1_theta
        temp.append(t1_theta)
        accy = math.atan2(t2[i][0], t2[i][2])*180/PI + 90
        accx = math.atan2(t2[i][1],t2[i][2])*80/PI + 90
        dt=0.01
        t2_theta = 0.85*(t2_old_theta+np.array([t2[i][4],t2[i][3]])*dt)+0.15*np.array([accy,accx])
        t2_old_theta = t2_theta
        temp.append(t2_theta)
        accy = math.atan2(k1[i][0], k1[i][2])*180/PI + 90
        accx = math.atan2(k1[i][1],k1[i][2])*80/PI + 90
        dt=0.01
        k1_theta = 0.85*(k1_old_theta+np.array([k1[i][4],k1[i][3]])*dt)+0.15*np.array([accy,accx])
        k1_old_theta = k1_theta
        temp.append(k1_theta)
        accy = math.atan2(k2[i][0], k2[i][2])*180/PI + 90
        accx = math.atan2(k2[i][1],k2[i][2])*80/PI + 90
        dt=0.01
        k2_theta = 0.85*(k2_old_theta+np.array([k2[i][4],k2[i][3]])*dt)+0.15*np.array([accy,accx])
        k2_old_theta = k2_theta
        temp.append(k2_theta)
        pitch_roll.append(temp) 
    a = "C:/Users/tanishqjasoria/Documents/Github/Rehab/gaitCycle-data/"+person+"/dataBack.txt"
    d = open(a,"a+")
    for i in range(len(time)):
        d.write(str(time[i]) + "  ")
        #for t1
        for x in pitch_roll[i][0]:
            d.write(str(x) + "  ")
        d.write(str(t1[i][3]) + "  ")
        d.write(str(t1[i][4]) + "  ")
        d.write(str(t1[i][5]) + "  ")
        for x in pitch_roll[i][1]:
            d.write(str(x) + "  ")
        d.write(str(t2[i][3]) + "  ")
        d.write(str(t2[i][4]) + "  ")
        d.write(str(t2[i][5]) + "  ")
        for x in pitch_roll[i][2]:
            d.write(str(x) + "  ")
        d.write(str(k1[i][3]) + "  ")
        d.write(str(k1[i][4]) + "  ")
        d.write(str(k1[i][5]) + "  ")
        for x in pitch_roll[i][3]:
            d.write(str(x) + "  ")
        d.write(str(k2[i][3]) + "  ")
        d.write(str(k2[i][4]) + "  ")
        d.write(str(k2[i][5]) + "  ")
        for x in w[i]:
            d.write(str(x) + "  ")
        for x in back[i]:
            d.write(str(x) + "  ")
        d.write("\n")
    d.close()
        


