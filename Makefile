CC_DIR=$(shell brew --prefix llvm)
CC=${CC_DIR}/bin/clang
CXX=${CC_DIR}/bin/clang++
Generates=Ninja

VCPKG_PATH=${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake
TOOL_FILE=-DCMAKE_TOOLCHAIN_FILE=${VCPKG_PATH}
CXX_ASAN_FLAG=-DCMAKE_CXX_FLAGS="-fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -fsanitize=leak -g"
C_ASAN_FLAG=-DCMAKE_C_FLAGS="-fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -fsanitize=leak -g"
LINK_ASAN_FLAG=-DCMAKE_EXE_LINKER_FLAGS="-fno-omit-frame-pointer -fsanitize=address -fsanitize=undefined -fsanitize=leak"
PROTOC=${VCPKG_ROOT}/installed/x64-osx/tools/protobuf/protoc
PROTO_DST=.
IDLPATH="idl/pb/"

ARGS=-G ${Generates} -S . ${TOOL_FILE} ${C_ASAN_FLAG} ${CXX_ASAN_FLAG} ${LINK_ASAN_FLAG}
TARGET=cppcheats

config:
	cmake -B _build ${ARGS}

build: config
	cmake --build _build

clean:
	rm -fr _build

run: build
	./_build/${TARGET}

fmt:
	clang-format -i -style=file *.cpp *.h

gen_pb:
	${PROTOC} --proto_path=${IDLPATH} --cpp_out=${PROTO_DST} idl/pb/person.proto