import os

workingDir = '/home/ymoon/src/study/c_basic/python'
execFile = 'python3 ./closure.py'

def run(path):
    os.chdir(workingDir)
    os.system(path)

run(execFile)
