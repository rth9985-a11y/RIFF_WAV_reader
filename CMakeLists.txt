cmake_minimum_required(VERSION 4.0)
project(wav_file_reader)

set(CMAKE_CXX_STANDARD 20)

add_executable(wav_file_reader main.cpp
        WAVHeader.h)
