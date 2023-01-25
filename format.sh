#!/bin/bash
echo "Applying clang-format for staged files" 
for FILE in $(git diff --cached --name-only *.cpp *.hpp)
do
    echo "Formatting $FILE..."
    clang-format-9 -i $FILE
    git add $FILE
done 