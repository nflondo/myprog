#!/bin/bash
zypper ar dir:///srv/www/suse-12.4/x86_64/repos/Cloud SLES12-SP4-Install-local
zypper ar dir:///srv/www/htdocs/repo/SUSE/Products/OpenStack-Cloud/9/x86_64/product SOC9-Pool
zypper ar dir:///srv/www/htdocs/repo/SUSE/Updates/OpenStack-Cloud/9/x86_64/update SOC9-Updates
