#!/bin/sh

TargetDir=~/Library/Developer/Xcode/Templates
TargetDir3D=$TargetDir"/3D"

Glfw="Basic GLFW.xctemplate"
GlfwTargetPath="$TargetDir3D/$Glfw"

rm -rf "$GlfwTargetPath"
mkdir "$TargetDir3D"
cp -r "$Glfw" "$GlfwTargetPath"