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

echo "${OTHER_ARGUMENTS[0]}" # ScheduleSQL.txt
echo "${OTHER_ARGUMENTS[1]}" # root
echo "${OTHER_ARGUMENTS[2]}" # .students
echo "${OTHER_ARGUMENTS[3]}" # Andrei

cd "${OTHER_ARGUMENTS[1]}"

# jq '.students += Andrei' ScheduleSQL.txt
# jq --arg entry "students" --arg destination "Andrei"  '.[$entry] = $destination' ScheduleSQL.txt
REZULTAT=$(jq --arg entry "${OTHER_ARGUMENTS[3]}" --arg destination "${OTHER_ARGUMENTS[2]}" '.[$destination] = $entry' "${OTHER_ARGUMENTS[0]}")
rm -r "${OTHER_ARGUMENTS[0]}"
touch "${OTHER_ARGUMENTS[0]}"
echo $REZULTAT > "${OTHER_ARGUMENTS[0]}"
#jq '"${OTHER_ARGUMENTS[2]}" + +=  + ""${OTHER_ARGUMENTS[3]}"" + "${OTHER_ARGUMENTS[0]}"
