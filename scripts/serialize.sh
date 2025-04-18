#!/bin/sh

# NOTE: probably should change this later
IMAGES="ratatoskr/diagnostics:latest ratatoskr/broker:latest"
PWD=$(pwd)
O_FLAG=""
BIN_PATH=""

# Handle options
getopts "o:" FLAG_IN
case ${FLAG_IN} in
    o) BIN_PATH=${OPTARG} ;;
    *) continue ;;
esac

# Fix Binary path if none specified to default location
if [${BIN_PATH} -eq ""]; then
    BIN_PATH=${PWD}/build/bin
fi

echo "Serializing all known docker images into compressed artifact..."
echo "Saving to '${BIN_PATH}'..."
ls -ld ${BIN_PATH} > /dev/null 2>&1

# Create the binary path if none is specified
if [ $? -ne 0 ]; then
    echo "No BIN_PATH detected. Creating..."
    mkdir -p ${BIN_PATH}
    if [ $? -ne 0 ]; then
        echo "Failed to create BIN_PATH."
        exit 255
    fi
fi

# Serialize the docker image to the binary path
docker image save ${IMAGES} | gzip > ${BIN_PATH}/ratatoskr-flash.tar.gz
if [ $? -ne 0 ]; then
    echo "Failed to serialize docker images."
    exit 255
else
    echo "Images serialized! Consider flashing using scp and ssh."
fi
