#!/usr/bin/env python3
# Logging
import logging
# look up python doc for logging — Logging facility for Python
# https://docs.python.org/3/library/logging.html
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(name)s -'+ 
    '%(levelname)s - %(message)s', datefmt='%m/%d/%Y %H:%M:%S')
import helper
# 5 Logging levels
logging.debug('This is a debug message')
logging.info('Info message')
logging.warning('Warning message') # only this and below this are printed by default
logging.error('Error message')
logging.critical('Critical message')