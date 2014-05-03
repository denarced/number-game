#!/bin/bash

while [ 1 ]
do
    clear
    date
    output="/tmp/test_output.$RANDOM.log"
    scons -c >$output
    if [ $? -eq 0 ]
    then
        scons > $output
    fi
    if [ $? -eq 0 ]
    then
        ./bin/debug/test > $output
    fi
    if [ $? -ne 0 ]
    then
        echo "Contents of log file"
        echo " -------------- START --------------"
        cat $output
        echo " --------------  END  --------------"
    fi
    inotifywait -e close_write `find src/ -type f ! -name '*.swp'`
done
