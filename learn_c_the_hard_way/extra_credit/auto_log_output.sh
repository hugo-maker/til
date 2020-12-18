#!/bin/bash

set -eu
OUTFILE=${1:-"stdout.log"}
ERRFILE=${2:-"stderr.log"}

echo "This script runs autotest.sh, and emits two log files."
{ { sh ./autotest.sh | tee "${OUTFILE}"; } 3>&2 2>&1 1>&3 | tee "${ERRFILE}"; } 3>&2 2>&1 1>&3
