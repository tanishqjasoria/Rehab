p_e=0
i_e=0
d_e=0
Kp = 100
Ki = 0.1
Kd = 0.01
setPoint = 0
actPoint = 0
e_prev = 0
e_curr = 0
while(True):
    e_curr = setPoint - actPoint
    i_e = p_e + e_curr
    p_e = e_curr
    d_e = e_curr - e_prev
    u = Kp * p_e + Ki * i_e + Kd * d_e
    
