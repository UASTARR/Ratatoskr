# This Makefile is explicitly used to simplify working with docker builds

# PROJECT SPECIFICATIONS

PROJECT_NAME:=sensorstorm-image
DOCKER:=docker
WORKSPACE:=.


# COMMANDS AND CONFIG

BUILD:=build
RUN:=run


# EMULATED HOST SETUP

HOST_TAG:=-t sensorstorm-host-image
QEMU_SETUP:=--privileged multiarch/qemu-user-static --reset -p yes
PLATFORM:=--platform linux/arm64
QUIETLY:=> /dev/null 2>&1


# COMMANDS

# Allows (silently) enabling QEMU
enable-qemu:
	${DOCKER} ${RUN} --rm ${QEMU_SETUP} ${QUIETLY}

# Builder for custom docker image
image: enable-qemu
	${DOCKER} ${BUILD} ${PLATFORM} ${HOST_TAG} ${WORKSPACE}

# Runs the container using arguments supplied via the ARGS= flag
run: enable-qemu
	${DOCKER} ${RUN} --rm ${PLATFORM} ${HOST_TAG} ${ARGS}
