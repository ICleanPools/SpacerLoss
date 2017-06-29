#!/usr/bin/python
import os

#for n in redoFiles:
for i in range(0,217):
    #i = int(n)
    outF = open("sh/runCSCDigiTree" + str(i) + ".sh" , 'w')
    outF.write("#!/bin/bash\n")
    outF.write("\n")
    outF.write("export CMSSW_PROJECT_SRC=\"/afs/cern.ch/user/p/pepps/work/cscDigiTrees/CMSSW_8_0_10/src\"\n")
    outF.write("export JOB_DIR=\"/afs/cern.ch/user/p/pepps/work/cscDigiTrees/run\"\n")
    outF.write("export CFG_FILE=\"makeCSCDigiTree_RAWRECO_cfg.py\"\n")
    outF.write("export X509_USER_PROXY=\"/afs/cern.ch/user/p/pepps/proxy/myProxy\"\n")
    outF.write("\n")
    outF.write("cd $CMSSW_PROJECT_SRC\n")
    outF.write("eval `scramv1 runtime -sh`\n")
    outF.write("cd $JOB_DIR\n")
    outF.write("cmsRun $CFG_FILE fileN=" + str(i) + "\n")
    outF.write("rm core.*\n")
    outF.write("\n")
    outF.close()
    os.system("bsub -q 8nh -J csc" + str(i) + " < sh/runCSCDigiTree" + str(i) + ".sh")
    #os.system("bsub -R \"pool>3000\" -q 1nh -J qcdHT2AR" + str(i) + " < sh/runAnaRECOqcd" + str(i) + ".sh")
