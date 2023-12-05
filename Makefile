name: C++ CI/CD with Make

on:
  push:
    branches:
      - master

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
      - name: Enable debug
        run: |
          echo "::set-env name=MAKEFLAGS::--debug=b"
          echo "::set-env name=MAKELEVEL::0"
        shell: bash
        
      - name: Print Working Directory and Contents
        run: |
          pwd
          ls -al
        working-directory: ${{ github.workspace }}

      - name: Set up GCC
        uses: actions/setup-python@v2
        with:
          python-version: 3.x

      - name: Install GCC
        run: sudo apt-get update && sudo apt-get install -y g++-9

      - name: Check GCC Version
        run: g++ --version

      - name: Build
        run: make all
        working-directory: ${{ github.workspace }}

      - name: Checkout Repository
        uses: actions/checkout@v2

      - name: Print Repository Contents
        run: |
          ls -al
          ls -al src
          cat Makefile
        working-directory: ${{ github.workspace }}

      - name: Build with Make
        run: make
        working-directory: ${{ github.workspace }}

      - name: Set up Catch2
        run: |
          git submodule update --init --recursive
        working-directory: ${{ github.workspace }}

      - name: Run Tests
        run: make test
        working-directory: ${{ github.workspace }}

      - name: Display Artifacts
        run: |
          ls -al build
        working-directory: ${{ github.workspace }}

      - name: Deploy (Example)
        if: success()
        run: echo "Deployment step (replace with actual deployment commands)"
        working-directory: ${{ github.workspace }}

      - name: Debug Statement
        if: failure() || cancelled()
        run: echo "The workflow failed or was cancelled."
