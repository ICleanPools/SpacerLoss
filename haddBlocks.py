import os
for i in range(7,8):
    fileList = '../trees/CSCDigiTree%i.root'%(i*22)
    for j in range(21):
        if i == 9 and j > 17: continue
        print i,j
        fileList = fileList + " ../trees/CSCDigiTree%i.root"%(i*22+j+1)
        print fileList
        pass
    os.system("hadd cscDigiBlock%i.root "%i + fileList)
    pass
