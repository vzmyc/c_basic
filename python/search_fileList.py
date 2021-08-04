import os

path = "./"
file_list = os.listdir(path)
file_list_py = [file for file in file_list if file.endswith(".py")]

print ("file_list_py: {}".format(file_list_py))
