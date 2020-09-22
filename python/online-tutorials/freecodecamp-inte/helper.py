#!/usr/bin/env python3
# Allows to use logging for modules without using "root"
import logging
logger = logging.getLogger(__name__)# creates a logger with a name of "helper"
logger.propagate = False # will prevent printing this logger message in file doing
# the import (main.py)
logger.info('hello from helper')