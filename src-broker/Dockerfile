FROM --platform=arm64 nvcr.io/nvidia/l4t-base:r32.1 AS broker

# Set working directory
WORKDIR /ratatoskr/

# Update fetchables
RUN apt-get update

# Configure environment
RUN apt-get install -y \
    cmake \
    git \
    curl \
    gcc \
    g++ \
    mosquitto && \
    rm -rf /var/lib/apt/lists/*

# Expose the mosquitto MQTT port
EXPOSE 1883

# Run the mosquitto broker
CMD ["mosquitto", "-d"]
