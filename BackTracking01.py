#! /usr/bin/env python
# coding=utf-8
import random
import time
import numpy

class BackSack():  # 定义背包类
    def __init__(self, capacity):  # 类的初始化
        self.capacity = capacity  # 背包最大容量（重量）
        self.currentWeight = 0  # 背包当前重量
        self.bestValue = 0  # 背包可容纳货物的最大价值，最优值
        self.currentValue = 0  # 背包内当前已装货物的价值

    def Backtrack(self, i):  # 遍历解空间寻找最优值，I:当前搜索的深度
        global length, weight, value, goods  # 全局变量
        if (i > length):
            if self.currentValue > self.bestValue:  # 更新最优值
                self.bestValue = self.currentValue
                self.currentCapacity = self.currentWeight  # 当前最优解下的背包重量
                self.bestgoods = goods[0:10]
                print('best:', self.bestgoods)  # 输出当前的最优解，最后一次输出即是最终的最优解
            return
        if self.currentWeight + weight[i] <= self.capacity:  # 进入左子树，即选取goods[i]放入背包
            goods[i] = 1
            self.currentWeight = self.currentWeight + weight[i]
            self.currentValue = self.currentValue + value[i]
            self.Backtrack(i + 1)
            self.currentValue = self.currentValue - value[i]  # 进入右子树，即舍弃goods[i]，不放入背包
            self.currentWeight = self.currentWeight - weight[i]
            goods[i] = 0
        self.Backtrack(i + 1)


def main():
    global length, weight, value, goods  # 全局变量，分别表示货物数目，货物的重量数组，价值数组，货物的选取即0-1值
    # currentWeight = 0
    # bestValue = 0
    # currentValue = 0
    capacity = 200
    number_goods = 35
    value_max = 50
    weight_max = 50

    weight = [0 for _ in range(number_goods)]
    for index1 in range(number_goods):
        weight[index1] = random.randint(1, weight_max)
    print(weight)

    # weight = [2, 2, 6, 5, 4]

    value = [0 for _ in range(number_goods)]
    for index2 in range(number_goods):
        value[index2] = random.randint(1, value_max)
    print(value)

    # value = [6, 3, 5, 4, 6]

    goods = [0 for _ in range(number_goods)]

    length = len(weight) - 1
    backsack = BackSack(capacity)

    start_time = time.time_ns()
    backsack.Backtrack(0)
    end_time = time.time_ns()

    # backsack.Backtrack=Backtrack
    print("===============================================")
    print("Bag weight: " + str(capacity))
    print("Number of goods: " + str(capacity // 2))
    print("Best value: " + str(backsack.bestValue))
    print("Current weight: " + str(backsack.currentCapacity))  # 输出最优值和背包内物品的总重量
    print("Total time: " + str(end_time - start_time) + " ns.")
    print(backsack.bestgoods)  # 输出最优解

    return end_time - start_time


times = [0, 0, 0]
for ix in range(3):
    ctime = main()
    times[ix] = ctime
print("################################################################")
print(numpy.mean(times))
