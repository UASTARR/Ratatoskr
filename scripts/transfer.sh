#!/bin/sh

# What we are transferring
SRC=""
# The IPv4 address of the jetson nano device connected via ethernet (see README for instructions)
DST=""
# The username of the jetson nano
JUSER="uastarr"


# Print the usage of this script, IE: How to use it.
usage() {
    echo "Usage: $0 [-s <src-path>] [-d <dst-ipv4>]"
}

# Gather options
UNRECOGNIZED_FLAG=0
while getopts "d:s:" FLAG; do
    case ${FLAG} in
        d)
            DST=${OPTARG}
            ;;
        s)
            SRC=${OPTARG}
            ;;
        *) 
            UNRECOGNIZED_FLAG=1
            ;;
    esac
done

# Alert user of error

if [ -z "${DST}" ] || [ -z "${SRC}" ]; then
    usage
    exit 255
fi

if [ ${UNRECOGNIZED_FLAG} -eq 1 ]; then
    usage
    exit 255
fi

# Actually do the file transfer
echo "Initiating file transfer from ${SRC} to ${DST}..."
# This should trigger password request. Make sure to enter your password.
scp ${SRC} ${JUSER}@${DST}:/home/${JUSER}/Downloads
if [ $? -ne 0 ]; then
    echo "Error: Failed to transfer file."
    exit 255
fi
