#since I couldnt cross compile my self because of size on c9 and koding, I an already cross compiler

export NOSP="$PWD"
cd ../barebones-toolchain
export PATH="$PWD/cross/i686/bin:$PATH"
. ./setenv.sh
cd $NOSP