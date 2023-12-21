#!/bin/bash

dirName="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
source $dirName/_variables.sh

cmake -S $PROJECT_ROOT_DIR_PATH -B $BIN_DIR_PATH -GNinja
ninja -C $BIN_DIR_PATH
