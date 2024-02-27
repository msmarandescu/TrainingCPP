#!/bin/bash

CompileFiles=$1
outDirName=$2
exeName=$3

rm -r $outDirName 2> /dev/null
# rm -rf out/ | trueh 
mkdir -p $outDirName/

echo "Compilation started:"

for f in $CompileFiles
do 
    # echo "$outDirName/$(basename -- ${f%.*}.o)" 
    $(g++ -Wall -std=c++17 -g -c $f -o "$outDirName/$(basename -- ${f%.*}.o)")
    exitCode=$?
    echo "  $f"
    if [ $exitCode -gt 0 ]
    then 
        echo "break"
        break
    fi
done

if [ $exitCode -gt 0 ]
then 
    echo "Compilation failed! exit code:$exitCode"
else
    echo "Compilation successful!"

    echo "Linking started:"
    obj=""
    for o in $(ls $outDirName)
    do
        obj="$obj $outDirName/$o"
        echo "  Linking file: "$o
    done

    $(g++ -Xlinker $obj -o $outDirName/$exeName -lpthread)
    echo "Linking end!"
    echo "Project build successful!"
    echo
fi
