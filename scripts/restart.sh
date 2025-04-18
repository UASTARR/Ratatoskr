#!/bin/bash

# Setup QEMU emulator
echo "Setting up qemu emulator..."
docker run --rm --privileged multiarch/qemu-user-static --reset -p yes

# Turn off current docker services across the host
echo "Restarting docker services..."
docker compose down -v
if [ $? -eq 0 ]; then
    echo "Old Docker services shutdown"
else
    echo "Failed to shutdown old docker services"
    exit 1
fi

# Restart / Turn on this applications specific docker services
echo "Starting new docker services..."
docker compose up --build -d
if [ $? -eq 0 ]; then
    echo "New services started!"
else
    echo "Failed to start new services"
    exit 1
fi
