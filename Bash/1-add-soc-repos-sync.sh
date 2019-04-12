#!/bin/bash
for REPO in SLES12-SP4-{Pool,Updates} SUSE-OpenStack-Cloud-9-{Pool,Updates}; do
  smt-repos $REPO sle-12-x86_64 -e
done
rc=$?
if [ $rc -eq 0 ];then
smt-mirror -L /var/log/smt/smt-mirror.log
else
echo "Errors adding repos, not synchronizing"
fi
