#!/bin/bash
cat original.txt | grep '^[0-9]' | sed s/[0-9][0-9][0-9]/-/ | cut -d- -f1 > ready-list.txt
