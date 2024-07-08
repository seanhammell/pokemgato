#!/bin/bash
find -E . -regex '.*\.(cpp|hpp)' -exec clang-format -style=Google -i {} \; -exec cpplint {} \;