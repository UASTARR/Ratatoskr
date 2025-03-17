#!/bin/bash

echo "Restarting docker services..."
docker compose down -v
if [ $? -eq 0 ]; then
    echo "Old Docker services shutdown"
else
    echo "Failed to shutdown old docker services"
    exit 1
fi

echo "Starting new docker services..."
docker compose up --build -d
if [ $? -eq 0 ]; then
    echo "New services started!"
else
    echo "Failed to start new services"
    exit 1
fi
