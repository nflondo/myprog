#!/bin/bash
vbmc stop compute01
sleep 10
vbmc stop controller01
sleep 10
vbmc stop controller02
sleep 10
vbmc stop controller03
sleep 20
vbmc delete compute01
vbmc delete controller01
vbmc delete controller02
vbmc delete controller03
ip link set cont01-bmc down
ip link set cont02-bmc down
ip link set cont03-bmc down
ip link set comp01-bmc down
sleep 5
ip addr del 192.168.199.11/24 dev cont01-bmc
ip addr del 192.168.199.12/24 dev cont02-bmc
ip addr del 192.168.199.13/24 dev cont03-bmc
ip addr del 192.168.199.21/24 dev comp01-bmc
ip link set dev cont01-bmc-nic down
ip link set dev cont02-bmc-nic down
ip link set dev cont03-bmc-nic down
ip link set dev comp01-bmc-nic down
ip link del dev cont01-bmc-nic type veth
ip link del dev cont02-bmc-nic type veth
ip link del dev cont03-bmc-nic type veth
ip link del dev comp01-bmc-nic type veth
sleep 10
vbmc list
