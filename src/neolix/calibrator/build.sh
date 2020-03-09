
SRC_DIR=$(dirname $(readlink -f "$0"))
INSTALL_DIR="$SRC_DIR/../opt/"
PYTHON_DIR="$SRC_DIR/../opt/python"
PROTO_IN="$SRC_DIR/src/proto"
# PROTO_IN="$SRC_DIR/src/proto"
PROTO_OUT="/autobot/cyber/proto_build/python"

function build_py_proto() {
  find $SRC_DIR -name "*.proto" \
      | xargs -t protoc -I=$SRC_DIR --python_out=$PROTO_OUT
  find $PROTO_OUT/../* -type d -exec touch "{}/__init__.py" \;
}

# mkdir proto_build
# mkdir proto_build/python
echo $SRC_DIR
# cd $PROTO_IN
build_py_proto
# cd $SRC_DIR

# mkdir build
# cd build 
# cmake -DCMAKE_INSTALL_PREFIX=$INSTALL_DIR ..
# make -j12 install
