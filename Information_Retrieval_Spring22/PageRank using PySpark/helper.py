# to generate node_names file containing node ids

import string
with open("node_names.txt", "w") as output:
  for i in range(1, 8298):
    output.write(str(i) + '\t' + str(i) + '\n')





# to sort graphx output acc to rank #
with open("PySpark-GraphX-result.txt", "rt") as openfile:
    new_list = []
    for line in openfile:
        new_list.append(line.rstrip("()\n"))



def my_sort(line):
    line_fields = line.strip().split(',')
    amount = float(line_fields[1])
    return amount


new_list.sort(key=my_sort, reverse = True)

with open("graphx_sorted.txt", "w") as output:
  for line in new_list:
    output.write(line + '\n')
