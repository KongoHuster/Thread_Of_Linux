import os

string_N = "N="
string_M = "M="

value_N = [1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100]
value_M = 10

file_name = "input"
count = 0


for item in value_N:
      path_file_name = file_name + str(count) + ".txt"
      count += 1
      print(path_file_name) 

      with open(path_file_name, "w") as f:
            f.write(string_N + str(item) + "\n")
            f.write(string_N + str(value_M))



