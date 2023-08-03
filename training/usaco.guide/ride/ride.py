"""
USER: Aditya Bankoti [adi.ban1]
LANG: PYTHON3
TASK: ride 
PROG: ride
"""
fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')
stuff = fin.read().split("\n")

s1 = 1
s2 = 1
for c in stuff[0]:
    s1 *= ord(c) - 64

for c in stuff[1]:
    s2 *= ord(c) - 64

if s1 % 47 == s2 % 47:
    fout.write("GO\n")
else:
    fout.write("STAY\n")


fout.close()