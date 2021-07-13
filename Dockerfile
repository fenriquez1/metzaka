FROM fedora:latest

RUN dnf -y install cmake gcc-c++ ninja-build boost-devel

EXPOSE 5300:5300/tcp
