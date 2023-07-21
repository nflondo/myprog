#!/bin/bash
# Get me a list of charts that have been updated in the last 6 months
# and the number of updates each chart has had in the last 6 months

###############################################################################
# Functions
###############################################################################

###############################################################################
# Main line code
###############################################################################

IndexFile="/root/git-repos/forks/partner-charts/index.yaml"
Count=0
ResultsFile="/tmp/partner-charts-stats.txt"
# Get the list of charts that have been updated in the last 6 months
# and the number of updates each chart has had in the last 6 months
# The output is sorted by the number of updates
# The output is in the format: <number of updates> <chart name>
# The output is saved in the file: partner-charts-stats.txt
# The output is also displayed on the screen
echo "Getting the list of charts that have been updated in the specific date"
# Regular expression to extract dates from created line in index.yaml
# The format of the date is: created: "2019-01-01T00:00:00.000-00:00"

for date in `cat $IndexFile | grep -E "created:" | cut -d \" -f 2 | cut -b 1-10` ;do
   if [[ $date > "2023-02-01" ]]; then
        echo $date >> $ResultsFile
        Count=$((Count+1))
    fi
done

echo "Count=$Count" >> $ResultsFile
echo ""
echo "The output has been saved in the file: $ResultsFile"
echo ""
echo "Done."