# encoding=utf-8
import os
from pylab import *
from ctypes import *

string_N = "N="
string_M = "M="

value_N = [1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]
value_M = 10

file_name = "./input/input"
count = 0


for item in value_N:
      path_file_name = file_name + str(count) + ".txt"
      count += 1
      print(path_file_name) 

      with open(path_file_name, "w") as f:
            f.write(string_N + str(item) + "\n")
            f.write(string_N + str(value_M))

# os.system("../thread/multisum")
os.system("make test")

value_time = [1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]


for i in range(0,count-1):
      with open("./timeresult/timeinput" + str(i) + ".txt", "r") as file:
            s = file.read()
            value_time[i] = float(s)
            print(value_time[i])



plt.plot(value_N, value_time, 'ob-', label=u'y=x^2曲线图')
plt.show()