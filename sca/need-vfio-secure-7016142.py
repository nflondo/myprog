 #!/usr/bin/python

# Title:       Guest OS Cannot Start When Attaching a VF with Secure Boot E
# Description: 
# Modified:    2015 Sep 03
#
##############################################################################
# Copyright (C) 2015
##############################################################################
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; version 2 of the License.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
#
#  Authors/Contributors:
#   Nefi Munoz
#
##############################################################################

##############################################################################
# Module Definition
##############################################################################

import os
import Core

##############################################################################
# Overriden (eventually or in part) from SDP::Core Module
##############################################################################

META_CLASS = "SLE"
META_CATEGORY = "Virtualization"
META_COMPONENT = "PCI"
PATTERN_ID = os.path.basename(__file__)
PRIMARY_LINK = "META_LINK_TID"
OVERALL = Core.TEMP
OVERALL_INFO = "NOT SET"
OTHER_LINKS = "META_LINK_TID=https://www.suse.com/support/kb/doc.php?id=7016142"

Core.init(META_CLASS, META_CATEGORY, META_COMPONENT, PATTERN_ID, PRIMARY_LINK, OVERALL, OVERALL_INFO, OTHER_LINKS)

##############################################################################
# Local Function Definitions
##############################################################################

def checkSomething():
	fileOpen = "filename.txt"
	section = "CommandToIdentifyFileSection"
	content = {}
	if Core.getSection(fileOpen, section, content):
		for line in content:
			if "something" in content[line]:
				return True
	return False

##############################################################################
# Main Program Execution
##############################################################################

if( checkSomething() ):
	Core.updateStatus(Core.CRIT, "A critical severity is set")
else:
	Core.updateStatus(Core.IGNORE, "Ignore this pattern, not applicable")

Core.printPatternResults()


