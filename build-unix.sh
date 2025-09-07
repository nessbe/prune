# File:        build-unix.sh
# Project:     prune
# Repository:  https://github.com/nessbe/prune
#
# Copyright (c) 2025 nessbe
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at:
#
#     https://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# For more details, see the LICENSE file at the root of the project.

#!/bin/bash

set -u
set -o pipefail

SOURCE="source/prune.c"
INCLUDE="include"
FLAGS="-Wall -Wextra"
OUT="build/prune"

if ! command -v gcc >/dev/null 2>&1; then
    echo "Error: gcc not found in the PATH." >&2
    exit 1
fi

mkdir -p "$(dirname "$OUT")"

echo "Building $OUT from $SOURCE..."
gcc -I "$INCLUDE" "$SOURCE" -o "$OUT" $FLAGS
GCC_EXIT_CODE=$?

if [ $GCC_EXIT_CODE -ne 0 ]; then
    echo "Error: Build failed with exit code $GCC_EXIT_CODE." >&2
    exit $GCC_EXIT_CODE
else
    echo "Build succeeded: $OUT"
fi

exit 0
