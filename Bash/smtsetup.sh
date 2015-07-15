#!/bin/bash
echo -e "Adding Repos..."
zypper ar http://151.155.193.250/repo/\$RCE/SLES11-SP3-Updates/sle-11-x86_64/ SLES11-SP3-Updates
if [ $? == 0 ]
then
	echo -e "SUCESS Adding SLES11-SP3-Updates"
fi
zypper ar http://151.155.193.250/repo/\$RCE/SLE11-SDK-SP3-Pool/sle-11-x86_64/ SLE11-SDK-SP3-Pool
if [ $? == 0 ]
then
	echo -e "SUCESS Adding SLE11-SDK-SP3-Pool"
fi
zypper ar http://151.155.193.250/repo/\$RCE/SLE11-SDK-SP3-Updates/sle-11-x86_64/ SLE11-SDK-SP3-Updates
if [ $? == 0 ]
then
	echo -e "SUCESS Adding SLE11-SDK-SP3-Updates"
fi
zypper ref


exit 0