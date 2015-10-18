#!/bin/sh

TargetDir=~/Library/Developer/Xcode/Templates/com.mutexre

Glfw="Basic GLFW.xctemplate"
GlfwTargetPath="$TargetDir/$Glfw"

if [ -e "$TargetDir" ]; then
    if [ -d "$TargetDir" ]; then
        rm -r "$GlfwTargetPath"
        cp -r "$Glfw" "$GlfwTargetPath"
    else
        rm "$TargetDir"
        mkdir "$TargetDir"
        cp -r "$Glfw" "$GlfwTargetPath"
    fi
else
    mkdir "$TargetDir"
    cp -r "$Glfw" "$GlfwTargetPath"
fi
