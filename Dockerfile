FROM nvcr.io/nvidia/l4t-base:r34.1 AS base

# Set working directory
WORKDIR /jetsonNano/sensorStorm/

# Update the OS
RUN apt-get update -y
RUN apt-get upgrade -y

# Dev-Dependencies
RUN apt-get install -y \
    cmake \
    git \
    curl \
    gcc \
    g++ \
    make && \
    rm -rf /var/lib/apt/lists/*


# Build the weather station application
FROM base AS weather-station

# Prepare the runtime environment with our files
COPY CMakeLists.txt /jetsonNano/sensorStorm/
COPY weather_station/ /jetsonNano/sensorStorm/weather_station/

# Actually run the build
RUN cmake -S . -B build

# Start nmqx integration
FROM base AS nmqx

# Setup NMQX
RUN curl -s https://assets.emqx.com/scripts/install-nanomq-deb.sh  | bash
RUN sudo apt-get install nanomq
RUN sudo systemctl start nanomq

EXPOSE 1883
