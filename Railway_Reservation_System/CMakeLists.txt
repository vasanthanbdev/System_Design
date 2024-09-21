cmake_minimum_required(VERSION 3.5.0)
project(railway_reservation_system VERSION 0.1.0 LANGUAGES C CXX)

add_executable(railway_reservation_system passenger.cpp railway_reservation_system.cpp ticket.cpp)

