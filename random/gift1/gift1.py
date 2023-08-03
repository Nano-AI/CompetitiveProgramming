"""
USER: Aditya Bankoti [adi.ban1]
LANG: PYTHON3
PROG: gift1 
"""
fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')
lines = fin.read().split("\n")

total = {}

new_group = False 
leader = ""
money = 0
count = 0
per_person = 0

first_run = True 

x = 0

while x < len(lines) - 1:
    person = lines[x]
    if first_run and not person.isdigit():
        total[person] = 0
    nums = lines[x + 1].split(" ")
    if len(nums) > 0 and nums[0].isdigit():
        if first_run:
            first_run = False
        money = int(nums[0])
        count = int(nums[1])
        leader = person
        if count != 0 and money != 0:
            dist = money - money % count
            total[leader] -= dist
            per_person = dist / count
        else:
            per_person = 0
    elif not person.split(" ")[0].isdigit():
        if not first_run and leader != '':
            total[person] += per_person
    x += 1

answer = ""

for person in total:
    answer += person + " " + str(int(total[person])) + "\n"


fout.write(answer)
fout.close()