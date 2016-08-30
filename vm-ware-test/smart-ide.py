import sys
multiFlag = False
for line in sys.stdin:
  lineProcess = False
  if '/*' in line and multiFlag == False and lineProcess == False:
    multiFlag = True
    lineProcess = True
    print line.strip()
  if multiFlag == True:
    if '*/' in line:
      multiFlag = False
      if lineProcess == False:
        print line.strip()
    elif lineProcess == False:
      lineProcess = True
      print line.strip()
  if '//' in line and multiFlag == False and lineProcess == False:
    lineProcess = True
    line = line.strip()
    index = line.index('/')
    print line[index:]
