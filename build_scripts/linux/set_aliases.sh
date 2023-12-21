#!/bin/bash

# Determine the directory where the script is located
dirName="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source "$dirName/_variables.sh"

alias build="$dirName/build.sh"
alias run="$dirName/run_project.sh"
alias create="$dirName/create_project.sh"

echo "Aliases set"

