FROM --platform=arm64 nvcr.io/nvidia/l4t-base:r32.1 AS diagnostics

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

# Prepare the root of the virtual environment
COPY CMakeLists.txt /ratatoskr/
COPY ./vendor/ /ratatoskr/vendor/

# Prepare this environment
COPY ./src-diagnostics/CMakeLists.txt /ratatoskr/src-diagnostics/
COPY ./src-diagnostics/src/ /ratatoskr/src-diagnostics/src/

# Get cmake going
RUN cmake -S .
RUN cmake --build .

CMD ["./bin/diagnostics"]
