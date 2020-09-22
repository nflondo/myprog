#!/usr/bin/env python3
import logging
#from logging.handlers import RotatingFileHandler
from logging.handlers import TimedRotatingFileHandler
import time

logger2 = logging.getLogger(__name__)
logger2.setLevel(logging.INFO)

#roll over after 2KB, and keep backup logs app.log.1, app.log.2, etc.
#handler = RotatingFileHandler('app.log', maxBytes=2000, backupCount=5)
# m = minutes, s = seconds, d = day, midnight, w0, etc
handler = TimedRotatingFileHandler('timed_app.log', when='s', interval=5, backupCount=5)
logger2.addHandler(handler)

for _ in range(6): # _ we don't care
    logger2.info("Hello World !")
    time.sleep(5)

# look up python-json-logger