cmake_minimum_required(VERSION 3.16) 
project(rest LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenSSL REQUIRED)

file(GLOB SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/*)

include(FetchContent)

FetchContent_Declare(
  httplib
  GIT_REPOSITORY https://github.com/yhirose/cpp-httplib.git
  GIT_TAG v0.19.0  # or the latest version
)

FetchContent_MakeAvailable(httplib)

add_subdirectory(test)

add_executable(rest ${SOURCE} 
                    ${CMAKE_CURRENT_SOURCE_DIR}/main.cc)
target_include_directories(rest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(rest httplib OpenSSL::SSL OpenSSL::Crypto)

set(CERT_DIR ${CMAKE_CURRENT_BINARY_DIR}/cert)
file(MAKE_DIRECTORY ${CERT_DIR})

add_custom_command(
  OUTPUT ${CERT_DIR}/key.pem
  COMMAND openssl genrsa -out ${CERT_DIR}/key.pem 2048
  COMMENT echo "Creating private key"
  VERBATIM
)

add_custom_command(
   OUTPUT ${CERT_DIR}/cert.pem
    COMMAND openssl req -new -x509
            -key ${CERT_DIR}/key.pem
            -out ${CERT_DIR}/cert.pem
            -days 365
            -subj "/CN=localhost"
    DEPENDS ${CERT_DIR}/key.pem
    COMMENT "Generating self-signed certificate"
    VERBATIM
)
add_custom_target(generate_cert ALL
    DEPENDS
    ${CERT_DIR}/key.pem 
    ${CERT_DIR}/cert.pem)
add_dependencies(rest generate_cert)
