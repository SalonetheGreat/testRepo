import os

os.system('gcc repoCtest.c')
for i in range(1, 9):
    os.system('./a.out ' + str(i))
