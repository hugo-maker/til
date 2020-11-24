#!/bin/bash
MESSAGE=${1:-"Added today's activities"}

git add -A
git commit -m "${MESSAGE}"
git push origin main
