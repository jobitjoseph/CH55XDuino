#!/usr/bin/python
import re

#GITEE doesn't allow direct fetch of webpage form python, using API is not necessary.
#we extract from brower's console

bz2OnGitee = ("https://gitee.com/deqings/ch55xduino/attach_files/491764/download/ch55xduino-tools_macosx-2020.10.05.tar.bz2","https://gitee.com/deqings/ch55xduino/attach_files/491765/download/ch55xduino-tools_mingw32-2020.10.05.tar.bz2","https://gitee.com/deqings/ch55xduino/attach_files/491766/download/ch55xduino-core-0.0.6.tar.bz2","https://gitee.com/deqings/ch55xduino/attach_files/491757/download/sdcc-mcs51-i586-mingw32msvc-20200526-11630.tar.bz2","https://gitee.com/deqings/ch55xduino/attach_files/491758/download/ch55xduino-tools_mingw32-2020.05.31.tar.bz2","https://gitee.com/deqings/ch55xduino/attach_files/491759/download/ch55xduino-tools_macosx-2020.05.31.tar.bz2","https://gitee.com/deqings/ch55xduino/attach_files/491760/download/ch55xduino-core-0.0.1.tar.bz2","https://gitee.com/deqings/ch55xduino/attach_files/491761/download/sdcc-mcs51-x86_64-apple-macosx-20200526-11630.tar.bz2",)

#print(bz2OnGitee)

originalJSON = open("../package_ch55xduino_mcs51_index.json","r")
jsonLines = originalJSON.readlines()
originalJSON.close()

for i in range(len(jsonLines)):
    line = jsonLines[i]
    bzFileMatch = (re.search('\"(http.+bz2)\"',line))
    if (bzFileMatch):
        originalBz2URL = bzFileMatch.group(1)
        #print(originalBz2URL)
        releaseVerMatch = (re.search('download/(.+)/(.+\.bz2)',line))
        if releaseVerMatch==None: break;
        releaseVer = releaseVerMatch.group(1)
        bz2File = releaseVerMatch.group(2)
        bzInGitee = False
        for bzStr in bz2OnGitee:
            if (bz2File in bzStr):
                bzInGitee = True
                #print("    "+bz2File + " in " + bzStr)
                jsonLines[i] = line.replace(originalBz2URL,bzStr)
                break
        

for line in jsonLines:
    pass
#   print(line)

with open('package_ch55xduino_mcs51_index_gitee.json', 'w') as the_file:
    for line in jsonLines:
        the_file.write(line)
