# encoding=utf-8
import os
from pylab import *
from ctypes import *

string_N = "N="
string_M = "M="

value_N = range(1,100,2)
value_MSet = [100,1000,10000,10000]

value_count = 0

for value_M in value_MSet:
      file_name = "./input/input" + str(value_count) + '_'
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

      value_time = range(1,100,2)


      for i in range(0,count-1):
            with open("./timeresult/timeinput" + str(value_count) + '_' + str(i) + ".txt", "r") as file:
                  s = file.read()
                  value_time[i] = float(s)
                  print(value_time[i])

      value_count += 1
      plt.plot(value_N, value_time, mfc='w', label=str(value_M))

plt.xlabel('number of thread')
plt.ylabel('time/us')
plt.title("thread")
plt.legend()
plt.show()