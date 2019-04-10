#!/bin/bash
sudo ip link add dev cont01-bmc-nic type veth peer name cont01-bmc
sudo ip link add dev cont02-bmc-nic type veth peer name cont02-bmc
sudo ip link add dev cont03-bmc-nic type veth peer name cont03-bmc
sudo ip link add dev comp01-bmc-nic type veth peer name comp01-bmc
sudo ip link set dev cont01-bmc-nic up
sudo ip link set dev cont02-bmc-nic up
sudo ip link set dev cont03-bmc-nic up
sudo ip link set dev comp01-bmc-nic up
sudo ip link set comp01-bmc-nic master virbr5
sudo ip link set cont01-bmc-nic master virbr5
sudo ip link set cont02-bmc-nic master virbr5
sudo ip link set cont03-bmc-nic master virbr5
sudo ip addr add 192.168.199.21/24 dev comp01-bmc
sudo ip addr add 192.168.199.11/24 dev cont01-bmc
sudo ip addr add 192.168.199.12/24 dev cont02-bmc
sudo ip addr add 192.168.199.13/24 dev cont03-bmc
sudo ip link set cont01-bmc up
sudo ip link set cont02-bmc up
sudo ip link set cont03-bmc up
sudo ip link set comp01-bmc up
sudo vbmc add compute01 --address 192.168.199.21 --port 623 --username admin --password password --libvirt-uri qemu:///system
sudo vbmc add controller01 --address 192.168.199.11 --port 623 --username admin --password password --libvirt-uri qemu:///system
sudo vbmc add controller02 --address 192.168.199.12 --port 623 --username admin --password password --libvirt-uri qemu:///system
sudo vbmc add controller03 --address 192.168.199.13 --port 623 --username admin --password password --libvirt-uri qemu:///system
sudo vbmc start controller01
sudo vbmc start controller02
sudo vbmc start controller03
sudo vbmc start compute01
