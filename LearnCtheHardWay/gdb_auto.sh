#!/bin/bash
FILENAME=${1:-"Default File"}

gdb --batch --ex run --ex bt --ex q --args ./"${FILENAME}"
