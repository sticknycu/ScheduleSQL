#!/bin/bash
# Default values of arguments
SHOULD_INITIALIZE=0
CACHE_DIRECTORY="/etc/cache"
ROOT_DIRECTORY="/etc/projects"
OTHER_ARGUMENTS=()

# Loop through arguments and process them
for arg in "$@"; do
  case $arg in
  -i | --initialize)
    SHOULD_INITIALIZE=1
    shift # Remove --initialize from processing
    ;;
  -c=* | --cache=*)
    CACHE_DIRECTORY="${arg#*=}"
    shift # Remove --cache= from processing
    ;;
  -r | --root)
    ROOT_DIRECTORY="$2"
    shift # Remove argument name from processing
    shift # Remove argument value from processing
    ;;
  *)
    OTHER_ARGUMENTS+=("$1")
    shift # Remove generic argument from processing
    ;;
  esac
done

cd "${OTHER_ARGUMENTS[1]}" && rm -r "${OTHER_ARGUMENTS[0]}"
