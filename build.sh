#/bin/bash

# Collect shell command line arguments
readonly PROGNAME=$(basename $0)
readonly ARGS=("$@")

usage() {
    echo "usage: $PROGNAME <DOCKER_IMAGE> <SOURCE_DIR> [clean]"
}

executeBuild() {
    docker run  --rm                        \
                -v $PWD/build:/build        \
                -v $PWD/${ARGS[1]}:/${ARGS[1]}    \
                -w /build                   \
                "${ARGS[0]}"                \
                bash -c "cmake -G Ninja ../${ARGS[1]} ; ninja-build"
}

buildDockerImage() {
    docker build -t "${ARGS[0]}" .
}

clean() {
    echo "Cleaning Previous Build..."
    rm -rf ./build
}

main() {
    if [ ${#ARGS[@]} -lt 2 ]
    then
    usage
    return 1
    fi

    docker image inspect "${ARGS[0]}"
    if [ $? -ne 0 ]
    then
    echo "Building docker image ${ARGS[0]}"
    buildDockerImage
    fi

    if [ "${ARGS[2]}" == "clean" ]
    then
    clean
    fi

    if [[ ! -d "./build" ]]
    then
    echo "Running new build..."
    mkdir build
    else
    echo "Updating previous build..."
    fi

    executeBuild
}

main
