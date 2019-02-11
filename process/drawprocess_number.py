# encoding=utf-8
import os
from pylab import *
from ctypes import *

string_N = "N="
string_M = "M="

value_N = range(1,100,2)
value_MSet = [1,100,1000,10000]
value_count = 0

path_file_name = "./input/input0_0.txt"
value_time = range(1,100,2)
count = 0

for value_M in value_MSet:
      
      for item in value_N:
            # print(path_file_name) 

            with open(path_file_name, "w") as f:
                  f.write(string_N + str(item) + "\n")
                  f.write(string_N + str(value_M))

            # os.system("../thread/multisum")
            os.system("make test")

            
            with open("./timeresult/timeinput0_0.txt", "r") as file:
                  s = file.read()
                  value_time[count] = float(s)
                  print(value_time[count])
            count += 1
           
      plt.plot(value_N, value_time, mfc='w', label=str(value_M))
      count = 0

plt.xlabel('number of thread')
plt.ylabel('time/us')
plt.title("thread")
plt.legend()
plt.show()