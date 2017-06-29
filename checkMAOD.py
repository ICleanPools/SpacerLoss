from ROOT import TFile,TTree

with open('NEvents.txt') as freco:
    NEList = freco.read().splitlines()

Ntot = 0
Nfiles = len(NEList)

for i in range(0,Nfiles/10):
    myF = TFile("trees/CSCDigiTree%i.root"%i,'read')
    if(i%100==0): print i
#    print int(NEList[i])
    if not (myF.IsOpen()): continue
    c_h = myF.Get('hist')
    Nev = c_h.GetEntries()
    Ntot += Nev
    NevF = 0
    for j in range(i*10,i*10+10):
        NevF += int(NEList[j])
    if(Nev != NevF): print "File %i has only %i entries and should have %i"%(i,Nev,NevF) 

print "%i files read"%Nfiles
print "Finished with %i events counted"%Ntot

