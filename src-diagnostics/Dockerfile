FROM nvcr.io/nvidia/l4t-base:r32.1 AS diagnostics

# Set working directory
WORKDIR /ratatoskr/

# Update fetchables
RUN apt-get update

# Dev-Dependencies
RUN apt-get install -y \
    cmake \
    git \
    curl \
    gcc \
    g++ \
    make && \
    rm -rf /var/lib/apt/lists/*

# Prepare the runtime environment with our files
COPY CMakeLists.txt ./
COPY ./vendor /ratatoskr/vendor/
COPY ./src-diagnostics/ /ratatoskr/src-diagnostics/
