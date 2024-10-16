import os

# 获取当前目录下所有后缀名为.lib的文件
lib_files = [f for f in os.listdir('.') if f.endswith('.lib')]

# 将文件名写入一个.txt文件中，每一个文件名占一行
with open('lib_files.txt', 'w') as file:
    for lib_file in lib_files:
        file.write(lib_file + '\n')

print("文件名已写入lib_files.txt")
