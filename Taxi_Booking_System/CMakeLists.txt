cmake_minimum_required(VERSION 3.5.0)
project(taxi_booking_system VERSION 0.1.0 LANGUAGES C CXX)

add_executable(taxi_booking_system booking.cpp main.cpp system.cpp taxi.cpp location.cpp)

