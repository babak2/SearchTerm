# Use the official Ubuntu base image
FROM ubuntu:latest

# Set the working directory in the container
WORKDIR /app

# Copy the contents of the local build/bin directory to the container at /app
COPY ./build/bin /app

# Copy the contents of the local input_files directory to the container at /app
COPY ./input_files /app

# Set the entry point for the container
CMD ["./search_term", "input_alice.txt"]
