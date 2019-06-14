# get fqdn
import socket
#import netifaces as ni

#ni.ifaddresses('eth0')
#ip = ni.ifaddresses('eth0')[ni.AF_INET][0]['addr']
#print(f"IP={ip}")
print(socket.getfqdn())
