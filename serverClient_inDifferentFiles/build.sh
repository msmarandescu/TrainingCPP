#!/bin/bash

#delete log files:
sudo rm -r logScript.log serverLogFile.log clientLogFile.log


#compieaza cele 2 programe utilizand scriptul compille.sh ca are parametrii:
# $1 - "fisierele ce urmeaza a fi compilate"
# $2 - "locatia in care sa creeze obiectele si executabilul"
# $3 - "numele executabilului"
sh compille.sh "server.cpp SocketCommunication.cpp" "outputServer" "server.exe"
sh compille.sh "client.cpp SocketCommunication.cpp" "outputClient" "client.exe"

#rulez executabilele salvand stdOut si stdErrorOut in logScript.log
./outputServer/server.exe > logScript.log 2>&1 &
./outputClient/client.exe > logScript.log 2>&1 &
