import random
import time

def bag(n, c, w, v):
    # 置零，表示初始状态
    value = [[0 for j in range(c + 1)] for i in range(n + 1)]
    for i in range(1, n + 1):
        for j in range(1, c + 1):
            value[i][j] = value[i - 1][j]
            # 背包总容量够放当前物体，遍历前一个状态考虑是否置换
            if j >= w[i - 1] and value[i][j] < value[i - 1][j - w[i - 1]] + v[i - 1]:
                value[i][j] = value[i - 1][j - w[i - 1]] + v[i - 1]
    print("weight: ")
    print(w)
    print("value: ")
    print(v)
    # for x in value:
    #     print(x)
    return value

def show(n, c, w, value):
    print('the best value is ', value[n][c])
    x = [False for i in range(n)]
    j = c
    for i in range(n, 0, -1):
        if value[i][j] > value[i - 1][j]:
            x[i - 1] = True
            j -= w[i - 1]
    print('the things in the bag:你 ')
    for i in range(n):
        if x[i]:
            print('NO. ', i+1, ' thing,', end='')

n = 70  # 物品的数量，
c = 2000 # 书包能承受的重量，
w=[0 for _ in range(n)] # the weight of goods
v=[0 for _ in range(n)] # the values of goods
for k in range(n):
    w[k]=random.randint(1,n)
    v[k]=random.randint(1,n)

# 乱码严重，改为英文输出（utf-8 也会乱码我也是醉了）
t1=time.time_ns()
total = bag(n,c,w,v)
e1=time.time_ns()

t2=time.time_ns()
show(n,c,w,total)
e2=time.time_ns()

print("\n===============================")
print("time of function bag :"+str(e1-t1)+" ns")
print("time of function show :"+str(e2-t2)+" ns")
